//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_BORROWENGINE_H
#define LIBRARYSYSTEM_BORROWENGINE_H

#include "../include/main_h.h"
#include "../io/consolePrinter.h"
#include "../io/dataReader.h"
#include "../include/publicationType_h.h"
#include "../model/users/Person.h"
#include "../model/library.h"
#include "../model/libraryUser.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class borrowEngine {
private:
  consolePrinter cslPrinter;
  dataReader dataReader;
  /**Function that searches the database to find the wanted user. Returns the index of the main vector iterator.*/
  int findUser(libraryUser *libraryUser);
  /**Function that searches the database to find the wanted publication. Returns the index of the main vector iterator.*/
  int findPublication(library *library, bool loanStatus, std::string userPesel);

public:
  /**Function searching for the searched user and publication.
   * Get the current time, create a new HistoryElement, and borrow it to the user.*/
  void borrowPublication(library *library, libraryUser *libraryUser);
  /**Function searching for the searched user and publication. Returns the provided item and assigns a return date.*/
  void returnPublication(library *library, libraryUser *libraryUser);
  /**Looks for a specific user and sends its iterator to the history printing class.*/
  void printUserHistory(libraryUser *libraryUser);
};

#endif //LIBRARYSYSTEM_BORROWENGINE_H
