//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#include "userLendHistory.h"

using namespace std;

const std::vector<BorrPublicationsPtr> &userLendHistory::getBorrowedPub() const {
  return historyOfBorrow;
}

void userLendHistory::borrowPub(BorrowedPublications publication){
  BorrPublicationsPtr borrPub = make_shared<BorrowedPublications>(publication);
  historyOfBorrow.push_back(borrPub);
//  Statistic
  allBorrNumb++;
  currentlyBorrowed++;
};

//void userLendHistory::returnPublication(BorrowedPublications publication){
//  for()
//
//
//  currentlyBorrowed--;
//  returedNumb++;
//};

string userLendHistory::getHistory(){
  string info = to_string(allBorrNumb) + "; " + to_string(allBorrNumb) + "; " + to_string(allBorrNumb);
  for(int i = 0; i < historyOfBorrow.size(); ++i) {
    info.append('\n' + historyOfBorrow.at(i)->bookToString());
  }
  return info;
};