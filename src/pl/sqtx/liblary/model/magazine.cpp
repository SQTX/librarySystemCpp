//
// Created by Jakub Sitarczyk on 16/12/2021.
//
/*Headers*/
#include "../include/publication_h.h"

using namespace std;
//*********************************************************************************************************************
class Magazine : public Publication{
private:
  int month;
  int day;
  string language;

public:
//  Constructor  ---------------------------------------------------------------------
  Magazine(string title = "", int day = 1, int month = 1, int releaseDate = 0, string language = "", string publisher = "")
  : Publication(title, releaseDate, publisher) /*constructor inheritance*/ {
    this -> month = month;
    this -> day = day;
    this -> language = language;
  }

//  Destructors  ---------------------------------------------------------------------
  virtual ~Magazine() {}

//  Getter and setter  ---------------------------------------------------------------------
  int getMonth() const {
    return month;
  }

  void setMonth(int month) {
    Magazine::month = month;
  }

  int getDay() const {
    return day;
  }

  void setDay(int day) {
    Magazine::day = day;
  }

  const string &getLanguage() const {
    return language;
  }

  void setLanguage(const string &language) {
    Magazine::language = language;
  }

//  Equals  ---------------------------------------------------------------------
  bool operator==(const Magazine &rhs) const {
    return static_cast<const Publication &>(*this) == static_cast<const Publication &>(rhs) &&
           month == rhs.month &&
           day == rhs.day &&
           language == rhs.language;
  }
  bool operator!=(const Magazine &rhs) const {
    return !(rhs == *this);
  }

//    Methods  ---------------------------------------------------------------------
//  Create string-line with the information about Book object
  string toString() override { //Printer
    string info = getTitle() + "; " + to_string(day) + "; " + to_string(month) + "; "+ to_string(getReleaseDate()) + "; "
        + language + "; " + getPublisher();
    return info;
  }

//  Create string-line with the information arranged for data export
  string toSave() override { //Printer
    string info = getTitle() + ";" + to_string(day) + ";" + to_string(month) + ";"+ to_string(getReleaseDate()) +
        ";" + language + ";" + getPublisher();
    return info;
  }
};
