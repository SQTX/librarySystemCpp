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
  vector<User>::iterator it_wantedUser = libraryUser->getIteratorUsers();

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
        if (dynamic_cast<Book *>(ptr.get())) { //Checking if the Publication is a Book
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

#include <iostream>
//*******************************************************************************************************************
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
  BorrowedPublications newBorrowPub(*(it_publications + indexOfPublication), time);
  it_user->newBorrow(newBorrowPub);
//  Change number of publication
  (it_publications + indexOfPublication)->get()->setNumberOf((it_publications + indexOfPublication)->get()->getNumberOf() - 1);
//  Assign a loan to the user




//  Message
  cslPrinter.printLine("Wybrana publikacja zostala wypozyczona");
};
//*******************************************************************************************************************
void borrowEngine::returnPublication(library *library, libraryUser *libraryUser) {
  cslPrinter.printLine("Zwrot!");
}
