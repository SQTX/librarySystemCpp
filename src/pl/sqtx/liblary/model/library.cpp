//
// Created by Jakub Sitarczyk on 09/12/2021.
//

#include "library.h"

using namespace std;

const vector<PublicationPtr> &library::getPublications() const {
  return publications;
}

std::vector<PublicationPtr>::iterator &library::getIteratorPublications(){
  vector<PublicationPtr>::iterator it_publications = publications.begin();
  return it_publications;
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
//  Check is it exists
    checkIsItExistsAdd(publication);
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
    checkIsItExistsRemove(publication);
  } else {
    throw invalid_argument("Publikacja nie zostala znaleziona i usunieta.");
  }
}

void library::checkIsItExistsAdd(PublicationPtr publication) {
  if (publicationsNumber == 0) {
    publications.push_back(publication);
    publicationsNumber++;
  } else {
    bool isItExists = false;
    for (auto &element: publications) {
      if (*(publication.get()) == *(element.get())) {
        int indexOfPublication = element->getNumberOf();
        element->setNumberOf(++indexOfPublication);
        publicationsNumber++;
        isItExists = true;
        break;
      }
    }
    if(!isItExists) {
      publications.push_back(publication);
      publicationsNumber++;
    }
  }
}

void library::checkIsItExistsRemove(PublicationPtr publication) {
//  Index is better because will be needed to removing publication from vectro
/*TODO: W momecie gdy Pub będzie wypożyczone wystąpi problem z usunięćiem bo ilość może być 0. Zrobić aby usuwało dla
 * wartości -1, tak bedziemy odróżniać publikację wyporzyczoną od usuniętej bo może być 0 dostępnych a w systemie dalej będą.*/
  for (int index = 0; index < publications.size(); index++) {
    if (*(publication.get()) == *(publications[index].get())) {
      int indexOfPublication = publications[index]->getNumberOf();
      if(indexOfPublication > 1) {
        publications[index]->setNumberOf(--indexOfPublication);
        publicationsNumber--;
      } else if(indexOfPublication == 1){
        publications.erase((publications.begin() + index));
        publicationsNumber--;
      }
    }
  }
}