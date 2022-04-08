//
// Created by Jakub Sitarczyk on 16/12/2021.
//
#include "magazine.h"

using namespace std;

//  Constructor  ---------------------------------------------------------------------
Magazine::Magazine(string title, int day = 1, int month = 1, int releaseDate = 0, string language = "",
                   string publisher = "") : Publication(title, releaseDate, publisher) /*constructor inheritance*/ {
  this->month = month;
  this->day = day;
  this->language = language;
}
//  Destructors  ---------------------------------------------------------------------
Magazine::~Magazine() {}
//  Getter and setter  ---------------------------------------------------------------------
int Magazine::getMonth() const {
  return month;
}
void Magazine::setMonth(int month) {
  Magazine::month = month;
}

int Magazine::getDay() const {
  return day;
}
void Magazine::setDay(int day) {
  Magazine::day = day;
}

const string &Magazine::getLanguage() const {
  return language;
}
void Magazine::setLanguage(const string &language) {
  Magazine::language = language;
}

//  Equals  ---------------------------------------------------------------------
bool Magazine::operator==(const Magazine &rhs) const {
  return static_cast<const Publication &>(*this) == static_cast<const Publication &>(rhs) &&
         month == rhs.month &&
         day == rhs.day &&
         language == rhs.language;
}

bool Magazine::operator!=(const Magazine &rhs) const {
  return !(rhs == *this);
}

//    Methods  ---------------------------------------------------------------------
//  Create string-line with the information about Book object
string Magazine::toString() { //Printer
  string info = getTitle() + "; " + to_string(day) + "; " + to_string(month) + "; " + to_string(getReleaseDate()) + "; "
                + language + "; " + getPublisher() + "; ";
  getIsLoan() ? info.append("niedostepna") : info.append("dostepna");
  return info;
}

//  Create string-line with the information arranged for data export
string Magazine::toSave() { //Printer
  string info = getTitle() + ";" + to_string(day) + ";" + to_string(month) + ";" + to_string(getReleaseDate()) +
                ";" + language + ";" + getPublisher() + ";" + to_string(getIsLoan() ? 0 : 1) + ";";
  if(isLoan) info.append(currentlyOwns);
  else info.append("0");
  return info;
}

string Magazine::createSecondPart(){
  string secondPart = to_string(day) + "; " + to_string(day) + "; " + to_string(getReleaseDate());
  return secondPart;
}
