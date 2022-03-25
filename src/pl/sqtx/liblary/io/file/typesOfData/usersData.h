//
// Created by Jakub Sitarczyk on 18/03/2022.
//

#ifndef LIBRARYSYSTEM_USERSDATA_H
#define LIBRARYSYSTEM_USERSDATA_H

/*Libraries*/
#include <cstdio>
#include <fstream>
//Headers
#include "../../../include/main_h.h"
#include "../../../include/consolePriner_h.h"
#include "../../../include/exception_h.h"
#include "../../../model/libraryUser.h"
#include "../../../model/users/user.h"

/*Functions saving and downloading users from the database*/
class usersData {
private:
  consolePrinter cslPrinter;
  const unsigned char MAX_PESEL_CHAR = 11;

public:
  /*Function that imports user into the main vector that stores
    users in the libraryUser.cpp class*/
  bool importUsers(libraryUser *libraryUser, const char MAX_CHAR,
                          std::fstream *dataFile, int *position);

  /*Function that export users from the main vector that stores
    users in the libraryUser.cpp class into dataBase file*/
  bool exportUsers(libraryUser *libraryUser, const char MAX_CHAR,
                          std::fstream *dataFile, int *position);
};

#endif //LIBRARYSYSTEM_USERSDATA_H