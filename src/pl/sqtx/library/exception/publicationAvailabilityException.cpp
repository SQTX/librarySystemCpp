//
// Created by Jakub Sitarczyk on 12/04/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when a publication availability error occurs.*/
class PublicationAvailabilityException : public std::exception{
public:
  const char* what() {
    return "Podana publikacja ";
  }
};
