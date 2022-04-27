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
  cslPrinter.printLine("Tytul: ");
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
  releaseDate = getInt();
  cslPrinter.printLine("Ilosc stron: ");
  int pages;
  pages = getInt();
  return Book(title, author, releaseDate, pages, publisher, isbn);
}
Magazine dataReader::readAndCreateMagazine() {
  cslPrinter.printLine("Tytul: ");
  string title;
  cin.ignore(1);
  getline(cin, title);
  cslPrinter.printLine("Dzien: ");
  int day;
  day = getInt();
  cslPrinter.printLine("Miesiac: ");
  int month;
  month = getInt();
  cslPrinter.printLine("Rok wydania: ");
  int releaseDate;
  releaseDate = getInt();
  cslPrinter.printLine("Jezyk: ");
  cin.ignore(1);
  string language;
  getline(cin, language);
  cslPrinter.printLine("Wydawnictwo: ");
  string publisher;
  getline(cin, publisher);
  cin.clear();
  return Magazine(title, day, month, releaseDate, language, publisher);
}

//For person ******************************************************
Person dataReader::readAndCreatePerson(){
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

  if(pesel.size()>11){
    wrongDataException err;
    cslPrinter.printLine("Pesel musi skladac sie z 11 cyfr.");
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
