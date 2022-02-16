//
// Created by Jakub Sitarczyk on 16/12/2021.
//
//Headers
#include "../include/main_h.h"
class Publication{
protected:
  string title;
  int releaseDate;
  string publisher;

public:
//  Constructor
  Publication(string title = "", int releaseDate = 0, string publisher = ""){
    this -> title = title;
    this -> releaseDate = releaseDate;
    this -> publisher = publisher;
  }
//  Destructor
  virtual ~Publication() {

  }
//  Getter and Setter
  string getTitle() const {
    return title;
  }

  void setTitle(const string &title) {
    Publication::title = title;
  }

  int getReleaseDate() const {
    return releaseDate;
  }

  void setReleaseDate(int releaseDate) {
    Publication::releaseDate = releaseDate;
  }

  string getPublisher() const {
    return publisher;
  }

  void setPublisher(const string &publisher) {
    Publication::publisher = publisher;
  }
//  Equals ****************************************************************************************
  bool operator==(const Publication &rhs) const {
    return title == rhs.title &&
           releaseDate == rhs.releaseDate &&
           publisher == rhs.publisher;
  }
  bool operator!=(const Publication &rhs) const {
    return !(rhs == *this);
  }
//  Method ****************************************************************************************
  virtual string toString(){}  //Virtual method
  virtual string toSave(){}  //Virtual method
};
