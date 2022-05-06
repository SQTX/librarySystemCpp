//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#include "dataReader.h"

using namespace std;

string dataReader::toLowerCase(string txt) {
  transform(txt.begin(), txt.end(), txt.begin(), ::tolower); //Convert string to lower case
  return txt;
}

int dataReader::getInt() {
  int number = -1;
  cin >> number;
  if (cin.good()) {
    cin.clear();
    return number;
  } else {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartosc nie jest liczba");
  }
}
char dataReader::getChar() {
  char ch = ' ';
  cin >> ch;
  if (cin.good()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ch;
  } else {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartosc nie jest pojedynczym znakiem");
  }
}
string dataReader::getTextLine() {
  string txt = "";
  getline(cin, txt);
  if (cin.good()) {
    cin.clear();
    return txt;
  } else {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartosc jest bledna");
  }
}

//For publications ******************************************************
Book dataReader::readAndCreateBook() {
  consolePrinter::printLine("Tytul: ");
  string title;
  cin.ignore(1);
  getline(cin, title);
  consolePrinter::printLine("Autor: ");
  string author;
  getline(cin, author);
  consolePrinter::printLine("Wydawnictwo: ");
  string publisher;
  getline(cin, publisher);
  consolePrinter::printLine("ISBN: ");
  string isbn;
  cin >> isbn;
  cin.ignore();
  consolePrinter::printLine("Rok wydania: ");
  int releaseDate;
  releaseDate = getInt();
  consolePrinter::printLine("Ilosc stron: ");
  int pages;
  pages = getInt();
  return Book(title, author, releaseDate, pages, publisher, isbn);
}
Magazine dataReader::readAndCreateMagazine() {
  consolePrinter::printLine("Tytul: ");
  string title;
  cin.ignore(1);
  getline(cin, title);
  consolePrinter::printLine("Dzien: ");
  int day;
  day = getInt();
  consolePrinter::printLine("Miesiac: ");
  int month;
  month = getInt();
  consolePrinter::printLine("Rok wydania: ");
  int releaseDate;
  releaseDate = getInt();
  consolePrinter::printLine("Jezyk: ");
  cin.ignore(1);
  string language;
  getline(cin, language);
  consolePrinter::printLine("Wydawnictwo: ");
  string publisher;
  getline(cin, publisher);
  cin.clear();
  return Magazine(title, day, month, releaseDate, language, publisher);
}

//For person ******************************************************
Person dataReader::readAndCreatePerson(){
  consolePrinter::printLine("Imie: ");
  cin.ignore(1);
  string firstName;
  cin >> firstName;
  consolePrinter::printLine("Nazwisko: ");
  cin.ignore(1);
  string lastName;
  cin >> lastName;
  consolePrinter::printLine("PESEL: ");
  cin.ignore(1);
  string pesel;
  cin >> pesel;

  if(pesel.size()>11){
    wrongDataException err;
    consolePrinter::printLine("Pesel musi skladac sie z 11 cyfr.");
    throw err;
  }

  if (!cin.good()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw invalid_argument("Podana wartosc nie jest liczba");
  }
  cin.clear();
  return Person(firstName, lastName, pesel);
}
User dataReader::readAndCreateUser() {
  Person newPerson = readAndCreatePerson();
  return User(newPerson.getFirstName(), newPerson.getLastName(), newPerson.getPesel());
}
