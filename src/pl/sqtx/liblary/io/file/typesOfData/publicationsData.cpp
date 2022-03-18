//
// Created by Jakub Sitarczyk on 17/03/2022.
//

#include "publicationsData.h"

using namespace std;

//Add hyphen in txt
string publicationsData::addHyphen(string txt) {
  string hyphen = ";";
  txt.append(hyphen);
  return txt;
}

//Import publications function
void publicationsData::importPublications(library *library, const char MAX_CHAR,
                                          fstream *dataFile) {
  try {
    DataImportException err;

    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::in); //Open data_file

    if (dataFile->is_open()) {
      dataFile->ignore(numeric_limits<streamsize>::max(), '\n');

//      Save publications data ****************************************
      int publicationDataSize;

      *dataFile >> publicationDataSize;  //Data size
      dataFile->ignore(1);

      for (int i = 0; i < publicationDataSize; i++) {
//          Get Publication type
        char c_type[MAX_CHAR];
        dataFile->get(c_type, MAX_CHAR, ';');
        dataFile->ignore(1);

//          Checking types and division
        string type(c_type);
//          If Book
//          Save standard: Book;Title;Author;ReleaseData;Pages;Publisher;ISBN
        if (type == "Book") {
//            Standard types
          int releaseDate = 0;
          int pages = 0;

//            Import all data
          char c_title[MAX_CHAR];
          dataFile->get(c_title, MAX_CHAR, ';');
          string title(c_title);
          dataFile->ignore(1);

          char c_author[MAX_CHAR];
          dataFile->get(c_author, MAX_CHAR, ';');
          string author(c_author);
          dataFile->ignore(1);

          char c_releaseDate[MAX_CHAR];
          dataFile->get(c_releaseDate, MAX_CHAR, ';');
          sscanf(c_releaseDate, "%d", &releaseDate);
          dataFile->ignore(1);

          char c_pages[MAX_CHAR];
          dataFile->get(c_pages, MAX_CHAR, ';');
          sscanf(c_pages, "%d", &pages);//Last element
          dataFile->ignore(1);

          char c_publisher[MAX_CHAR];
          dataFile->get(c_publisher, MAX_CHAR, ';');
          string publisher(c_publisher);
          dataFile->ignore(1);

          char c_isbn[MAX_CHAR];
          dataFile->get(c_isbn, MAX_CHAR, '\n');
          string isbn(c_isbn);
          dataFile->ignore(1);

//            Create object and add it to lib
          Book bookObj(title, author, releaseDate, pages, publisher, isbn);
          PublicationPtr book = make_shared<Book>(bookObj);
          library->addBook(book);

//           If Magazine
//           Save standard: Book;Title;Day;Month;ReleaseData;Language;Publisher
        } else if (type == "Magazine") {
//            Standard types
          int day = 0;
          int month = 0;
          int releaseDate = 0;

//            Import all data
          char c_title[MAX_CHAR];
          dataFile->get(c_title, MAX_CHAR, ';');
          string title(c_title);
          dataFile->ignore(1);

          char c_day[MAX_CHAR];
          dataFile->get(c_day, MAX_CHAR, ';');
          sscanf(c_day, "%d", &day);
          dataFile->ignore(1);

          char c_month[MAX_CHAR];
          dataFile->get(c_month, MAX_CHAR, ';');
          sscanf(c_month, "%d", &month);
          dataFile->ignore(1);

          char c_releaseDate[MAX_CHAR];
          dataFile->get(c_releaseDate, MAX_CHAR, ';');
          sscanf(c_releaseDate, "%d", &releaseDate);
          dataFile->ignore(1);

          char c_language[MAX_CHAR];
          dataFile->get(c_language, MAX_CHAR, ';');
          string language(c_language);
          dataFile->ignore(1);

          char c_publisher[MAX_CHAR];
          dataFile->get(c_publisher, MAX_CHAR, '\n');
          string publisher(c_publisher);
          dataFile->ignore(1);

//            Create object and add it to lib
          Magazine magazineObj(title, day, month, releaseDate, language, publisher);
          PublicationPtr magazine = make_shared<Magazine>(magazineObj);
          library->addMagazine(magazine);

        } else {
          cslPrinter.printLine("Nieznany typ publikacji.");
        }
      }
//        Succesfulle import
      cslPrinter.printLine("Baza danych została pomyślnie zainportowana.");
      dataFile->close();

    } else {
//        If the database file doesn't exist, it tries to create a new one
      dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);
      cslPrinter.printLine("Brak bazy danych.");
      if (dataFile->is_open()) {
        cslPrinter.printLine("Zainicjalizowano nową baze danych.");
        dataFile->close();
      } else {
        cslPrinter.printLine("Stworzenie nowej bazy danych jest niemożliwe.");
        throw err;
      }
    }
  } catch (DataImportException err) {
    string message = err.what();
    cslPrinter.printLine(message);
  }
}

//Export publications function
void publicationsData::exportPublications(library *library, const char MAX_CHAR,
                                         fstream *dataFile) {
  try {
    DataExportException err;
    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);  //Open data_file

    if (dataFile->is_open()) {

//      Save publications data ****************************************
      *dataFile << "[Publications]\n";
//        Get vector from lib
      vector<PublicationPtr> publications = library->getPublications();

//        Get database size
      int publicationsNum = publications.size();
//        Empty library
      if (publicationsNum <= 0) {
        *dataFile << '0';
        dataFile->close();
      } else {
        *dataFile << publicationsNum;
        for (int i = 0; i < publicationsNum; i++) {
          string saveLine;
          PublicationPtr ptr = publications[i];

//            Division into types
          if (dynamic_cast<Book *>(ptr.get())) {
            saveLine = "\nBook";
            saveLine = addHyphen(saveLine);
            saveLine.append(ptr->toSave());
          } else if (dynamic_cast<Magazine *>(ptr.get())) {
            saveLine = "\nMagazine";
            saveLine = addHyphen(saveLine);
            saveLine.append(ptr->toSave());
          }
          *dataFile << saveLine; //Export data
        }
        if (((dataFile->rdstate() ^ fstream::eofbit) == 0) || fstream::eofbit == 2) {
          dataFile->close();
          cslPrinter.printLine("Zapis zakończony powodzeniem.");
        }
      }
    }
  } catch (DataExportException err) {
    string message = err.what();
    cslPrinter.printLine("Błąd zapisy.");
    cslPrinter.printLine(message);
  }
}