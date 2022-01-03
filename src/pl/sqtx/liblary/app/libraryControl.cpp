//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#include "../io/dataReader.cpp"
#include "../include/library_h.h"
#include "option.cpp"

typedef shared_ptr<Publication> PublicationPtr;
class LibraryControl{
private:
  DataReader dataReader;  //dataReader.cpp
  Library library;  //library.cpp

public:
//  Main method
  void controlLoop(){
    Option option;
    int choice;
    do{
      printOptions(option);
      choice = dataReader.getInt();
      switch(choice) {
        case option.ADD_BOOK:
          addBook();
          break;
        case option.ADD_MAGAZINE:
          addMagazine();
          break;
        case option.PRINT_BOOKS:
          printBooks();
          break;
        case option.PRINT_MAGAZINES:
          printMagazines();
          break;
        case option.EXIT:
          exit();
          break;
        default:
          cout << "Wybrana opcja nie istnieje wprowadz ponownie inna." << endl;
      }
    }while (choice != option.EXIT);
  }

private:
  void printOptions(Option option){
    cout << "Wybierz opcję: " << endl;
    for(int i = 0; i < option.getOptionsSize(); i++){
      cout << option.toString(i) << endl;
    }
  }

  void addBook(){
  PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
  library.addBook(book);
  }

  void addMagazine(){
    PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
        library.addMagazine(magazine);
  }

  void printBooks(){
    library.printBooks();
  }

  void printMagazines(){
    library.printMagazines();
  }

  void exit(){
    cout << "Koniec programu" << endl;
  }
};