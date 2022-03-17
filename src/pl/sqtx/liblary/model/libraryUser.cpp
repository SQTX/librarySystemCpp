//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "libraryUser.h"

using namespace std;

const std::vector<User> &libraryUser::getUsers() const {
  return users;
}

void libraryUser::addUser(User user){
  if (usersNumber >= maxUsers) {
    throw out_of_range("Przekroczono dozwolony limit użytkowników w bazie.");
  } else {
    users.push_back(user);
    usersNumber++;
  }
};
