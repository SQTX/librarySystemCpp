//
// Created by Jakub Sitarczyk on 15/02/2022.
//
#include "../../include/main_h.h"
#include "../../include/exception_h.h"
#include "../../include/library_h.h"
#include "../../include/consolePriner_h.h"
#include "../../include/publicationType_h.h"
//#include "../../include/fileManagers_h.h"
#include "fileManager.cpp"
#include <cstdio>
#include <fstream>

class SerializableFileManager /*: public FileManager*/{
  const short MAX_CHAR = 50;
  ConsolePrinter cslPrinter;
  fstream dataFile;
public:
  void importData(Library library) /*override*/{
    try{
      DataImportException err;

      dataFile.open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::in);
      if(dataFile.is_open()){
        int publicationData;
        dataFile >> publicationData;
        for(int i = 0; i < publicationData; i++){
          //Book;Tytuł;Autor;Wydawca;ISBN;dataWydania;liczbaStron
//          Get type
          char type[MAX_CHAR];
          dataFile.get(type, MAX_CHAR, ';');
          dataFile.ignore(1);
//          If type
          if(strcmp(type, "Book")){
//            Standard types
            int releaseDate = 0;
            int pages = 0;
//            Import all data
            char c_title[MAX_CHAR];
            dataFile.get(c_title, MAX_CHAR, ';');
            string title(c_title);
            dataFile.ignore(1);
            char c_author[MAX_CHAR];
            dataFile.get(c_author, MAX_CHAR, ';');
            string author(c_author);
            author = c_author;
            dataFile.ignore(1);
            char c_publisher[MAX_CHAR];
            dataFile.get(c_publisher, MAX_CHAR, ';');
            string publisher(c_publisher);
            dataFile.ignore(1);
            char c_isbn[MAX_CHAR];
            dataFile.get(c_isbn, MAX_CHAR, ';');
            string isbn (c_isbn);
            dataFile.ignore(1);
            char c_releaseDate[MAX_CHAR];
            dataFile.get(c_releaseDate, MAX_CHAR, ';');
            sscanf(c_releaseDate, "%d", &releaseDate);
            char c_pages[MAX_CHAR];
            dataFile.ignore(1);
            dataFile.get(c_pages, MAX_CHAR, '\n');
            sscanf(c_pages, "%d", &pages);//Last element

            string txt = title + " ; " +  author + " ; " + to_string(releaseDate) + " ; " + to_string(pages)+
                " ; " + publisher + " ; " + isbn;
            cslPrinter.printLine(txt);
//            Create object
            Book bookObj(title, author, releaseDate, pages, publisher, isbn);
            PublicationPtr book = make_shared<Book>(bookObj);
            library.addBook(book);
            cslPrinter.printBooks(library.getPublications());
            library.setPublications()
          }
          //TODO if sprawdzający typ publikacji i przekazywanie obiektu danego typu do funkcji liblary.addSTH
        }



        cslPrinter.printLine("Baza danych została zainportowana pomyślnie.");
      }else{  //Plik nieistnieje, próba stworzenia nowego
        dataFile.open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);
        cslPrinter.printLine("Brak bazy danych.");
        if(dataFile.is_open())
          cslPrinter.printLine("Zainicjalizowano nową baze danych.");
        else{
          cslPrinter.printLine("Stworzenie nowej bazy danych jest niemożliwe.");
          throw err;
        }
      }
    }catch(DataImportException err) {
      string message = err.what();
      cslPrinter.printLine(message);
    }
    dataFile.close();
  }
};
