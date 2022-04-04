//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "user.h"

using namespace std;

//Constructor
User::User(const string &firstName, const string &lastName, const string &pesel) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->pesel = pesel;
}

//Destructor
User::~User() {}

//Getters and setters
const string &User::getFirstName() const {
  return firstName;
}

void User::setFirstName(const string &firstName) {
  User::firstName = firstName;
}

const string &User::getLastName() const {
  return lastName;
}

void User::setLastName(const std::string &lastName) {
  User::lastName = lastName;
}

const std::string &User::getPesel() const {
  return pesel;
}

void User::setPesel(const string &pesel) {
  User::pesel = pesel;
}

const userLendHistory &User::getUserHistory() const {
  return userHistory;
}

//Equals
bool User::operator==(const User &rhs) const {
  return firstName == rhs.firstName &&
         lastName == rhs.lastName &&
         pesel == rhs.pesel;
}

bool User::operator!=(const User &rhs) const {
  return !(rhs == *this);
}

//Borrow methods
void User::lendPublication(BorrowedPublications borrPub){
  userHistory.borrowPublication(borrPub);
}

void User::returnPublication(){
  userHistory.returnPublication();
}

//To.. methods
string User::toString() {
  return firstName + "; " + lastName + "; " + pesel;
}
string User::toSave() {
  return firstName + ";" + lastName + ";" + pesel;
}

string User::getStringHistoryOfUser(){
  return userHistory.getHistory();
}