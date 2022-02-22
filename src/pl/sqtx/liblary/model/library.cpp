//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/publication_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;
class Library {
private:
  vector<PublicationPtr> publications;
  static const int maxPublications = 1000;
  int publicationsNumber = 0;

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

private:
  void addPublication(PublicationPtr publication) {
    if (publicationsNumber >= maxPublications) {
      throw out_of_range("Przekroczono dozwolony limit publikacji.");
    } else {
      publications.push_back(publication);
      publicationsNumber++;
    }
  }

public:
//  Delete functions
  void removeBook(PublicationPtr book) {
    removePublication(book);
  }

  void removeMagazine(PublicationPtr magazine) {
    removePublication(magazine);
  }
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
