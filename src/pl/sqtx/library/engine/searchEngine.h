//
// Created by Jakub Sitarczyk on 20/04/2022.
//

#ifndef LIBRARYSYSTEM_SEARCHENGINE_H
#define LIBRARYSYSTEM_SEARCHENGINE_H

#include "../include/main_h.h"
#include "../include/exception_h.h"
#include "../io/dataReader.h"
#include "../io/consolePrinter.h"
#include "../model/library.h"
#include "../model/libraryUser.h"

class searchEngine {
private:
  dataReader dataReader;
//  --- Find-functions ---
  int findUser(libraryUser *libraryUser, std::string txt, int lastIteratorIndex);  //Find user and return iterator
  int findPublication(library *library, std::string txt, int lastIteratorIndex);   //Find publication and return iterator

public:
  /**Get the searched data from the user and send the data to the search functions.*/
  void searchEng(library *library, libraryUser *libraryUser);
};

#endif //LIBRARYSYSTEM_SEARCHENGINE_H
