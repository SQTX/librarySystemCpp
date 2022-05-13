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
  void isbnCheck(std::string isbn);
public:
//  --- Letter transform ---
  std::string toLowerCase(std::string);  //To lower case
//  --- Get data from user ---
  int getInt(); //Get int num
  char getChar(); //Get char
  std::string getTextLine();  //Get all line of text

//  --- For publications ---
  /**Get informations about new book and create it.*/
  Book readAndCreateBook();
  /**Get informations about new magazine and create it.*/
  Magazine readAndCreateMagazine();

// --- For person ---
  /**Get informations about new person and create it.*/
  Person readAndCreatePerson();
  /**Create new user.*/
  User readAndCreateUser();
};

#endif //LIBRARYSYSTEM_DATAREADER_H
