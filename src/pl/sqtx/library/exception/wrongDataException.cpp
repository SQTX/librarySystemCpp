//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when a data provided is wrong.*/
class wrongDataException : public std::exception{
public:
  const char* what(){
    return "Przekazano bledne dane.";
  }
};
