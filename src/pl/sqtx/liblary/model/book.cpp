//
// Created by Jakub Sitarczyk on 02/12/2021.
//
/*Headers*/
#include "../include/publication_h.h"

using namespace std;
//*********************************************************************************************************************
class Book : public Publication{
private:
    string author;
    int pages;
    string isbn;

public:
//    Constructors  ---------------------------------------------------------------------
    Book(string title = "", string author = "", int releaseDate = 0, int pages = 0, string publisher = "",
         string isbn = "") : Publication(title, releaseDate, publisher) /*constructor inheritance*/ {
      this->author = author;
      this->pages = pages;
      this->isbn = isbn;
    }

//    Destructors  ---------------------------------------------------------------------
  virtual ~Book() {}

//  Getter and Setter  ---------------------------------------------------------------------
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

  //  Equals  ---------------------------------------------------------------------
  bool operator==(const Book &rhs) const {
    return static_cast<const Publication &>(*this) == static_cast<const Publication &>(rhs) &&
           author == rhs.author &&
           pages == rhs.pages &&
           isbn == rhs.isbn;
  }
  bool operator!=(const Book &rhs) const {
    return !(rhs == *this);
  }

//    Methods  ---------------------------------------------------------------------
//  Create string-line with the information about Book object
  string toString() override{
    string info = getTitle() + "; " + author + "; " + to_string(getReleaseDate()) + "; " + to_string(pages) +
        "; " + getPublisher();
    if(isbn != ""){
      info.append("; " + isbn);
    }
    return info;
  }

//  Create string-line with the information arranged for data export
  string toSave() override{
    string info = getTitle() + ";" + author + ";" + to_string(getReleaseDate()) + ";" + to_string(pages) +
        ";" + getPublisher();
    if(isbn != ""){
      info.append(";" + isbn);
    }
    return info;
  }
};

