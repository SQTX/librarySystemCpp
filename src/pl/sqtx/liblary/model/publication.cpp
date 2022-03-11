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
}

//  Destructor  ---------------------------------------------------------------------
Publication::~Publication() {}

//  Getter and Setter  ---------------------------------------------------------------------
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

//  Equals  ---------------------------------------------------------------------
bool Publication::operator==(const Publication &rhs) const {
  return title == rhs.title &&
         releaseDate == rhs.releaseDate &&
         publisher == rhs.publisher;
}

bool Publication::operator!=(const Publication &rhs) const {
  return !(rhs == *this);
}

//  Methods   ---------------------------------------------------------------------
//Virtual method
string Publication::toString(){};
string Publication::toSave(){};
