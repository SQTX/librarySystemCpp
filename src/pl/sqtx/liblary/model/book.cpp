//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Headers
#include "../include/publication_h.h"

using namespace std;
class Book : public Publication{ //Book class
private:
    string author;
    int pages;
    string isbn;
public:
//    Constructors  ****************************************************************************************
    Book(string title = "", string author = "", int releaseDate = 0, int pages = 0, string publisher = "",
         string isbn = "") {
    setTitle(title);  //publication element
    setReleaseDate(releaseDate);
    setPublisher(publisher);
      this->author = author;
      this->pages = pages;
      this->isbn = isbn;
    }
//  Getter and Setter *****************************************************************************************
    const string &getAuthor() const {
      return author;
    }
    void setAuthor(const string &author) {
      Book::author = author;
    }
    int getPages() const {
      return pages;
    }
    void setPages(int pages) {
      Book::pages = pages;
    }
    const string &getIsbn() const {
      return isbn;
    }
    void setIsbn(const string &isbn) {
      Book::isbn = isbn;
    }
//    Function *****************************************************************************************
    void printInfo(){ //Printer
      string info = getTitle() + "; " + author + "; " + to_string(getReleaseDate()) + "; " + to_string(pages) +
          "; " + getPublisher();
      if(isbn != ""){
        info.append("; " + isbn);
      }
      cout << info << endl;
    }
};

