//
// Created by Jakub Sitarczyk on 18/03/2022.
//

#ifndef LIBRARYSYSTEM_USERSDATA_H
#define LIBRARYSYSTEM_USERSDATA_H

#include <cstdio>
#include <fstream>
#include "../../../include/main_h.h"
#include "../../consolePrinter.h"
#include "../../../include/exception_h.h"
#include "../../../model/libraryUser.h"
#include "../../../model/users/Person.h"
#include "../../../model/users/User.h"
#include "../../../model/publications/HistoryElement.h"

/*Functions saving and downloading users from the database*/
class usersData {
private:
  consolePrinter cslPrinter;
//  Create errors
  DataImportException impErr;
  DataExportException expErr;
  const unsigned char MAX_PESEL_CHAR = 11;

public:
  /**Function that imports user into the main vector that stores
   * users in the libraryUser.cpp class.*/
  bool importUsers(libraryUser *libraryUser, const char MAX_CHAR, std::fstream *dataFile, int *position);

  /**Function that export users from the main vector that stores
   * users in the libraryUser.cpp class into dataBase file.*/
  bool exportUsers(libraryUser *libraryUser, const char MAX_CHAR, std::fstream *dataFile, int *position);
};

#endif //LIBRARYSYSTEM_USERSDATA_H