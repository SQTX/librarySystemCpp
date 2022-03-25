//
// Created by Jakub Sitarczyk on 10/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARYCONTROL_H
#define LIBRARYSYSTEM_LIBRARYCONTROL_H

/*Files*/
#include "../io/dataReader.h"
//Headers
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../include/library_h.h"
#include "../include/exception_h.h"
#include "../model/publications/publication.h"
#include "../include/publicationType_h.h"
#include "../model/users/user.h"
#include "../model/libraryUser.h"
#include "../io/file/serializableFileManager.h"  //Import/Export data

class libraryControl {
private:
  dataReader dataReader;  //dataReader.cpp
  consolePrinter cslPrinter;  //consolePrinter.cpp
  serializableFileManager srlFileManager; //serializableFileManager.cpp
  library library;  //library.cpp
  libraryUser libraryUser;  //libraryUser.cpp
public:
//  Main function
  void controlLoop();

private:
  int getChoice();

//  Print all options in numbered list
  void printOptions();

//  Add publications
  void addBook();

  void addMagazine();

//  Print publications
  void printBooks();

  void printMagazines();

//  Remove publications
  void removeBook();

  void removeMagazine();

//  users functions
  void addUser();

  void printUsers();

//  Exit
  void exit();
};
//  Class Options =====================================================================================================
namespace options {
  class Option {
  public:
//  All options and his number
    enum option {
      EXIT = 0,
      ADD_BOOK,
      ADD_MAGAZINE,
      PRINT_BOOKS,
      PRINT_MAGAZINES,
      REMOVE_BOOK,
      REMOVE_MAGAZINE,
      ADD_USER,
      PRINT_USERS,
      END //Last element (Enum_size = END-1)
    };
    int optionsSize = option::END;
//  Key(enum-number)-Descriptions
    std::map<unsigned int, const std::string> MyMap{
        {EXIT,            "wyjście z programu"},
        {ADD_BOOK,        "dodanie nowej książki"},
        {ADD_MAGAZINE,    "dodanie nową gazete"},
        {PRINT_BOOKS,     "wyświetl dostępne książki"},
        {PRINT_MAGAZINES, "wyświetl dostępne gazety"},
        {REMOVE_BOOK,     "usuń książkę"},
        {REMOVE_MAGAZINE, "usuń gazetę"},
        {ADD_USER,        "dodaj użytkownika"},
        {PRINT_USERS,     "wyświetl dostępnych użytkowników"},
    };

//    Return enum option size
    int getOptionsSize() const;

//    Return option map
    const std::map<unsigned int, const std::string> &getMyMap() const;

//    Return oneline text ready to print
    std::string toString(int value);
  };
}

#endif //LIBRARYSYSTEM_LIBRARYCONTROL_H
