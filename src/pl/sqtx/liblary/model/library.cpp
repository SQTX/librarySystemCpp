//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#ifndef MY_HEADER_H
#define MY_HEADER_H //Same in dataReader.cpp
#include <iostream>
#include "../model/book.cpp"
#endif MY_HEADER_H

class Library{
private:
  static const int maxBooks = 1000;
  Book books[maxBooks];  //Books array and size
  int booksNumber = 0;

public:
//  Add new book to lab
  void addBook(Book book){
    if(booksNumber < maxBooks){
      books[booksNumber] = book;
      booksNumber++;
    }else{
      cout << "Maksymalna liczba książek została osiągnięta" << endl;
    }
  }
//  Print informations about all books in lab
  void printBooks(){
    if(booksNumber == 0){
      cout << "Brak ksiazek w bibliotece" << endl;
    }
    for(int i = 0; i < booksNumber; i++){
      books[i].printInfo();
    }
  }
};
