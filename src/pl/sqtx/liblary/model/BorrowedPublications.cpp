//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#include "BorrowedPublications.h"

BorrowedPublications::BorrowedPublications(const PublicationPtr &borrPublications, const std::string &dateOfLoan){
  this->borrPublications = borrPublications;
  this->dateOfLoan = dateOfLoan;
  this->dateOfReturn = "";
  this->borrStatus = true;
}

BorrowedPublications::~BorrowedPublications() {}

void BorrowedPublications::returnPublication(std::string dayDate){
  BorrowedPublications::dateOfReturn = dayDate;
  BorrowedPublications::borrStatus = false;
}