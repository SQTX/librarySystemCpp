//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#ifndef LIBRARYSYSTEM_PERSON_H
#define LIBRARYSYSTEM_PERSON_H

#include "../../include/main_h.h"

class Person{
private:
  std::string firstName;
  std::string lastName;
  std::string pesel;

public:
//  Constructor ---------------------------------------------------------------------
  Person(const std::string &firstName, const std::string &lastName, const std::string &pesel);
//  Destructor  ---------------------------------------------------------------------
  virtual ~Person();
//  Getter and setter ---------------------------------------------------------------------
  const std::string &getFirstName() const;
  void setFirstName(const std::string &firstName);

  const std::string &getLastName() const;
  void setLastName(const std::string &lastName);

  const std::string &getPesel() const;
  void setPesel(const std::string &pesel);

//  Equals ---------------------------------------------------------------------
  bool operator==(const Person &rhs) const;
  bool operator!=(const Person &rhs) const;

//  Method ---------------------------------------------------------------------
  std::string toString(); //Prepere data to printout
  std::string toSave(); //Prepere data to save
};

#endif //LIBRARYSYSTEM_PERSON_H
