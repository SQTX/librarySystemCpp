//
// Created by Jakub Sitarczyk on 02/01/2022.
//
#include "../include/main_h.h"

class Option{
public:
//  Options
  enum option {
    EXIT = 0,
    ADD_BOOK,
    ADD_MAGAZINE,
    PRINT_BOOKS,
    PRINT_MAGAZINES,
    END
  };
private:
  int optionsSize = option::END;
//  Key-Descriptions
  map <unsigned int, const string> MyMap{
      {EXIT, "wyjście z programu"},
      {ADD_BOOK, "dodanie nowej książki"},
      {ADD_MAGAZINE, "dodanie nową gazete"},
      {PRINT_BOOKS, "wyświetl dostępne książki"},
      {PRINT_MAGAZINES, "wyświetl dostępne gazety"},
  };
public:
  int getOptionsSize() const {
    return optionsSize;
  }

  const map<unsigned int, const string> &getMyMap() const {
    return MyMap;
  }

  string toString(int value){
    return to_string(value) + " - " + MyMap[value];
  }
};
