//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/publicationType_h.h"

class DataReader {
public:
  //  Get int number
  int getInt(){
    int number;
    cin >> number;
    return number;
  }
//  Get informations about new book
  Book readAndCreateBook() {
    cout << "Tytuł: ";
    string title;
    cin >> title;
    cout << "Autor: ";
    string author;
    cin >> author;
    cout << "Wydawnictwo: ";
    string publisher;
    cin >> publisher;
    cout << "ISBN: ";
    string isbn;
    cin >> isbn;
    cout << "Rok wydania: ";
    int releaseDate;
    cin >> releaseDate;
    cout << "Ilość stron: ";
    int pages;
    cin >> pages;

    return Book(title, author, releaseDate, pages, publisher, isbn);
  }
  //  Get informations about new book
  Magazine readAndCreateMagazine() {
    cout << "Tytuł: ";
    string title;
    cin >> title;
    cout << "Dzien: ";
    int day;
    cin >> day;
    cout << "Miesiac: ";
    int month;
    cin >> month;
    cout << "Rok wydania: ";
    int releaseDate;
    cin >> releaseDate;
    cout << "Jezyk: ";
    string language;
    cin >> language;
    cout << "Wydawnictwo: ";
    string publisher;
    cin >> publisher;

    return Magazine(title, day, month, releaseDate, language, publisher);
  }
};