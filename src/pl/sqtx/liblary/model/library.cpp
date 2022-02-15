//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/publication_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;
class Library{
private:
  vector<PublicationPtr> publications;
  static const int maxPublications = 1000;
  int publicationsNumber = 0;

public:
  const vector<PublicationPtr> &getPublications() const {
    return publications;
  }

//  Add new book to lab
  void addBook(PublicationPtr book){
    addPublication(book);
  }
  //  Add new magazine to lab
  void addMagazine(PublicationPtr magazine){
    addPublication(magazine);
  }

private:
  void addPublication(PublicationPtr publication){
    if(publicationsNumber >= maxPublications) {
      throw out_of_range("Przekroczono dozwolony limit publikacji.");
    }else{
      publications.push_back(publication);
      publicationsNumber++;
    }
  }
};
