//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARY_H
#define LIBRARYSYSTEM_LIBRARY_H

/*Headers*/
#include "../include/main_h.h"
#include "publication.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class library {
private:
//  Main data
  std::vector<PublicationPtr> publications;  //Main vector
  static const int maxPublications = 1000;  //Publications limit
  int publicationsNumber = 0; //Number of publications

//  Vector getter
public:
  const std::vector<PublicationPtr> &getPublications() const;

//  Add new book to lab
  void addBook(PublicationPtr book);

//  Add new magazine to lab
  void addMagazine(PublicationPtr magazine);

//  Add new Publication to lib - MAIN function
private:
  void addPublication(PublicationPtr publication);

//  Remove book from lab
public:
  void removeBook(PublicationPtr book);

//  Remove magazine from lab
  void removeMagazine(PublicationPtr magazine);

//  Remove Publication from lab - MAIN function
private:
  void removePublication(PublicationPtr publication);
};

#endif //LIBRARYSYSTEM_LIBRARY_H
