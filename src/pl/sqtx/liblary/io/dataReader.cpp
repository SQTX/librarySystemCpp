//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

class DataReader {
  ConsolePrinter cslPrinter;
public:
  //  Get int number
  int getInt(){
    int number = -1;
    cin >> number;
      if(cin.good()){
        return number;
      }else{
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw invalid_argument("Podana wartość nie jest liczba");
      }
  }
//  Get informations about new book
  Book readAndCreateBook() {
    cslPrinter.printLine("Tytuł: ");
    string title;
    cin >> title;
    cslPrinter.printLine("Autor: ");
    string author;
    cin >> author;
    cslPrinter.printLine("Wydawnictwo: ");
    string publisher;
    cin >> publisher;
    cslPrinter.printLine("ISBN: ");
    string isbn;
    cin >> isbn;
    cslPrinter.printLine("Rok wydania: ");
    int releaseDate;
    cin >> releaseDate;
    cslPrinter.printLine("Ilość stron: ");
    int pages;
    cin >> pages;

    return Book(title, author, releaseDate, pages, publisher, isbn);
  }
  //  Get informations about new book
  Magazine readAndCreateMagazine() {
    cslPrinter.printLine("Tytuł: ");
    string title;
    cin >> title;
    cslPrinter.printLine("Dzien: ");
    int day;
    cin >> day;
    cslPrinter.printLine("Miesiac: ");
    int month;
    cin >> month;
    cslPrinter.printLine("Rok wydania: ");
    int releaseDate;
    cin >> releaseDate;
    cslPrinter.printLine("Jezyk: ");
    string language;
    cin >> language;
    cslPrinter.printLine("Wydawnictwo: ");
    string publisher;
    cin >> publisher;

    return Magazine(title, day, month, releaseDate, language, publisher);
  }
};