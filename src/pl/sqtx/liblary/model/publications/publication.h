//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_PUBLICATION_H
#define LIBRARYSYSTEM_PUBLICATION_H

/*Headers*/
#include "../../include/main_h.h"

class Publication{
protected:
  std::string title;
  int releaseDate;
  std::string publisher;

public:
//  Constructor  ---------------------------------------------------------------------
  Publication(const std::string &title, int releaseDate, const std::string &publisher);

//  Destructor  ---------------------------------------------------------------------
  virtual ~Publication();

//  Getter and Setter  ---------------------------------------------------------------------
  std::string getTitle() const;

  void setTitle(const std::string &title);

  int getReleaseDate() const;

  void setReleaseDate(int releaseDate);

  std::string getPublisher() const;

  void setPublisher(const std::string &publisher);

//  Equals  ---------------------------------------------------------------------
  bool operator==(const Publication &rhs) const;
  bool operator!=(const Publication &rhs) const;

//  Methods   ---------------------------------------------------------------------
//Virtual method
  virtual std::string toString();
  virtual std::string toSave();
};

#endif //LIBRARYSYSTEM_PUBLICATION_H
