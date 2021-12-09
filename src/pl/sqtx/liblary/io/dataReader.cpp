//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#ifndef MY_HEADER_H
#define MY_HEADER_H //Same in library.cpp
#include <iostream>
#include "../model/book.cpp"
#endif MY_HEADER_H

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
};