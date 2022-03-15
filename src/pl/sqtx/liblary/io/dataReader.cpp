//
// Created by Jakub Sitarczyk on 09/12/2021.
//

#include "dataReader.h"

using namespace std;

int dataReader::getInt() {
  int number = -1;
  cin >> number;
  if (cin.good()) {
    return number;
  } else {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartość nie jest liczbą");
  }
}

//  Get informations about new book and create it
Book dataReader::readAndCreateBook() {
  cslPrinter.printLine("Tytuł: ");
  string title;
  cin.ignore(1);
  getline(cin, title);
  cslPrinter.printLine("Autor: ");
  string author;
  getline(cin, author);
  cslPrinter.printLine("Wydawnictwo: ");
  string publisher;
  getline(cin, publisher);
  cslPrinter.printLine("ISBN: ");
  string isbn;
  cin >> isbn;
  cin.ignore();
  cslPrinter.printLine("Rok wydania: ");
  int releaseDate;
  cin >> releaseDate;
  cin.ignore();
  cslPrinter.printLine("Ilość stron: ");
  int pages;
  cin >> pages;
  cin.ignore();
//    If inavalid value
  if (!cin.good()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartość nie jest liczbą");
  }
  cin.clear();
  return Book(title, author, releaseDate, pages, publisher, isbn);
}

//  Get informations about new magazine and create it
Magazine dataReader::readAndCreateMagazine() {
  cslPrinter.printLine("Tytuł: ");
  string title;
  cin.ignore(1);
  getline(cin, title);
  cslPrinter.printLine("Dzien: ");
  int day;
  cin >> day;
  cin.ignore();
  cslPrinter.printLine("Miesiac: ");
  int month;
  cin >> month;
  cin.ignore();
  cslPrinter.printLine("Rok wydania: ");
  int releaseDate;
  cin >> releaseDate;
//    cin.ignore();
  cslPrinter.printLine("Jezyk: ");
  cin.ignore(1);
  string language;
  getline(cin, language);
  cslPrinter.printLine("Wydawnictwo: ");
  string publisher;
  getline(cin, publisher);
//    IF inavalid value
  if (!cin.good()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartość nie jest liczbą");
  }
  cin.clear();
  return Magazine(title, day, month, releaseDate, language, publisher);
}

//  User functions
//  Get informations about new user and create it
User dataReader::readAndCreateUser(){
  cslPrinter.printLine("Imię: ");
  cin.ignore(1);
  string firstName;
  cin >> firstName;
  cslPrinter.printLine("Nazwisko: ");
  cin.ignore(1);
  string lastName;
  cin >> lastName;
  cslPrinter.printLine("PESEL: ");
  cin.ignore(1);
  string pesel;
  cin >> pesel;

  if (!cin.good()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartość nie jest liczbą");
  }
  cin.clear();
  return User(firstName, lastName, pesel);
};
