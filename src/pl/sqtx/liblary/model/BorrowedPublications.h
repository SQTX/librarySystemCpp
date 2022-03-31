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
  PublicationPtr borrPublication;
  std::string dateOfLoan;
  std::string dateOfReturn;
  bool borrStatus;
  std::vector<PublicationPtr>::iterator obj_iterator;
public:
  BorrowedPublications(const PublicationPtr &borrPublication, const std::string &dateOfLoan, std::vector<PublicationPtr>::iterator it_borrPub);

  virtual ~BorrowedPublications();

  void returnPublication(std::string date);

  std::string bookToString();
  std::string toSave();
};

#endif //LIBRARYSYSTEM_BORROWEDPUBLICATIONS_H
