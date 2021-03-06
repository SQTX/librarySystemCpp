//
// Created by Jakub Sitarczyk on 12/04/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when the publication doesn't exist*/
class PublicationNotExistException : public std::exception{
public:
  const char* what() {
    return "Publikacja nie widnieje w bazach danych";
  }
};

