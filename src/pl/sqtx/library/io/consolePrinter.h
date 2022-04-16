//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_CONSOLEPRINTER_H
#define LIBRARYSYSTEM_CONSOLEPRINTER_H

#include <iostream>
#include "../include/main_h.h"
#include "../include/sortData_h.h"
#include "../include/publicationType_h.h"
#include "../model/publications/publication.h"
#include "../model/users/User.h"

typedef std::shared_ptr<Publication> PublicationPtr; //Defined PublicationPtr

class consolePrinter {
private:
  sortByTitle sort;   //Sorting by WHAT <---- choose options

public:
  /**Function that prints the passed string in the console.*/
  static void printLine(std::string txt);
  /**Function that prints all books from database.*/
  void printBooks(std::vector<PublicationPtr> &publications);
  /**Function that prints all magazines from database.*/
  void printMagazines(std::vector<PublicationPtr> &publications);
  /**Function that prints all users from database.*/
  void printUsers(std::vector<User> &users);
  /**Function that prints history of user.*/
  void printUserHistory(std::vector<User>::iterator users);
};

#endif //LIBRARYSYSTEM_CONSOLEPRINTER_H
