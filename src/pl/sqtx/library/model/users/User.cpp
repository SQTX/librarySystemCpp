//
// Created by Jakub Sitarczyk on 25/03/2022.
//
#include "User.h"

using namespace std;

//Constructor
User::User(const string &firstName, const string &lastName, const string &pesel) : Person(firstName, lastName, pesel) {
//  this->person = person;
  this->allLoanNumb = 0;
  this->currentlyLoan = 0;
  this->returnedNumb = 0;
};
//Destructor
User::~User() {}

//Getters and setters
const vector<HistoryElement> &User::getUserHistory() const {
  return userHistory;
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

unsigned int User::getReturnedNumb() const {
  return returnedNumb;
}
void User::setReturnedNumb(unsigned int returnedNumb) {
  User::returnedNumb = returnedNumb;
}

//Other methods
string User::toString(){
  string info;
  info.append(getFirstName() + "; " + getLastName() + "; " + getPesel() + "; " +
    to_string(allLoanNumb) + "; " + to_string(currentlyLoan) + "; " + to_string(returnedNumb));
//  info.append(person.getFirstName() + "; " + person.getLastName() + "; " + person.getPesel() + "; " +
//    to_string(allLoanNumb) + "; " + to_string(currentlyLoan) + "; " + to_string(returnedNumb));
  return info;
}
string User::toSave(){
  string info;
  info.append("\nUser;" + getFirstName() + ";" + getLastName() + ";" + getPesel() + ";" +
              to_string(allLoanNumb) + ";" + to_string(currentlyLoan) + ";" + to_string(returnedNumb));
  return info;
}
string User::toSaveUserHistory(int i){
  string info;
  //TODO: getElemSecondPart dla magazynu tworzy spacje i jest bład. Magazayn posiada od teraz getElemSecondPartToSave
  info.append(userHistory[i].getElemTitle() + ";" + userHistory[i].getElemSecondPart() + ";" +
    userHistory[i].getElemLoanDate() + ";" + userHistory[i].getElemReturnDate());
  return info;
}

void User::addBorrowedPublications(PublicationPtr publication){
  borrowedPublications.push_back(publication);
}
void User::addHistoryElement(HistoryElement historyElement){
  userHistory.push_back(historyElement);
}

void User::lendPublication(PublicationPtr publication, HistoryElement historyElement){
  borrowedPublications.push_back(publication);
  userHistory.push_back(historyElement);
//  Statistic
  allLoanNumb++;
  currentlyLoan++;
}
void User::returnPublication(std::string title, std::string secondPart, std::string time){
  for(int i = 0; i < borrowedPublications.size(); i++){
    if(title == borrowedPublications[i]->getTitle()) {
      string bPSecondPart;
      if(dynamic_cast<Book *>(borrowedPublications[i].get())){
        bPSecondPart = dynamic_cast<Book *>(borrowedPublications[i].get())->getAuthor();
      } else if(dynamic_cast<Magazine *>(borrowedPublications[i].get())){
        bPSecondPart = dynamic_cast<Magazine *>(borrowedPublications[i].get())->createFullDateOfPublication();
      }
      if(secondPart == bPSecondPart) borrowedPublications.erase(borrowedPublications.begin() + i);
    }
  }
  for(int i = 0; i < userHistory.size(); i++){
    if ((title == userHistory[i].getElemTitle()) &&
        secondPart == userHistory[i].getElemSecondPart() &&
        userHistory[i].getElemReturnDate() == "0"){
      userHistory[i].setElemReturnDate(time);
    }
  }
  //  Statistic
  currentlyLoan--;
  returnedNumb++;
}
