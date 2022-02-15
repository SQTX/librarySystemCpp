//
// Created by Jakub Sitarczyk on 15/02/2022.
//
#include "../../include/main_h.h"
#include "../../include/exception_h.h"
#include "../../include/library_h.h"
#include "../../include/consolePriner_h.h"
//#include "../../include/fileManagers_h.h"
#include "fileManager.cpp"
#include <fstream>

class SerializableFileManager /*: public FileManager*/{
  ConsolePrinter cslPrinter;
  fstream dataFile;
public:
  void importData() /*override*/{
    try{
      DataImportException err;

      dataFile.open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::in);
      if(dataFile.is_open()){
        int publicationData;
        dataFile >> publicationData;
        for(int i = 0; i < publicationData; i++){
          //TODO if sprawdzający typ publikacji i przekazywanie obiektu danego typu do funkcji liblary.addSTH


          string title;
          dataFile >> title;
          string author;
          dataFile >> author;
          string publisher;
          dataFile >> publisher;
          string isbn;
          dataFile >> isbn;
          int releaseDate;
          dataFile >> releaseDate;
          int pages;
          dataFile >> pages;

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
