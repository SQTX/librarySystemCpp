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
#include "iostream"
int borrowEngine::findUser(libraryUser *libraryUser) {
//  Create wanted user
  cslPrinter.printLine("Podaj dane uzytkownika");
  User wanted = dataReader.readAndCreateUser();

//  Searching
  vector<User>::iterator it_wantedUser = libraryUser->getIteratorUsers();

  cout << wanted.getFirstName() << endl;
  cout << wanted.getLastName() << endl;
  cout << wanted.getPesel() << endl;
  for (int i = 0; i < libraryUser->getUsers().size(); i++) {
    if (wanted.getFirstName() == (it_wantedUser + i)->getFirstName() &&
      wanted.getLastName() == (it_wantedUser + i)->getPesel() &&
      wanted.getPesel() == (it_wantedUser + i)->getPesel()) return i;
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
    case 'k': case 'K': {
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
          if(searchingTitle == title && searchingAuthor == author) return i;
        };
      }
      return -1; //If not exist
      break;
    } case 'g': case 'G': {
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
          if(searchingTitle == title && searchingDay == day &&
            searchingMonth == month && searchingYear == year) return i;
        };
      }
      return -1; //If not exist
      break;
    } default:
      cslPrinter.printLine("Podany przez ciebie typ publikacji nie istnieje.");
      return -1;
      break;
  };
};

int borrowEngine::findBorrowedPublication(userLendHistory *history, string time) {
  vector<BorrPublicationsPtr>::iterator it_userLendHistory = history->getIteratorHistoryOfUser();

  //  Choose wanted type and get data
  cslPrinter.printLine("Wybierz typ publikacji:\n[K] - Ksiazka\n[G] - Gazeta");
  char choice = tolower(dataReader.getChar());

  switch (choice) {
    case 'k': case 'K': {
      //TODO: Potęcjalny search engine to będzie
//      Get data
      cslPrinter.printLine("Tytul ksiazki:");
      string searchingTitle = dataReader.getTextLine();
      cslPrinter.printLine("Autor ksiazki:");
      string searchingAuthor = dataReader.getTextLine();
//      Searching
      for (int i = 0; i < history->getHistoryOfUser().size(); i++) {
        BorrPublicationsPtr ptr = *(it_userLendHistory + i);
        if (dynamic_cast<Book *>(ptr->getObjIterator()->get())) { //Checking if the Publication is a Book
          string title = ptr->getObjIterator()->get()->getTitle();
          string author = dynamic_cast<Book *>(ptr->getObjIterator()->get())->getAuthor(); //Potencjalnie dobrze
          if(searchingTitle == title && searchingAuthor == author){
            ptr->getObjIterator()->get()->setNumberOf((ptr->getObjIterator()->get()->getNumberOf()) + 1);
            if(ptr.get()->returnPublication(time)) return 1;
          }
        };
      }
      return 0; //If not find
      break;
    } case 'g': case 'G': {
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
      for (int i = 0; i < history->getHistoryOfUser().size(); i++) {
        BorrPublicationsPtr ptr = *(it_userLendHistory + i);
        if (dynamic_cast<Magazine *>(ptr->getObjIterator()->get())) { //Checking if the Publication is a Book
          string title = ptr->getObjIterator()->get()->getTitle();
          int day = dynamic_cast<Magazine *>(ptr->getObjIterator()->get())->getDay(); //Potencjalnie dobrze
          int month = dynamic_cast<Magazine *>(ptr->getObjIterator()->get())->getMonth(); //Potencjalnie dobrze
          int year = ptr->getObjIterator()->get()->getReleaseDate(); //Potencjalnie dobrze
          if(searchingTitle == title && searchingDay == day &&
             searchingMonth == month && searchingYear == year){
            ptr->getObjIterator()->get()->setNumberOf((ptr->getObjIterator()->get()->getNumberOf()) + 1);
            if(ptr.get()->returnPublication(time)) return 1;
          }
        };
      }
      return -1; //If not exist
      break;
    } default:
      cslPrinter.printLine("Podany przez ciebie typ publikacji nie istnieje.");
      return -1;
      break;
  };
};

//#include <iostream>
//Lend ****************************************************************************************************************
void borrowEngine::borrowPublication(library *library, libraryUser *libraryUser) {
//  Get actual time
  string time = getTimeAndDate();

//  Search user
  const int indexOfUser = findUser(libraryUser);
  vector<User>::iterator it_user = libraryUser->getIteratorUsers();
//  Search Publication
  const int indexOfPublication = findPublication(library);
  vector<PublicationPtr>::iterator it_publications = library->getIteratorPublications();

//  Loan machine
  BorrowedPublications newBorrowPub(*(it_publications + indexOfPublication), time, (it_publications + indexOfPublication));
  (it_user + indexOfUser)->lendPublication(newBorrowPub);
//  Change number of publication
  (it_publications + indexOfPublication)->get()->setNumberOf((it_publications + indexOfPublication)->get()->getNumberOf() - 1);

//  Message
  cslPrinter.printLine("Wybrana publikacja zostala wypozyczona");
};

//RETURN **************************************************************************************************************
void borrowEngine::returnPublication(library *library, libraryUser *libraryUser) {
//  Get actual time
  string time = getTimeAndDate();

//  Search user
  const int indexOfUser = findUser(libraryUser);
  vector<User>::iterator it_user = libraryUser->getIteratorUsers();
//  Get user history
  userLendHistory userHistory = (it_user + indexOfUser)->getUserHistory();
//  Search Borrowed Publication
  const int returnOkey = findBorrowedPublication(&userHistory, time);
//  Change statistic
  (it_user + indexOfUser)->returnPublication();

//  Message
  if(returnOkey){
    cslPrinter.printLine("Wybrana publikacja zostala zwrocona");
  }
}

void borrowEngine::printUserHistory(libraryUser *libraryUser){
  const int indexOfUser = findUser(libraryUser);
  vector<User>::iterator it_user = libraryUser->getIteratorUsers();
  cslPrinter.printUsersHistory((it_user + indexOfUser));
}
