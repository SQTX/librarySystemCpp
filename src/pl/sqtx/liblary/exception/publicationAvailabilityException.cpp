//
// Created by Jakub Sitarczyk on 12/04/2022.
//
#include "../include/main_h.h"

class PublicationAvailabilityException : public std::exception{
public:
  const char* what() {
    return "Podana publikacja ";
  }
};
