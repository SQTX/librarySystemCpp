//
// Created by Jakub Sitarczyk on 15/02/2022.
//
#include "../include/main_h.h"

class DataExportException : exception{
public:
  static const string what(string message) {
    return message;
  }
};