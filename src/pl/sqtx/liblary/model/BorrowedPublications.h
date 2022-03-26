//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_BORROWEDPUBLICATIONS_H
#define LIBRARYSYSTEM_BORROWEDPUBLICATIONS_H

#include "../include/main_h.h"
#include "../include/publicationType_h.h"
#include "publications/publication.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class BorrowedPublications {
private:
  PublicationPtr borrPublications;
  std::string dateOfLoan;
  std::string dateOfReturn;
  bool borrStatus;
public:
  BorrowedPublications(const PublicationPtr &borrPublications, const std::string &dateOfLoan);

  virtual ~BorrowedPublications();

  void returnPublication(std::string date);
};

#endif //LIBRARYSYSTEM_BORROWEDPUBLICATIONS_H
