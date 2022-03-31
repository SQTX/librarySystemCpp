//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_BORROWENGINE_H
#define LIBRARYSYSTEM_BORROWENGINE_H

#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../io/dataReader.h"
#include "../include/publicationType_h.h"
#include "../model/BorrowedPublications.h"
#include "../model/users/user.h"
#include "../model/library.h"
#include "../model/libraryUser.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class borrowEngine {
private:
  consolePrinter cslPrinter;
  dataReader dataReader;

  int findUser(libraryUser *libraryUser);

  int findPublication(library *library);
public:
  void borrowPublication(library *library, libraryUser *libraryUser);

  void returnPublication(library *library, libraryUser *libraryUser);

  void printUserHistory(libraryUser *libraryUser);
};

#endif //LIBRARYSYSTEM_BORROWENGINE_H
