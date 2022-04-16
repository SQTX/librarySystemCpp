//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "libraryUser.h"

using namespace std;

//Get vector
const std::vector<User> &libraryUser::getUsersVector() const {
  return users;
}

//Get iterator
std::vector<User>::iterator &libraryUser::getIteratorUsers(){
  vector<User>::iterator it_users = users.begin();
  return it_users;
}

//Add new user to base
void libraryUser::addUser(User user){
  if (usersNumber >= maxUsers) {
    throw out_of_range("Przekroczono dozwolony limit uzytkownikow w bazie.");
  } else {
    users.push_back(user);
    usersNumber++;
  }
}
