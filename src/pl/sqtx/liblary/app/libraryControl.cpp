//
// Created by Jakub Sitarczyk on 09/12/2021.
//
#include "../io/dataReader.cpp"
#include "../model/library.cpp"

class LibraryControl{
private:
//  Variables to switch
  static const int EXIT = 0;
  static const int ADD_BOOK = 1;
  static const int PRINT_BOOKS = 2;
//  Create objects
  DataReader dataReader;  //dataReader.cpp
  Library library;  //library.cpp

public:
//  Main method
  void controlLoop(){
    int option;

    do{
      printOptions();
      option = dataReader.getInt();
      switch(option) {
        case ADD_BOOK:
          addBook();
          break;
        case PRINT_BOOKS:
          printBooks();
          break;
        case EXIT:
          exit();
          break;
        default:
          cout << "Wybrana opcja nie istnieje wprowadz ponownie inna." << endl;
      }
    }while (option != EXIT);
  }

private:
  void printOptions(){
    cout << "Wybierz opcję: " << endl;
    cout << EXIT << " - wyjście z programu" << endl;
    cout << ADD_BOOK << " - dodanie nowej książki" << endl;
    cout << PRINT_BOOKS << " - wyświetl dostępne książki" << endl;
  }

  void addBook(){
  Book book = dataReader.readAndCreateBook();
  library.addBook(book);
  }

  void printBooks(){
    library.printBooks();
  }

  void exit(){
    cout << "Koniec programu" << endl;
  }
};