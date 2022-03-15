//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_DATAREADER_H
#define LIBRARYSYSTEM_DATAREADER_H

/*Headers*/
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../include/publicationType_h.h"
#include "../model/user.h"

class dataReader {
  consolePrinter cslPrinter;
public:
  //  Get int-type number from user
  int getInt();

//  Get informations about new book and create it
  Book readAndCreateBook();

  //  Get informations about new magazine and create it
  Magazine readAndCreateMagazine();

//  User functions
//  Get informations about new user and create it
  User readAndCreateUser();
};

#endif //LIBRARYSYSTEM_DATAREADER_H
