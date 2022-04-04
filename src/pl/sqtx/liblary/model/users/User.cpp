//
// Created by Jakub Sitarczyk on 25/03/2022.
//
#include "User.h"

using namespace std;

//Constructor
User::User(const Person &person) : person(person) {
  this->person = person;
  this->allLoanNumb = 0;
  this->currentlyLoan = 0;
  this->returedNumb = 0;
};
//Destructor
User::~User() {}
//Getters and setters
const Person &User::getPerson() const {
  return person;
}
void User::setPerson(const Person &person) {
  User::person = person;
}

unsigned int User::getAllLoanNumb() const {
  return allLoanNumb;
}
void User::setAllLoanNumb(unsigned int allLoanNumb) {
  User::allLoanNumb = allLoanNumb;
}

unsigned int User::getCurrentlyLoan() const {
  return currentlyLoan;
}
void User::setCurrentlyLoan(unsigned int currentlyLoan) {
  User::currentlyLoan = currentlyLoan;
}

unsigned int User::getReturedNumb() const {
  return returedNumb;
}
void User::setReturedNumb(unsigned int returedNumb) {
  User::returedNumb = returedNumb;
}
//Other methods
string User::toString(){
  string info;
  info.append(person.getFirstName() + "; " + person.getLastName() + "; " + person.getPesel() + "; " +
    to_string(allLoanNumb) + "; " + to_string(currentlyLoan) + "; " + to_string(returedNumb));
  return info;
}

string User::toSave(){
  return "Skura";
}

//string historyToString()

/*const std::vector<PublicationPtr> &User::getHistoryOfUser() const {
  return userHistory;
}

vector<PublicationPtr>::iterator User::getIteratorHistoryOfUser() {
  vector<PublicationPtr>::iterator it_historyOfBorrow = historyOfBorrow.begin();
  return it_historyOfBorrow;
}

void User::borrowPublication(BorrowedPublications publication){
  PublicationPtr borrPub = make_shared<BorrowedPublications>(publication);
  userHistory.push_back(borrPub);
//  Statistic
  allLoanNumb++;
  currentlyLoan++;
};

void User::returnPublication(){
//  Statistic
  currentlyLoan--;
  returedNumb++;
};

string User::getHistory(){
  string info = to_string(allBorrNumb) + "; " + to_string(currentlyBorrowed) + "; " + to_string(returedNumb);
  for(int i = 0; i < historyOfBorrow.size(); ++i) {
    info.append('\n' + historyOfBorrow.at(i)->bookToString());
  }
  return info;
}*/


