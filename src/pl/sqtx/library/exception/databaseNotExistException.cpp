//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when a data export error occurs.*/
class DatabaseNotExistException : public std::exception{
public:
  const char* what() {
    return "Baza danych nie istnieje.";
  }
};