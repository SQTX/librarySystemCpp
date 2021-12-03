//
// Created by Jakub Sitarczyk on 02/12/2021.
//
#include <iostream>
#include <string>

using namespace std;
class Book{ //Book class®
  public:
    string title;
    string author;
    int releaseDate;
    int pages;
    string publisher;
    string isbn;
    Book(string title, string author, int releaseDate, int pages, string publisher) { //Constructor Book
      this->title = title;
      this->author = author;
      this->releaseDate = releaseDate;
      this->pages = pages;
      this->publisher = publisher;
    }
    Book(string title, string author, int releaseDate, int pages, string publisher, string isbn) { //Constructor Book
      this->title = title;
      this->author = author;
      this->releaseDate = releaseDate;
      this->pages = pages;
      this->publisher = publisher;
      this->isbn = isbn;
    }
  void printInfo(){ //Printer
    string info = title + "; " + author + "; " + to_string(releaseDate) + "; " + to_string(pages) + "; " + publisher + "; " + isbn;
    cout << info << endl;
  }
};

