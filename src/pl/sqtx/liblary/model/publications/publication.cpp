//
// Created by Jakub Sitarczyk on 16/12/2021.
//

#include "publication.h"

using namespace std;

//  Constructor  ---------------------------------------------------------------------
Publication::Publication(const string &title, int releaseDate, const string &publisher) {
  this->title = title;
  this->releaseDate = releaseDate;
  this->publisher = publisher;
//  Loan System
  this->dateOfLoan = "";
  this->dateOfReturn = "";
  this->isLoan = false;
}

//Destructor  ---------------------------------------------------------------------
Publication::~Publication() {}

//Getter and Setter  ---------------------------------------------------------------------
string Publication::getTitle() const {
  return title;
}
void Publication::setTitle(const string &title) {
  Publication::title = title;
}

int Publication::getReleaseDate() const {
  return releaseDate;
}
void Publication::setReleaseDate(int releaseDate) {
  Publication::releaseDate = releaseDate;
}

string Publication::getPublisher() const {
  return publisher;
}
void Publication::setPublisher(const string &publisher) {
  Publication::publisher = publisher;
}

//  Loan System ********************************************
string Publication::getDateOfLoan() const {
  return dateOfLoan;
}
void Publication::setDateOfLoan(const string &dateOfLoan) {
  Publication::dateOfLoan = dateOfLoan;
}

string Publication::getDateOfReturn() const {
  return dateOfReturn;
}
void Publication::setDateOfReturn(const string &dateOfReturn) {
  Publication::dateOfReturn = dateOfReturn;
}

bool Publication::getIsLoan() const {
  return isLoan;
}
void Publication::setIsLoan(bool borrStatus) {
  Publication::isLoan = borrStatus;
}

//Equals  ---------------------------------------------------------------------
bool Publication::operator==(const Publication &rhs) const {
  return title == rhs.title &&
         releaseDate == rhs.releaseDate &&
         publisher == rhs.publisher;
}

bool Publication::operator!=(const Publication &rhs) const {
  return !(rhs == *this);
}

//Other methods   ---------------------------------------------------------------------
string loanStatusToString(){
  string info;
  info.append()
  = borrPublication->getTitle() + ";" + (dynamic_cast<Book *>(borrPublication.get())->getAuthor()) + ";" +
                dateOfLoan + ";" + to_string(borrStatus) + ";" + dateOfReturn;
  return info;
}
string loanStatusToSave();

//Virtual methods:
string Publication::toString(){};
string Publication::toSave(){}
