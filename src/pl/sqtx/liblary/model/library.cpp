//
// Created by Jakub Sitarczyk on 09/12/2021.
//
//Headers
#include "../include/main_h.h"
#include "../include/publication_h.h"
#include "../include/publicationType_h.h"
#include <vector>
#include <memory>

typedef shared_ptr<Publication> PublicationPtr;
class Library{
private:
  vector<PublicationPtr> publications;
  static const int maxPublications = 1000;
  int publicationsNumber = 0;

public:
//  Add new book to lab
  void addBook(PublicationPtr book){
    if(publicationsNumber < maxPublications){
      publications.push_back(book);
      publicationsNumber++;
    }else{
      cout << "Maksymalna liczba książek została osiągnięta" << endl;
    }
  }
  //  Add new magazine to lab
  void addMagazine(PublicationPtr magazine){
    if(publicationsNumber < maxPublications){
      publications.push_back(magazine);
      publicationsNumber++;
    }else{
      cout << "Maksymalna liczba gazet została osiągnięta" << endl;
    }
  }
//  Print informations about all books in lab
  void printBooks(){
    int countBooks = 0;
    for(int i =0; i < publicationsNumber; i++){
      PublicationPtr ptr = publications[i];
      if(dynamic_cast<Book*>(ptr.get())){
        ptr->printInfo();
        countBooks++;
      }
    }
    if(countBooks == 0){
      cout << "Brak ksiazek w bibliotece" << endl;
    }
  }
  //  Print informations about all magazines in lab
  void printMagazines(){
    int countMagazine = 0;
    for(int i =0; i < publicationsNumber; i++){
      PublicationPtr ptr = publications[i];
      if(dynamic_cast<Magazine*>(ptr.get())){
        ptr->printInfo();
        countMagazine++;
      }
    }
    if(countMagazine == 0){
      cout << "Brak gazet w bibliotece" << endl;
    }
  }
};
