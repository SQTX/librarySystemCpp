//
// Created by Jakub Sitarczyk on 10/03/2022.
//

#ifndef LIBRARYSYSTEM_LIBRARYCONTROL_H
#define LIBRARYSYSTEM_LIBRARYCONTROL_H

#include "../include/main_h.h"
#include "../include/exception_h.h"
#include "../io/consolePrinter.h"
#include "../io/dataReader.h"
#include "../engine/borrowEngine.h"
#include "../engine/searchEngine.h"
#include "../model/library.h"
#include "../model/publications/publication.h"
#include "../include/publicationType_h.h" //Types of publications
#include "../model/libraryUser.h" //Users base
#include "../model/users/Person.h"
#include "../model/users/User.h"
#include "../io/file/serializableFileManager.h"  //Import and export data

class libraryControl {
private:
  dataReader dataReader;  //dataReader.cpp
  consolePrinter cslPrinter;  //consolePrinter.cpp
  borrowEngine borrowEngine;  //borrowEngine.cpp
  serializableFileManager srlFileManager; //serializableFileManager.cpp
  library library;  //library.cpp
  libraryUser libraryUser;  //libraryUser.cpp
  searchEngine searchEngine;  //searchEngine.cpp
public:
  /**Pętla główna z przełącznikami opcji.*/
  void controlLoop();
private:
  /**Get an option from the user and check if it exists.*/
  int getChoice();
  /**Printout of all available options.*/
  void printOptions();
//  --- Publications functions ---
  /**A call to a function that retrieves the data needed for writing.
   * Create new object na add it to library base.*/
  void addBook();
  void addMagazine();
  /**Print all publications in sorted order.*/
  void printBooks();
  void printMagazines();
  /**Creates a new object whose data must be identical to the one being deleted.
   * Checks for similarity and removes from database.*/
  void removeBook();
  void removeMagazine();
//  --- Users functions ---
  /**Creates a new user and adds him to the database.*/
  void addUser();
  /**Print all users in sorted order.*/
  void printUsers();
//  --- Borrow system ---
  /**Gets data about the user and publication. If everything is correct, it lends to him.*/
  void borrowPublication();
  /**Gets data about the user and publication. If everything is correct, it returns the publication*/
  void returnPublication();
  /**Looks for a given user and displays his history.*/
  void historyOfUser();
//  --- Search engine ---
  /**A function that searches data in the database. When it finds any, displays them.*/
  void searchEngi();
//  EXIT
  /**A function to end the main loop, import the data, and exit*/
  void exit();
};
//  ===== Subclass Options ===============================================================================================
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
      BORROW_PUBLICATION,
      RETURN_PUBLICATION,
      HISTORY_OF_USER,
      SEARCH_ENGINE,
      END //Last element (Enum_size = END-1)
    };
    int optionsSize = option::END;
    std::map<unsigned int, const std::string> MyMap{
//      Key(enum-number)-Descriptions
        {EXIT,                "wyjscie z programu"},
        {ADD_BOOK,            "dodanie nowej ksiazki"},
        {ADD_MAGAZINE,        "dodanie nowa gazete"},
        {PRINT_BOOKS,         "wyswietl dostepne ksiazki"},
        {PRINT_MAGAZINES,     "wyswietl dostepne gazety"},
        {REMOVE_BOOK,         "usun ksiazke"},
        {REMOVE_MAGAZINE,     "usun gazete"},
        {ADD_USER,            "dodaj uzytkownika"},
        {PRINT_USERS,         "wyswietl dostepnych uzytkownikow"},
        {BORROW_PUBLICATION,  "wypozycz publikacje"},
        {RETURN_PUBLICATION,  "zwroc publikacje"},
        {HISTORY_OF_USER,     "historia wypozyczen uzytkownika"},
        {SEARCH_ENGINE,       "wyszukaj"},
    };

//    Return enum option size
    int getOptionsSize() const;

//    Return option map
    const std::map<unsigned int, const std::string> &getMyMap() const;

//    Return one line text ready to print
    std::string toString(int value);
  };
}

#endif //LIBRARYSYSTEM_LIBRARYCONTROL_H
