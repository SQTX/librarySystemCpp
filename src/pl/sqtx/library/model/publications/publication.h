//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_PUBLICATION_H
#define LIBRARYSYSTEM_PUBLICATION_H

#include "../../include/main_h.h"

class Publication{
protected:
  std::string title;
  int releaseDate;
  std::string publisher;
  bool isLoan;
  std::string currentlyOwns;

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

  bool getIsLoan() const;
  void setIsLoan(bool borrStatus);

  const std::string &getCurrentlyOwns() const;

  void setCurrentlyOwns(const std::string &currentlyOwns);

//  Equals  ---------------------------------------------------------------------
  bool operator==(const Publication &rhs) const;
  bool operator!=(const Publication &rhs) const;

//  Methods   ---------------------------------------------------------------------
//Virtual method
  virtual std::string toString(); //Prepere to printout
  virtual std::string toSave(); //Prepere to save
};

#endif //LIBRARYSYSTEM_PUBLICATION_H
