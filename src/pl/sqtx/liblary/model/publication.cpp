//
// Created by Jakub Sitarczyk on 16/12/2021.
//
//Headers
#include "../include/main_h.h"

class Publication{
private:
  string title;
  int releaseDate;
  string publisher;

//  Getter and Setter
public:
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
};
