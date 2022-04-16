//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARYUSER_H
#define LIBRARYSYSTEM_LIBRARYUSER_H

#include "../include/main_h.h"
#include "../io/consolePrinter.h"
#include "users/Person.h"
#include "users/User.h"

/** Class created to hold the users of this system */
class libraryUser {
private:
  std::vector<User> users;  // Main vector
  static const int maxUsers = 1000;  // Limit of users
  int usersNumber = 0;
public:
//  --- Getters ---
  const std::vector<User> &getUsersVector() const;
  std::vector<User>::iterator &getIteratorUsers();
  /**Method that adds a new system user to the vector (database).*/
  void addUser(User user);
};

#endif //LIBRARYSYSTEM_LIBRARYUSER_H
