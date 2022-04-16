//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARY_H
#define LIBRARYSYSTEM_LIBRARY_H

/*Headers*/
#include "../include/main_h.h"
#include "../io/consolePrinter.h"
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
//  --- Getters ---
  const std::vector<PublicationPtr> &getPublications() const;
  std::vector<PublicationPtr>::iterator &getIteratorPublications();

  void addBook(PublicationPtr book);  //Add new book to lab

  void addMagazine(PublicationPtr magazine);  //Add new magazine to lab

private:
  void addPublication(PublicationPtr publication);  //Add new Publication to lib - MAIN function

public:
  void removeBook(PublicationPtr book); //Remove book from lab

  void removeMagazine(PublicationPtr magazine); //Remove magazine from lab

private:
  void removePublication(PublicationPtr publication); //Remove Publication from lab - MAIN function
};

#endif //LIBRARYSYSTEM_LIBRARY_H
