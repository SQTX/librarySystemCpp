//
// Created by Jakub Sitarczyk on 06/05/2022.
//

#include "../include/main_h.h"

/**The exception that occurs when the user doesn't exist*/
class wrongClosingFirstSessionException : public std::exception{
public:
  const char* what() {
    return "W pierwszej sesji aplikacja zostala niepoprawnie zamknieta, przez co zmiany nie zostaly zapisane.";
  }
};