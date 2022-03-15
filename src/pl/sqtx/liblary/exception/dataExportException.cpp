//
// Created by Jakub Sitarczyk on 15/02/2022.
//
/*Headers*/
#include "../include/main_h.h"

class DataExportException : public std::exception{
public:
  const char* what() {
    return "Blad eksportu pliku.";
  }
};