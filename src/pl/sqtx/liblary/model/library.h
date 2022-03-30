//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARY_H
#define LIBRARYSYSTEM_LIBRARY_H

/*Headers*/
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "publications/publication.h"
#include "../include/publicationType_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class library {
private:
//  Main data
  std::vector<PublicationPtr> publications;  //Main vector
  static const int maxPublications = 1000;  //Publications limit
  int publicationsNumber = 0; //Number of publications

public:
//  Vector getter
  const std::vector<PublicationPtr> &getPublications() const;

  std::vector<PublicationPtr>::iterator &getIteratorPublications();

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

/*  Function check is it element exists. If:
  yes - increase numberOf element
  no - do nothing */
  void checkIsItExistsAdd(PublicationPtr publication);

  void checkIsItExistsRemove(PublicationPtr publication);
};

#endif //LIBRARYSYSTEM_LIBRARY_H
