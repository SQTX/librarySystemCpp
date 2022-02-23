//
// Created by Jakub Sitarczyk on 03/01/2022.
//
/*Headers*/
#include "../include/main_h.h"

class NoSuchOptionException : public exception{
public:
  const char* what() {
    return "Nie istnieje opcja dla wartości ";
  }
};