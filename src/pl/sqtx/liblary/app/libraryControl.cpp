//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#include "../io/dataReader.cpp"
//Headers
#include "../include/main_h.h"
#include "../include/consolePriner_h.h"
#include "../include/library_h.h"
#include "../include/exception_h.h"
#include "../include/publicationType_h.h"
#include "../include/publication_h.h"

class LibraryControl{
private:
  DataReader dataReader;  //dataReader.cpp
  Library library;  //library.cpp
  ConsolePrinter cslPrinter;

public:
//  Main method
  void controlLoop(){
    Option option;
    int choice;
    do{
        choice = getChoice();
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
              cslPrinter.printLine("Nie ma takiej opcji, wprowadź ponownie: ");
          }
    }while (choice != option.EXIT);
  }

private:
  int getChoice() {
    Option option;
    ConsolePrinter cslPrinter;
    int choice = 0;
    bool choiceRight = false;
    do {
      printOptions();
      try {
        choice = dataReader.getInt();
        if (choice >= 0 && choice < option.END) {
          choiceRight = true;
        } else {
          NoSuchOptionException err;
          throw err;
        }
      }catch(NoSuchOptionException err) {
        choiceRight = false;
        string message = err.what()+to_string(choice);
        cslPrinter.printLine(message);
      }catch(invalid_argument err){
        cslPrinter.printLine(err.what());
      }
    } while (!choiceRight);
    return choice;
  }

  void printOptions(){
    Option option;
    cslPrinter.printLine("Wybierz opcję: ");
    for(int i = 0; i < option.getOptionsSize(); i++){
      cslPrinter.printLine(option.toString(i));
    }
  }

  void addBook(){
    try{
      PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
      library.addBook(book);
    }catch(invalid_argument err){
      string message = err.what();
      message.append(", piblikacja nie zostala dodana.");
      cslPrinter.printLine(message);
    }catch(out_of_range err){
      cslPrinter.printLine("Przekroczono dozwolony limit publikacji.");
    }
  }

  void addMagazine(){
    try{
      PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
      library.addMagazine(magazine);
    }catch(invalid_argument err){
      string message = err.what();
      message.append(", piblikacja nie zostala dodana.");
      cslPrinter.printLine(message);
    }catch(out_of_range err){
      cslPrinter.printLine("Przekroczono dozwolony limit publikacji.");
    }
  }

  void printBooks(){
    vector<PublicationPtr> publications = library.getPublications();
    cslPrinter.printBooks(publications);
  }

  void printMagazines(){
    vector<PublicationPtr> publications = library.getPublications();
    cslPrinter.printMagazines(publications);
  }

  void exit(){
    cslPrinter.printLine("Koniec programu");
  }

private:
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
    int optionsSize = option::END;
//  Key-Descriptions
    map <unsigned int, const string> MyMap{
        {EXIT, "wyjście z programu"},
        {ADD_BOOK, "dodanie nowej książki"},
        {ADD_MAGAZINE, "dodanie nową gazete"},
        {PRINT_BOOKS, "wyświetl dostępne książki"},
        {PRINT_MAGAZINES, "wyświetl dostępne gazety"},
    };
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
};