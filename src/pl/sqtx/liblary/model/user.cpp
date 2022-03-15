//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "user.h"

User::User(const std::string &firstName, const std::string &lastName, const std::string &pesel) {
  this->firstName = firstName;
  this->lastName = firstName;
  this->pesel = firstName;
}

User::~User() {}

const std::string &User::getFirstName() const {
  return firstName;
}

void User::setFirstName(const std::string &firstName) {
  User::firstName = firstName;
}

const std::string &User::getLastName() const {
  return lastName;
}

void User::setLastName(const std::string &lastName) {
  User::lastName = lastName;
}

const std::string &User::getPesel() const {
  return pesel;
}

void User::setPesel(const std::string &pesel) {
  User::pesel = pesel;
}

bool User::operator==(const User &rhs) const {
  return firstName == rhs.firstName &&
         lastName == rhs.lastName &&
         pesel == rhs.pesel;
}

bool User::operator!=(const User &rhs) const {
  return !(rhs == *this);
}

std::string User::toString(){
  return firstName + "; " + lastName + "; " + pesel;
}

std::string User::toSave(){
  return firstName + ";" + lastName + ";" + pesel;
}
