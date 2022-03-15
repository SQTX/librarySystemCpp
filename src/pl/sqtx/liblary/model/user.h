//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#ifndef LIBRARYSYSTEM_USER_H
#define LIBRARYSYSTEM_USER_H

#include "../include/main_h.h"

class User{
protected:
  std::string firstName;
  std::string lastName;
  std::string pesel;
public:
//  Constructor  ---------------------------------------------------------------------
  User(const std::string &firstName, const std::string &lastName, const std::string &pesel);
//  Destructor  ---------------------------------------------------------------------
  virtual ~User();
//  Getter and setter
  const std::string &getFirstName() const;

  void setFirstName(const std::string &firstName);

  const std::string &getLastName() const;

  void setLastName(const std::string &lastName);

  const std::string &getPesel() const;

  void setPesel(const std::string &pesel);
//  Equals  ---------------------------------------------------------------------
  bool operator==(const User &rhs) const;

  bool operator!=(const User &rhs) const;
//  Method  ---------------------------------------------------------------------
  std::string toString();
  std::string toSave();
};

#endif //LIBRARYSYSTEM_USER_H
