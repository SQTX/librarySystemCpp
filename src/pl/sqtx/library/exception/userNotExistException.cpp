//
// Created by Jakub Sitarczyk on 12/04/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when the user doesn't exist*/
class UserNotExistException : public std::exception{
public:
  const char* what() {
    return "Uzytkownik o podanych danych nie istnieje.";
  }
};
