//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "Person.h"

using namespace std;

//Constructor
Person::Person(const string &firstName, const string &lastName, const string &pesel) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->pesel = pesel;
}

//Destructor
Person::~Person() {}

//Getters and setters
const string &Person::getFirstName() const {
  return firstName;
}

void Person::setFirstName(const string &firstName) {
  Person::firstName = firstName;
}

const string &Person::getLastName() const {
  return lastName;
}

void Person::setLastName(const std::string &lastName) {
  Person::lastName = lastName;
}

const std::string &Person::getPesel() const {
  return pesel;
}

void Person::setPesel(const string &pesel) {
  Person::pesel = pesel;
}

//Equals
bool Person::operator==(const Person &rhs) const {
  return firstName == rhs.firstName &&
         lastName == rhs.lastName &&
         pesel == rhs.pesel;
}
bool Person::operator!=(const Person &rhs) const {
  return !(rhs == *this);
}

//Other methods
string Person::toString() {
  return firstName + "; " + lastName + "; " + pesel;
}

string Person::toSave() {
  return firstName + ";" + lastName + ";" + pesel;
}