//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#include "BorrowedPublications.h"

using namespace std;

BorrowedPublications::BorrowedPublications(const PublicationPtr &borrPublication, const std::string &dateOfLoan, vector<PublicationPtr>::iterator it_borrPub){
  this->borrPublication = borrPublication;
  this->dateOfLoan = dateOfLoan;
  this->dateOfReturn = "";
  this->borrStatus = true;
  this->obj_iterator = it_borrPub;
}

BorrowedPublications::~BorrowedPublications() {}

void BorrowedPublications::returnPublication(std::string dayDate){
  BorrowedPublications::dateOfReturn = dayDate;
  BorrowedPublications::borrStatus = false;
}

//  Create string-line with the information about Book object
string BorrowedPublications::bookToString() {
  string info;
  if(dynamic_cast<Book *>(borrPublication.get())){
    info = borrPublication->getTitle() + "; " + (dynamic_cast<Book *>(borrPublication.get())->getAuthor()) + "; ";
  }else if(dynamic_cast<Magazine *>(borrPublication.get())){
    info = borrPublication->getTitle() + "; " + to_string(dynamic_cast<Magazine *>(borrPublication.get())->getDay()) +
        "; " + to_string(dynamic_cast<Magazine *>(borrPublication.get())->getMonth()) +
        "; " + to_string(borrPublication->getReleaseDate()) + "; ";
  }
  info.append(dateOfLoan) + "; ";
  if(!borrStatus) info.append("zwrocona: " + dateOfReturn);
  return info;
}

//  Create string-line with the information arranged for data export
string BorrowedPublications::toSave() {
  string info = borrPublication->getTitle() + ";" + (dynamic_cast<Book *>(borrPublication.get())->getAuthor()) + ";" +
      dateOfLoan + ";" + to_string(borrStatus) + ";" + dateOfReturn;
  return info;
}