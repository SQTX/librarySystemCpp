//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_DATAREADER_H
#define LIBRARYSYSTEM_DATAREADER_H

#include "../include/main_h.h"
#include "../io/consolePrinter.h"
#include "../include/exception_h.h"
#include "../include/publicationType_h.h"
#include "../model/users/Person.h"
#include "../model/users/User.h"

class dataReader {
private:
  consolePrinter cslPrinter;
public:
//  Get from user ****************************************************
//  Get int num
  int getInt();
//  Get char
  char getChar();
//  Get all line of text
  std::string getTextLine();

//  For publications *************************************************
//  Get informations about new book and create it
  Book readAndCreateBook();
//  Get informations about new magazine and create it
  Magazine readAndCreateMagazine();

// For person ******************************************************
// Get informations about new person and create it
  Person readAndCreatePerson();
//  Create new user
  User readAndCreateUser();
};

#endif //LIBRARYSYSTEM_DATAREADER_H
