//
// Created by Jakub Sitarczyk on 17/03/2022.
//
#include "publicationsData.h"

using namespace std;

//Import publications function ****************************************************************************************
bool publicationsData::importPublications(library *library, const char MAX_CHAR,
                                          fstream *dataFile, int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataImportException err;  //Create error

    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::in); //Open data_file

//    File opens good =========================================================================================
    if (dataFile->is_open()) {
      dataFile->seekg(actualPosition);  //Set actualy position of file cursor

      dataFile->ignore(numeric_limits<streamsize>::max(), '\n');  //Ignore first line - [Publications]

//      Lets save
      int publicationDataSize;
      *dataFile >> publicationDataSize; //Get publications number
      dataFile->ignore(1);

//      Create all object form database
      for (int i = 0; i < publicationDataSize; i++) {
//        Get Publication type [book/magazine]
        char c_type[MAX_CHAR];
        dataFile->get(c_type, MAX_CHAR, ';');
        dataFile->ignore(1);

//        Checking types
        string type(c_type);
//        Book --------------------------------------------------------------------------------------------------------
        if (type == "Book") {
//          Save standard: Book;Title;Author;ReleaseData;Pages;Publisher;ISBN;isLoan;currentlyOwner

//          Get data from file and create new obejct of them
          char c_title[MAX_CHAR];
          dataFile->get(c_title, MAX_CHAR, ';');
          string title(c_title);
          dataFile->ignore(1);

          char c_author[MAX_CHAR];
          dataFile->get(c_author, MAX_CHAR, ';');
          string author(c_author);
          dataFile->ignore(1);

          int releaseDate = 0;
          char c_releaseDate[MAX_CHAR];
          dataFile->get(c_releaseDate, MAX_CHAR, ';');
          sscanf(c_releaseDate, "%d", &releaseDate);
          dataFile->ignore(1);

          int pages = 0;
          char c_pages[MAX_CHAR];
          dataFile->get(c_pages, MAX_CHAR, ';');
          sscanf(c_pages, "%d", &pages);//Last element
          dataFile->ignore(1);

          char c_publisher[MAX_CHAR];
          dataFile->get(c_publisher, MAX_CHAR, ';');
          string publisher(c_publisher);
          dataFile->ignore(1);

          char c_isbn[MAX_CHAR];
          dataFile->get(c_isbn, MAX_CHAR, ';');
          string isbn(c_isbn);
          dataFile->ignore(1);

          bool isLoan;
          char c_isLoan[MAX_CHAR];
          dataFile->get(c_isLoan, MAX_CHAR, ';');
          int flag;
          sscanf(c_isLoan, "%d", &flag);
          if (flag == 1) {
            isLoan = true;
          } else {
            isLoan = false;
          }
          dataFile->ignore(1);

          char c_currentlyOwner[MAX_CHAR];
          dataFile->get(c_currentlyOwner, MAX_CHAR, '\n');
          string currentlyOwner(c_currentlyOwner);
          dataFile->ignore(1);

//          Create object and add it to library vector
          Book bookObj(title, author, releaseDate, pages, publisher, isbn);
          bookObj.setIsLoan(isLoan);
          bookObj.setCurrentlyOwns(currentlyOwner);
          PublicationPtr book = make_shared<Book>(bookObj);
//          book.get()->setIsLoan(isLoan);
          library->addBook(book);

//        Magazine --------------------------------------------------------------------------------------------------------
        } else if (type == "Magazine") {
//          Save standard: Book;Title;Day;Month;ReleaseData;Language;Publisher

//          Get data from file and create new obejct of them
          char c_title[MAX_CHAR];
          dataFile->get(c_title, MAX_CHAR, ';');
          string title(c_title);
          dataFile->ignore(1);

          int day = 0;
          char c_day[MAX_CHAR];
          dataFile->get(c_day, MAX_CHAR, ';');
          sscanf(c_day, "%d", &day);
          dataFile->ignore(1);

          int month = 0;
          char c_month[MAX_CHAR];
          dataFile->get(c_month, MAX_CHAR, ';');
          sscanf(c_month, "%d", &month);
          dataFile->ignore(1);

          int releaseDate = 0;
          char c_releaseDate[MAX_CHAR];
          dataFile->get(c_releaseDate, MAX_CHAR, ';');
          sscanf(c_releaseDate, "%d", &releaseDate);
          dataFile->ignore(1);

          char c_language[MAX_CHAR];
          dataFile->get(c_language, MAX_CHAR, ';');
          string language(c_language);
          dataFile->ignore(1);

          char c_publisher[MAX_CHAR];
          dataFile->get(c_publisher, MAX_CHAR, ';');
          string publisher(c_publisher);
          dataFile->ignore(1);

          bool isLoan;
          char c_isLoan[MAX_CHAR];
          dataFile->get(c_isLoan, MAX_CHAR, ';');
          cout << c_isLoan << endl;
          int flag;
          sscanf(c_isLoan, "%d", &flag);
          if (flag == 1) {
            isLoan = true;
          } else {
            isLoan = false;
          }
          dataFile->ignore(1);

          char c_currentlyOwner[MAX_CHAR];
          dataFile->get(c_currentlyOwner, MAX_CHAR, '\n');
          string currentlyOwner(c_currentlyOwner);
          dataFile->ignore(1);

//          Create object and add it to library vector
          Magazine magazineObj(title, day, month, releaseDate, language, publisher);
          magazineObj.setIsLoan(isLoan);
          magazineObj.setCurrentlyOwns(currentlyOwner);
          PublicationPtr magazine = make_shared<Magazine>(magazineObj);
          library->addMagazine(magazine);

//        Noname type ----------------------------------
        } else {
          cslPrinter.printLine("Nieznany typ publikacji.");
        }
      }
//      Succesfulle import =========================================================================================
      actualPosition = dataFile->tellg(); //Get actualy position of file cursor
      *position = actualPosition;
//      Close file and print message
      dataFile->close();
      return 1;

//      File opens fail ============================================================================================
    } else {
//      If the database file doesn't exist, it tries to create a new one
      cslPrinter.printLine("Brak bazy danych.");
      dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);
      if (dataFile->is_open()) {
        cslPrinter.printLine("Zainicjalizowano nowa baze danych.");
        dataFile->close();
        return 0;
      } else {
        cslPrinter.printLine("Stworzenie nowej bazy danych jest niemozliwe.");
        throw err;
      }
      return 0;
    }
  } catch (DataImportException err) {
    string message = err.what();
    cslPrinter.printLine(message);
  }
}

//Export publications function ****************************************************************************************
bool publicationsData::exportPublications(library *library, const char MAX_CHAR,
                                          fstream *dataFile, int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataExportException err;
    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);  //Open database

//    File opens good =========================================================================================
    if (dataFile->is_open()) {
      dataFile->seekp(actualPosition);

      *dataFile << "[Publications]\n";  //Set sepparator

//      Get data from library.cpp
      vector<PublicationPtr> publications = library->getPublications(); //Get vector
      int publicationsNum = publications.size();  //Get database size

//      Lets export
      if (publicationsNum <= 0) {
        *dataFile << '0';
        dataFile->close();
        return 1;
      } else {
        *dataFile << publicationsNum; //Set publications number

        for (int i = 0; i < publicationsNum; i++) {
          string saveLine;
          PublicationPtr ptr = publications[i];

//          Division into types
          if (dynamic_cast<Book *>(ptr.get())) {
            saveLine = "\nBook;";
            saveLine.append(ptr->toSave());
          } else if (dynamic_cast<Magazine *>(ptr.get())) {
            saveLine = "\nMagazine;";
            saveLine.append(ptr->toSave());
          }
          *dataFile << saveLine; //Export data
        }
        if (((dataFile->rdstate() ^ fstream::eofbit) == 0) || fstream::eofbit == 2) {
          actualPosition = dataFile->tellp(); //Get actualy position of file cursor
          *position = actualPosition;
          dataFile->close();
          return 1;
        }
        return 0;
      }
      return 0;
    }
  } catch (DataExportException err) {
    string message = err.what();
    cslPrinter.printLine("Blad zapisu.");
    cslPrinter.printLine(message);
  }
}