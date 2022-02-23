//
// Created by Jakub Sitarczyk on 03/01/2022.
//
/*Libraries*/
#include <iostream>
//Headers
#include "../include/main_h.h"
#include "../include/publication_h.h"
#include "../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;
//*********************************************************************************************************************
class ConsolePrinter{
public:
  //  Print all books from database
  void printBooks(vector<PublicationPtr> publications){
    int countBooks = 0;
    for(int i =0; i < publications.size(); i++){
      PublicationPtr ptr = publications[i];
      if(dynamic_cast<Book*>(ptr.get())){ //Checking if the Publication is a Book
        cout << ptr->toString() << endl;
        countBooks++;
      }
    }
    if(countBooks == 0){
      printLine("Brak ksiazek w bibliotece");
    }
  }

  //  Print all magazines from database
  void printMagazines(vector<PublicationPtr> publications){
    int countMagazine = 0;
    for(int i =0; i < publications.size(); i++){
      PublicationPtr ptr = publications[i];
      if(dynamic_cast<Magazine*>(ptr.get())){ //Checking if the Publication is a Magazine
        cout << ptr->toString() << endl;
        countMagazine++;
      }
    }
    if(countMagazine == 0){
      printLine("Brak gazet w bibliotece");
    }
  }

//  Print text
  static void printLine(string txt){
    cout << txt << endl;
  }
};