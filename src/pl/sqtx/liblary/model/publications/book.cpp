//
// Created by Jakub Sitarczyk on 02/12/2021.
//
/*Headers*/
#include "book.h"

using namespace std;

//    Constructors  ---------------------------------------------------------------------
Book::Book(string title, string author = "", int releaseDate = 0, int pages = 0, string publisher = "",
           string isbn = "") : Publication(title, releaseDate, publisher) /*constructor inheritance*/ {
  this->author = author;
  this->pages = pages;
  this->isbn = isbn;
}

//    Destructors  ---------------------------------------------------------------------
Book::~Book() {}

//  Getter and Setter  ---------------------------------------------------------------------
const string &Book::getAuthor() const {
  return author;
}

void Book::setAuthor(const string &author) {
  Book::author = author;
}

int Book::getPages() const {
  return pages;
}

void Book::setPages(int pages) {
  Book::pages = pages;
}

const string &Book::getIsbn() const {
  return isbn;
}

void Book::setIsbn(const string &isbn) {
  Book::isbn = isbn;
}

//  Equals  ---------------------------------------------------------------------
bool Book::operator==(const Book &rhs) const {
  return static_cast<const Publication &>(*this) == static_cast<const Publication &>(rhs) &&
         author == rhs.author &&
         pages == rhs.pages &&
         isbn == rhs.isbn;
}

bool Book::operator!=(const Book &rhs) const {
  return !(rhs == *this);
}

//    Methods  ---------------------------------------------------------------------
//  Create string-line with the information about Book object
string Book::toString() {
  string info = getTitle() + "; " + author + "; " + to_string(getReleaseDate()) + "; " + to_string(pages) +
                "; " + getPublisher();
  if (isbn != "") {
    info.append("; " + isbn);
  }
  return info;
}

//  Create string-line with the information arranged for data export
string Book::toSave() {
  string info = getTitle() + ";" + author + ";" + to_string(getReleaseDate()) + ";" + to_string(pages) +
                ";" + getPublisher();
  if (isbn != "") {
    info.append(";" + isbn);
  }
  return info;
}