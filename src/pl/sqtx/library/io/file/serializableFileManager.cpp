//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "serializableFileManager.h"

using namespace std;

// IMPORT=================================================================
//Publications
void serializableFileManager::importData(library *library, libraryUser *libraryUser) {
  bool importPublicationFlag = false, importUserFlag = false;
  try {
    DataImportException impErr;
    importUserFlag = usersData.importUsers(libraryUser, MAX_CHAR, &dataFile, &position);
    if (importUserFlag)
      importPublicationFlag = publicationsData.importPublications(library, MAX_CHAR, &dataFile, &position, libraryUser);
    if (importUserFlag && importPublicationFlag)
      cslPrinter.printLine("Baza danych publikacji zostala pomyslnie zainportowana.");
    else throw impErr;
  } catch (DatabaseNotExistException databaseNotExistException) {
    cslPrinter.printLine(databaseNotExistException.what());
    dataFile.open("../src/pl/sqtx/library/data/dataBase.txt", ios::out);
    if (dataFile.is_open()) {
      cslPrinter.printLine("Zainicjalizowano nowa baze danych.");
      dataFile.close();
    } else {
      cslPrinter.printLine("Stworzenie nowej bazy danych jest niemozliwe.");
    }
  } catch (wrongClosingFirstSessionException wrongLastExit) {
    cslPrinter.printLine(wrongLastExit.what());
    dataFile.open("../src/pl/sqtx/library/data/dataBase.txt", ios::out);
    if(dataFile.is_open()){
      dataFile << "[Users]\n";
      dataFile << "0\n";
      dataFile << "[Publications]\n";
      dataFile << "0";
    }
    dataFile.close();
    cslPrinter.printLine("Zainicjalizowano nowa baze danych.");
  } catch (DataImportException impErr) {
    cslPrinter.printLine(impErr.what());
  }
}

// EXPORT=================================================================
//Publications
void serializableFileManager::exportData(library *library, libraryUser *libraryUser) {
  bool exportPublicationFlag = false, exportUserFlag = false;
  position = 0; //Reset
  try {
    DataExportException err;
    exportUserFlag = usersData.exportUsers(libraryUser, MAX_CHAR, &dataFile, &position);
    if (exportUserFlag)
      exportPublicationFlag = publicationsData.exportPublications(library, MAX_CHAR, &dataFile, &position);
    if (exportUserFlag && exportPublicationFlag)
      cslPrinter.printLine("Zapis zakonczony powodzeniem.");
    else throw err;
  } catch (DataExportException err) {
    string message = err.what();
    cslPrinter.printLine("Blad zapisu.");
    cslPrinter.printLine(message);
  }

}