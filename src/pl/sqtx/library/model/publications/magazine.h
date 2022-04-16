//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_MAGAZINE_H
#define LIBRARYSYSTEM_MAGAZINE_H

#include "publication.h"

//*********************************************************************************************************************
class Magazine : public Publication {
private:
  int month;
  int day;
  std::string language;

public:
//  Constructor  ---------------------------------------------------------------------
  Magazine(std::string title, int day, int month, int releaseDate, std::string language, std::string publisher);

//  Destructors  ---------------------------------------------------------------------
  virtual ~Magazine();

//  Getter and setter  ---------------------------------------------------------------------
  int getMonth() const;
  void setMonth(int month);

  int getDay() const;
  void setDay(int day);

  const std::string &getLanguage() const;
  void setLanguage(const std::string &language);

//  Equals  ---------------------------------------------------------------------
  bool operator==(const Magazine &rhs) const;
  bool operator!=(const Magazine &rhs) const;

//    Methods  ---------------------------------------------------------------------
  /**Create string-line with the information about Magazine object.*/
  std::string toString() override; //Prepere to printout
  /**Create string-line with the information arranged for data export.*/
  std::string toSave() override; //Prepere to save
  /**Create string-line creates lines containing day, month and year.*/
  std::string createSecondPart();
};

#endif //LIBRARYSYSTEM_MAGAZINE_H
