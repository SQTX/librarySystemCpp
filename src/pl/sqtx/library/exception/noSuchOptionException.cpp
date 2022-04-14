//
// Created by Jakub Sitarczyk on 03/01/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when the options selected by the user do not exist.*/
class NoSuchOptionException : public std::exception{
public:
  const char* what() {
    return "Nie istnieje opcja dla wartosci ";
  }
};