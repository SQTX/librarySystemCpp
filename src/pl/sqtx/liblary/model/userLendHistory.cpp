//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#include "userLendHistory.h"

using namespace std;

const std::vector<BorrPublicationsPtr> &userLendHistory::getHistoryOfUser() const {
  return historyOfBorrow;
}

vector<BorrPublicationsPtr>::iterator userLendHistory::getIteratorHistoryOfUser() {
  vector<BorrPublicationsPtr>::iterator it_historyOfBorrow = historyOfBorrow.begin();
  return it_historyOfBorrow;
}

void userLendHistory::borrowPublication(BorrowedPublications publication){
  BorrPublicationsPtr borrPub = make_shared<BorrowedPublications>(publication);
  historyOfBorrow.push_back(borrPub);
//  Statistic
  allBorrNumb++;
  currentlyBorrowed++;
};

void userLendHistory::returnPublication(){
  currentlyBorrowed--;
  returedNumb++;
};

string userLendHistory::getHistory(){
  string info = to_string(allBorrNumb) + "; " + to_string(currentlyBorrowed) + "; " + to_string(returedNumb);
  for(int i = 0; i < historyOfBorrow.size(); ++i) {
    info.append('\n' + historyOfBorrow.at(i)->bookToString());
  }
  return info;
};