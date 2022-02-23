//
// Created by Jakub Sitarczyk on 09/12/2021.
//
/*Headers*/
#include "../include/main_h.h"
#include "../include/publication_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;

class Library {
private:
//  Main data
  vector<PublicationPtr> publications;  //Main vector
  static const int maxPublications = 1000;  //Publications limit
  int publicationsNumber = 0; //Number of publications

//  Vector getter
public:
  const vector<PublicationPtr> &getPublications() const {
    return publications;
  }

//  Add new book to lab
  void addBook(PublicationPtr book) {
    addPublication(book);
  }

//  Add new magazine to lab
  void addMagazine(PublicationPtr magazine) {
    addPublication(magazine);
  }

//  Add new publication to lib - MAIN function
private:
  void addPublication(PublicationPtr publication) {
    if (publicationsNumber >= maxPublications) {
      throw out_of_range("Przekroczono dozwolony limit publikacji.");
    } else {
      publications.push_back(publication);
      publicationsNumber++;
    }
  }

//  Remove book from lab
public:
  void removeBook(PublicationPtr book) {
    removePublication(book);
  }

//  Remove magazine from lab
  void removeMagazine(PublicationPtr magazine) {
    removePublication(magazine);
  }

//  Remove publication from lab - MAIN function
private:
  void removePublication(PublicationPtr publication) {
    if (dynamic_cast<Book *>(publication.get()) || dynamic_cast<Magazine *>(publication.get())) {
      for(int index = 0; index < publications.size(); index++){
        if(*(publication.get()) == *(publications[index].get())){
          publications.erase((publications.begin()+index));
          publicationsNumber--;
        }
      }
    } else {
      throw invalid_argument("Publikacja nie została znaleziona i usunięta.");
    }
  }
};
