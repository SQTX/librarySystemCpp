//
// Created by Jakub Sitarczyk on 09/12/2021.
//
/*Headers*/
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

class DataReader {
  ConsolePrinter cslPrinter;
public:
  //  Get int-type number from user
  int getInt(){
    int number = -1;
    cin >> number;
      if(cin.good()){
        return number;
      }else{
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw invalid_argument("Podana wartość nie jest liczbą");
      }
  }

//  Get informations about new book and create it
  Book readAndCreateBook() {
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
    if(!cin.good()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw invalid_argument("Podana wartość nie jest liczbą");
    }
    cin.clear();
    return Book(title, author, releaseDate, pages, publisher, isbn);
  }

  //  Get informations about new magazine and create it
  Magazine readAndCreateMagazine() {
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
    if(!cin.good()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw invalid_argument("Podana wartość nie jest liczbą");
    }
    cin.clear();
    return Magazine(title, day, month, releaseDate, language, publisher);
  }
};