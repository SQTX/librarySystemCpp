//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_CONSOLEPRINTER_H
#define LIBRARYSYSTEM_CONSOLEPRINTER_H

/*Libraries*/
#include <iostream>
//Headers
#include "../include/main_h.h"
#include "../include/publicationType_h.h"
#include "../model/publication.h"
#include "../include/sortData_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;
//*********************************************************************************************************************
class consolePrinter{
  sortByTitle sort;   //Sorting by WHAT <---- choose options
public:
  //  Print all books from database -----------------------------------------------------------------------------
  void printBooks(std::vector<PublicationPtr> &publications);

  //  Print all magazines from database ------------------------------------------------------------------------
  void printMagazines(std::vector<PublicationPtr> &publications);

//  Print text ------------------------------------------------------------------------------------------
  static void printLine(std::string txt);
};

#endif //LIBRARYSYSTEM_CONSOLEPRINTER_H
