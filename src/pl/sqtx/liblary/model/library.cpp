//
// Created by Jakub Sitarczyk on 09/12/2021.
//

#include "library.h"

using namespace std;

const vector<PublicationPtr> &library::getPublications() const {
  return publications;
}

//  Add new book to lab
void library::addBook(PublicationPtr book) {
  addPublication(book);
}

//  Add new magazine to lab
void library::addMagazine(PublicationPtr magazine) {
  addPublication(magazine);
}

//  Add new Publication to lib - MAIN function
void library::addPublication(PublicationPtr publication) {
  if (publicationsNumber >= maxPublications) {
    throw out_of_range("Przekroczono dozwolony limit publikacji.");
  } else {
    publications.push_back(publication);
    publicationsNumber++;
  }
}

//  Remove book from lab
void library::removeBook(PublicationPtr book) {
  removePublication(book);
}

//  Remove magazine from lab
void library::removeMagazine(PublicationPtr magazine) {
  removePublication(magazine);
}

//  Remove Publication from lab - MAIN function
void library::removePublication(PublicationPtr publication) {
  if (dynamic_cast<Book *>(publication.get()) || dynamic_cast<Magazine *>(publication.get())) {
    for (int index = 0; index < publications.size(); index++) {
      if (*(publication.get()) == *(publications[index].get())) {
        publications.erase((publications.begin() + index));
        publicationsNumber--;
      }
    }
  } else {
    throw invalid_argument("Publikacja nie zostala znaleziona i usunieta.");
  }
}