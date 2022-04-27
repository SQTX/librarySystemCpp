//
// Created by Jakub Sitarczyk on 15/03/2022.
//

#include "libraryUser.h"

using namespace std;

//Get vector
const vector<User> &libraryUser::getUsersVector() const {
  return users;
}

//Get iterator
vector<User>::iterator &libraryUser::getIteratorUsers(){
  static vector<User>::iterator it_users = users.begin(); //TODO: dodanie static dla windows'a
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
