//
// Created by Jakub Sitarczyk on 03/01/2022.
//
#include "consolePrinter.h"

using namespace std;

void consolePrinter::printLine(string txt) {
  cout << txt << endl;
}

void consolePrinter::printBooks(vector<PublicationPtr> &publications) {
  int countBooks = 0;
  vector<PublicationPtr> sortedPublications;
  for (int i = 0; i < publications.size(); i++) {
    PublicationPtr ptr = publications[i];
    if (dynamic_cast<Book *>(ptr.get())) { //Checking if the Publication is a Book
      sortedPublications.push_back(ptr);
      countBooks++;
    }
  }
//    Sort
  sort.getSort(sortedPublications);
//    Print
  for (auto &publication: sortedPublications)
    cout << publication->toString() << endl;

  if (countBooks == 0) {
    printLine("Brak ksiazek w bibliotece");
  }
}

void consolePrinter::printMagazines(vector<PublicationPtr> &publications) {
  vector<PublicationPtr> sortedPublications;
  int countMagazine = 0;
  for (int i = 0; i < publications.size(); i++) {
    PublicationPtr ptr = publications[i];
    if (dynamic_cast<Magazine *>(ptr.get())) { //Checking if the Publication is a Magazine
      sortedPublications.push_back(ptr);
      countMagazine++;
    }
  }
//    Sort
  sort.getSort(sortedPublications);
//    Print
  for (auto &publication: sortedPublications)
    cout << publication->toString() << endl;
  if (countMagazine == 0) {
    printLine("Brak gazet w bibliotece");
  }
}

void consolePrinter::printUsers(vector<User> &users) {
  int countBooks = 0;
  for (int i = 0; i < users.size(); i++) {
    printLine(users[i].toString());
    countBooks++;
  }
  if (countBooks == 0) {
    printLine("Brak uzytkownikow w bazie.");
  }
}

void consolePrinter::printUserHistory(vector<User>::iterator user){
  string statistic = "Liczba wszystkich wypozyczen: " + to_string(user->getAllLoanNumb());
  statistic.append("\nLiczba aktualnie posiadanych: " + to_string(user->getCurrentlyLoan()));
  statistic.append("\nLiczba zwrotow: " + to_string(user->getReturnedNumb()));
  cout << statistic << endl;
  cout << "------------------------------------------" << endl;

  if(user->getAllLoanNumb() != 0){
    vector<HistoryElement> userHistory = user->getUserHistory();
    for(auto &historyElement : userHistory){
      if(historyElement.getElemReturnDate() == "0"){
        cout << historyElement.getElemTitle() + "; " + historyElement.getElemSecondPart() + "; " + historyElement.getElemLoanDate() << endl;
      }
    }
    for(auto &historyElement : userHistory){
      if(historyElement.getElemReturnDate() != "0"){
        cout << historyElement.getElemTitle() + "; " + historyElement.getElemSecondPart() + "; " +
                historyElement.getElemLoanDate() + "; " + historyElement.getElemReturnDate() << endl;
      }
    }
  } else {
    cout << "Historia uzytkownika jest pusta" << endl;
  }


}