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
  this->isLoan = false;
  this->currentlyOwns = "0";
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

bool Publication::getIsLoan() const {
  return isLoan;
}
void Publication::setIsLoan(bool borrStatus) {
  Publication::isLoan = borrStatus;
}

const string &Publication::getCurrentlyOwns() const {
  return currentlyOwns;
}
void Publication::setCurrentlyOwns(const string &currentlyOwns) {
  Publication::currentlyOwns = currentlyOwns;
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

//--- Other methods --------------------------------------------------------------------------
//Virtual methods:
//TODO last: Dd sprawdzenia
string Publication::toString(){return " ";}
string Publication::toSave(){return " ";}
