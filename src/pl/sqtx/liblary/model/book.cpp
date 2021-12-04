//
// Created by Jakub Sitarczyk on 02/12/2021.
//
#include <iostream>
#include <string>

using namespace std;
class Book{ //Book class
private:
    string title;
    string author;
    int releaseDate;
    int pages;
    string publisher;
    string isbn;
public:
//    Constructors  *****************************************************************************************
    Book(string title, string author, int releaseDate, int pages, string publisher) {
      this->title = title;
      this->author = author;
      this->releaseDate = releaseDate;
      this->pages = pages;
      this->publisher = publisher;
    }
    Book(string title, string author, int releaseDate, int pages, string publisher, string isbn) {
      this->title = title;
      this->author = author;
      this->releaseDate = releaseDate;
      this->pages = pages;
      this->publisher = publisher;
      this->isbn = isbn;
    }
//  Getter and Setter *****************************************************************************************
    const string &getTitle() const {
      return title;
    }
    void setTitle(const string &title) {
      Book::title = title;
    }
    const string &getAuthor() const {
      return author;
    }
    void setAuthor(const string &author) {
      Book::author = author;
    }
    int getReleaseDate() const {
      return releaseDate;
    }
    void setReleaseDate(int releaseDate) {
      Book::releaseDate = releaseDate;
    }
    int getPages() const {
      return pages;
    }
    void setPages(int pages) {
      Book::pages = pages;
    }
    const string &getPublisher() const {
      return publisher;
    }
    void setPublisher(const string &publisher) {
      Book::publisher = publisher;
    }
    const string &getIsbn() const {
      return isbn;
    }
    void setIsbn(const string &isbn) {
      Book::isbn = isbn;
    }
//    Function *****************************************************************************************
    void printInfo(){ //Printer
      string info = title + "; " + author + "; " + to_string(releaseDate) + "; " + to_string(pages) +
          "; " + publisher;
      if(isbn != ""){
        info.append("; " + isbn);
      }
      cout << info << endl;
    }
};

