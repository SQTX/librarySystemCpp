//
// Created by Jakub Sitarczyk on 25/03/2022.
//
#include "borrowEngine.h"
#include "../include/exception_h.h"
#include "../io/time/clockSystem.h"

using namespace std;

//Create string with time and date info
string getTimeAndDate() {
  string timeNdate;
  clockSystem clock;
  timeNdate.append(clock.getDate());
  timeNdate.append("|");
  timeNdate.append(clock.getTime());
  return timeNdate;
}

int borrowEngine::findUser(libraryUser *libraryUser) {
  UserNotExistException err;
//  --- Create wanted user ---
  cslPrinter.printLine("Podaj dane uzytkownika");
  User wanted = dataReader.readAndCreateUser();
//  --- Searching ---
  auto it_users = libraryUser->getIteratorUsers();
  for (int i = 0; i < libraryUser->getUsersVector().size(); i++) {
    if (dataReader.toLowerCase(wanted.getFirstName()) == dataReader.toLowerCase((it_users + i)->getFirstName()) &&
        dataReader.toLowerCase(wanted.getLastName()) == dataReader.toLowerCase((it_users + i)->getLastName()) &&
        wanted.getPesel() == (it_users + i)->getPesel())
      return i;
  }
  throw err;
}
int borrowEngine::findPublication(library *library, bool loanStatus, string userPesel) {
  PublicationNotExistException err;
  PublicationAvailabilityException availableErr;
  bool availablePublicationFlag = false;
  int flagInt = 0;
  auto it_publications = library->getIteratorPublications();

  do {
    //  Choose wanted type and get data
    consolePrinter::printLine("Wybierz typ publikacji:\n[K] - Ksiazka\n[G] - Gazeta");
    char choice = tolower(dataReader.getChar());

    switch (choice) {
      case 'k':
      case 'K': {
//      Get data
        consolePrinter::printLine("Tytul ksiazki:");
        string searchingTitle = dataReader.getTextLine();
        consolePrinter::printLine("Autor ksiazki:");
        string searchingAuthor = dataReader.getTextLine();
//      Searching
        for (int i = 0; i < library->getPublications().size(); i++) {
          PublicationPtr ptr = *(it_publications + i);
          //Checking if the Publication is a Book
          if (dynamic_cast<Book *>(ptr.get())) {
            string title = ptr.get()->getTitle();
            string author = dynamic_cast<Book *>(ptr.get())->getAuthor(); //Potencjalnie dobrze
            bool loan = ptr.get()->getIsLoan();
            if (dataReader.toLowerCase(searchingTitle) == dataReader.toLowerCase(title) && dataReader.toLowerCase(searchingAuthor) == dataReader.toLowerCase(author)) {
              if (loan == loanStatus && loanStatus == false) {
                return i;
              } else if (loan == loanStatus && loanStatus == true) {
                string pesel = ptr->getCurrentlyOwns();
                if (pesel == userPesel) return i;
              } else {
                availablePublicationFlag = true;
              }
            }
          }
        }
        if (availablePublicationFlag) throw availableErr;
        throw err;
      }
      case 'g':
      case 'G': {
//      Get data
        consolePrinter::printLine("Tytul gazety:");
        string searchingTitle = dataReader.getTextLine();
        consolePrinter::printLine("Dzien publikacji:");
        int searchingDay = dataReader.getInt();
        consolePrinter::printLine("Miesiac publikacji:");
        int searchingMonth = dataReader.getInt();
        consolePrinter::printLine("Rok publikacji:");
        int searchingYear = dataReader.getInt();
//      Searching
        for (int i = 0; i < library->getPublications().size(); i++) {
          PublicationPtr ptr = *(it_publications + i);
//        --- Checking if the Publication is a Book ---
          if (dynamic_cast<Magazine *>(ptr.get())) {
            string title = ptr.get()->getTitle();
            int day = dynamic_cast<Magazine *>(ptr.get())->getDay(); //Potencjalnie dobrze
            int month = dynamic_cast<Magazine *>(ptr.get())->getMonth(); //Potencjalnie dobrze
            int year = ptr->getReleaseDate(); //Potencjalnie dobrze
            bool loan = ptr.get()->getIsLoan();
            if (dataReader.toLowerCase(searchingTitle) == dataReader.toLowerCase(title) && searchingDay == day &&
                searchingMonth == month && searchingYear == year) {
              if (loan == loanStatus && loanStatus == false) {
                return i;
              } else if (loan == loanStatus && loanStatus == true) {
                string pesel = ptr->getCurrentlyOwns();
                if (pesel == userPesel) return i;
              } else {
                availablePublicationFlag = true;
              }
            }
          }
        }
        if (availablePublicationFlag) throw availableErr;
        throw err;
      }
      default:
        cslPrinter.printLine("Podany przez ciebie typ publikacji nie istnieje.");
        flagInt = -1;
        cin.clear();
        break;
    };
  } while (flagInt < 0);
  return -1;
};

//Lend ****************************************************************************************************************
void borrowEngine::borrowPublication(library *library, libraryUser *libraryUser) {
  string time = getTimeAndDate(); //Create actual date and time

  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  auto it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base

  const int indexOfPublication = findPublication(library, false, "0");  //Search index of publications
  auto it_publications = library->getIteratorPublications();  //Get iterator form data-base

  //    --- Create history element ---
//  Checking type of publication and assigns it secondPart value
  string secondPart;
  if (dynamic_cast<Book *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Book *>((it_publications + indexOfPublication)->get())->getAuthor();
  } else if (dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())->createFullDateOfPublication();
  } else secondPart = "Error second part borrowEngine.cpp";

  HistoryElement historyElement((it_publications + indexOfPublication)->get()->getTitle(), secondPart,
                                time, "0"); //Create history element

  (it_user + indexOfUser)->lendPublication(*(it_publications + indexOfPublication),
                                           historyElement);  //Send data to User
//  --- Changing in Publication object ---
  (it_publications + indexOfPublication)->get()->setCurrentlyOwns((it_user + indexOfUser)->getPesel());
  (it_publications + indexOfPublication)->get()->setIsLoan(true);

  consolePrinter::printLine("Wybrana publikacja zostala wypozyczona"); //Completed message
};

//RETURN **************************************************************************************************************
void borrowEngine::returnPublication(library *library, libraryUser *libraryUser) {
  string time = getTimeAndDate(); //Create actual date and time

  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  auto it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base
  string userPesel = (it_user + indexOfUser)->getPesel();

  const int indexOfPublication = findPublication(library, true, userPesel);  //Search index of publications
  auto it_publications = library->getIteratorPublications();  //Get iterator form data-base

  string title, secondPart;
  title = (it_publications + indexOfPublication)->get()->getTitle();

//  Checking type of publication and assigns it secondPart value
  if (dynamic_cast<Book *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Book *>((it_publications + indexOfPublication)->get())->getAuthor();
  } else if (dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())->createFullDateOfPublication();
  } else secondPart = "Error";

  (it_user + indexOfUser)->returnPublication(title, secondPart, time);

  //  Changing in Publication object
  (it_publications + indexOfPublication)->get()->setCurrentlyOwns("0");
  (it_publications + indexOfPublication)->get()->setIsLoan(false);

  consolePrinter::printLine("Wybrana publikacja zostala zwrocona");
}

//History of user
void borrowEngine::printUserHistory(libraryUser *libraryUser) {
  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  auto it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base

  cslPrinter.printUserHistory((it_user + indexOfUser));
}
