//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when a data import error occurs.*/
class DataImportException : public std::exception{
public:
  const char* what() {
    return "Blad importu pliku.";
  }
};