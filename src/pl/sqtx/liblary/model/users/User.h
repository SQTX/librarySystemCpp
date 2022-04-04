//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_USERLENDHISTORY_H
#define LIBRARYSYSTEM_USERLENDHISTORY_H

#include "../include/main_h.h"
#include "BorrowedPublications.h"

typedef std::shared_ptr<BorrowedPublications> BorrPublicationsPtr;

class userLendHistory {
private:
  std::vector<BorrPublicationsPtr> historyOfBorrow;
  unsigned int allBorrNumb = 0;
  unsigned int currentlyBorrowed = 0;
  unsigned int returedNumb = 0;
public:
  const std::vector<BorrPublicationsPtr> &getHistoryOfUser() const;
  std::vector<BorrPublicationsPtr>::iterator getIteratorHistoryOfUser();

  void borrowPublication(BorrowedPublications publication);

  void returnPublication();

  std::string getHistory();
};

#endif //LIBRARYSYSTEM_USERLENDHISTORY_H