//
// Created by Jakub Sitarczyk on 25/03/2022.
//
#include "borrowEngine.h"
#include "../io/time/clockSystem.h"

using namespace std;

//Create string with time and date info
string getTimeAndDate() {
  string timeNdate;
  clockSystem clock;
  timeNdate.append(clock.getDate());
  timeNdate.append(" | ");
  timeNdate.append(clock.getTime());
  return timeNdate;
}

int borrowEngine::findUser(libraryUser *libraryUser) {
//  Create wanted user
  cslPrinter.printLine("Podaj dane uzytkownika");
  User wanted = dataReader.readAndCreateUser();

//  Searching
  vector<User>::iterator it_users = libraryUser->getIteratorUsers();

  for (int i = 0; i < libraryUser->getUsersVector().size(); i++) {
    if (wanted.getPerson().getFirstName() == (it_users + i)->getPerson().getFirstName() &&
        wanted.getPerson().getLastName() == (it_users + i)->getPerson().getLastName() &&
        wanted.getPerson().getPesel() == (it_users + i)->getPerson().getPesel())
      return i;
  }
  return -1;
  //TODO błąd: podany użytkownik nie istnieje w bazie danych
}

//------------------------------------------------------------------------------------------------------------------
int borrowEngine::findPublication(library *library) {
  vector<PublicationPtr>::iterator it_publications = library->getIteratorPublications();

  //  Choose wanted type and get data
  cslPrinter.printLine("Wybierz typ publikacji:\n[K] - Ksiazka\n[G] - Gazeta");
  char choice = tolower(dataReader.getChar());

  switch (choice) {
    case 'k':
    case 'K': {
      //TODO: Potęcjalny search engine to będzie
//      Get data
      cslPrinter.printLine("Tytul ksiazki:");
      string searchingTitle = dataReader.getTextLine();
      cslPrinter.printLine("Autor ksiazki:");
      string searchingAuthor = dataReader.getTextLine();
//      Searching
      for (int i = 0; i < library->getPublications().size(); i++) {
        PublicationPtr ptr = *(it_publications + i);
        //Checking if the Publication is a Book
        if (dynamic_cast<Book *>(ptr.get())) {
          string title = ptr.get()->getTitle();
          string author = dynamic_cast<Book *>(ptr.get())->getAuthor(); //Potencjalnie dobrze
          if (searchingTitle == title && searchingAuthor == author) return i;
        };
      }
      return -1; //If not exist
      break;
    }
    case 'g':
    case 'G': {
//      Get data
      cslPrinter.printLine("Tytul gazety:");
      string searchingTitle = dataReader.getTextLine();
      cslPrinter.printLine("Dzien publikacji:");
      int searchingDay = dataReader.getInt();
      cslPrinter.printLine("Miesiac publikacji:");
      int searchingMonth = dataReader.getInt();
      cslPrinter.printLine("Rok publikacji:");
      int searchingYear = dataReader.getInt();
//      Searching
      for (int i = 0; i < library->getPublications().size(); i++) {
        PublicationPtr ptr = *(it_publications + i);
        if (dynamic_cast<Magazine *>(ptr.get())) { //Checking if the Publication is a Book
          string title = ptr.get()->getTitle();
          int day = dynamic_cast<Magazine *>(ptr.get())->getDay(); //Potencjalnie dobrze
          int month = dynamic_cast<Magazine *>(ptr.get())->getMonth(); //Potencjalnie dobrze
          int year = ptr->getReleaseDate(); //Potencjalnie dobrze
          if (searchingTitle == title && searchingDay == day &&
              searchingMonth == month && searchingYear == year) {

            return i;
          }
        };
      }
      return -1; //If not exist
      break;
    }
    default:
      cslPrinter.printLine("Podany przez ciebie typ publikacji nie istnieje.");
      return -1;
      break;
  };
};

//Lend ****************************************************************************************************************
void borrowEngine::borrowPublication(library *library, libraryUser *libraryUser) {
  string time = getTimeAndDate(); //Create actual date and time

  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  vector<User>::iterator it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base

  const int indexOfPublication = findPublication(library);  //Search index of publications
  vector<PublicationPtr>::iterator it_publications = library->getIteratorPublications();  //Get iterator form data-base

//  --- Create history element ---
  string secondPart;
//  Checking type of publication and assigns it secondPart value
  if (dynamic_cast<Book *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Book *>((it_publications + indexOfPublication)->get())->getAuthor();
  } else if (dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())->createSecondPart();
  } else secondPart = "Error";

  HistoryElement historyElement((it_publications + indexOfPublication)->get()->getTitle(), secondPart,
                                time); //Create history element

  (it_user + indexOfUser)->lendPublication(*(it_publications + indexOfPublication),
                                           historyElement);  //Send data to User
//  Changing in Publication object
  (it_publications + indexOfPublication)->get()->setCurrentlyOwns((it_user + indexOfUser)->getPerson().getPesel());
  (it_publications + indexOfPublication)->get()->setIsLoan(true);

  cslPrinter.printLine("Wybrana publikacja zostala wypozyczona"); //Completed message
};

//RETURN **************************************************************************************************************
void borrowEngine::returnPublication(library *library, libraryUser *libraryUser) {
  string time = getTimeAndDate(); //Create actual date and time

  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  vector<User>::iterator it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base

  const int indexOfPublication = findPublication(library);  //Search index of publications
  vector<PublicationPtr>::iterator it_publications = library->getIteratorPublications();  //Get iterator form data-base

  string title, secondPart;
  title = (it_publications + indexOfPublication)->get()->getTitle();

//  Checking type of publication and assigns it secondPart value
  if (dynamic_cast<Book *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Book *>((it_publications + indexOfPublication)->get())->getAuthor();
  } else if (dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())) {
    secondPart = dynamic_cast<Magazine *>((it_publications + indexOfPublication)->get())->createSecondPart();
  } else secondPart = "Error";

  (it_user + indexOfUser)->returnPublication(title, secondPart, time);

  //  Changing in Publication object
  (it_publications + indexOfPublication)->get()->setCurrentlyOwns("0");
  (it_publications + indexOfPublication)->get()->setIsLoan(false);

  cslPrinter.printLine("Wybrana publikacja zostala zwrocona");
}

void borrowEngine::printUserHistory(libraryUser *libraryUser) {
  const int indexOfUser = findUser(libraryUser);  //Search index of wanted user
  vector<User>::iterator it_user = libraryUser->getIteratorUsers(); //Get iterator form data-base

  cslPrinter.printUserHistory((it_user + indexOfUser));
}
