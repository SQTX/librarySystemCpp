//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#include <iostream>
#include "../model/book.cpp"

class DataReader {
public:
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
};