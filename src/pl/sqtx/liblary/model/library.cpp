//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/publicationType_h.h"

class Library{
private:
  static const int maxPublications = 1000;
  Book books[maxPublications];  //Books array and size
  Magazine magazines[maxPublications];  //Books array and size
  int booksNumber = 0;
  int magazinesNumber = 0;

public:
//  Add new book to lab
  void addBook(Book book){
    if(booksNumber < maxPublications){
      books[booksNumber] = book;
      booksNumber++;
    }else{
      cout << "Maksymalna liczba książek została osiągnięta" << endl;
    }
  }
  //  Add new magazine to lab
  void addMagazine(Magazine magazine){
    if(magazinesNumber < maxPublications){
      magazines[magazinesNumber] = magazine;
      magazinesNumber++;
    }else{
      cout << "Maksymalna liczba gazet została osiągnięta" << endl;
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
  //  Print informations about all magazines in lab
  void printMagazines(){
    if(magazinesNumber == 0){
      cout << "Brak gazet w bibliotece" << endl;
    }
    for(int i = 0; i < magazinesNumber; i++){
      magazines[i].printInfo();
    }
  }
};
