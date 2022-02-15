//
// Created by Jakub Sitarczyk on 15/02/2022.
//
#include "../include/main_h.h"

class DataImportException : exception{
public:
  const char* what() {
    return "Blad importu pliku.";
  }
};