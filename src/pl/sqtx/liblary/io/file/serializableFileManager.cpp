//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "serializableFileManager.h"

using namespace std;

// IMPORT=================================================================
//Publications
void serializableFileManager::importData(library *library, libraryUser *libraryUser) {
  bool importPublicationFlag = false, importUserFlag = false;
  position = 0; //Reset
  importPublicationFlag = publicationsData.importPublications(library, MAX_CHAR, &dataFile, &position);
  if(importPublicationFlag) importUserFlag = usersData.importUsers(libraryUser, MAX_CHAR, &dataFile, &position);
  if(importPublicationFlag && importUserFlag) cslPrinter.printLine("Baza danych publikacji zostala pomyslnie zainportowana.");
}

// EXPORT=================================================================
//Publications
void serializableFileManager::exportData(library *library, libraryUser *libraryUser) {
  bool exportPublicationFlag = false, exportUserFlag = false;
  position = 0; //Reset
  exportPublicationFlag = publicationsData.exportPublications(library, MAX_CHAR, &dataFile, &position);
  if(exportPublicationFlag) exportUserFlag = usersData.exportUsers(libraryUser, MAX_CHAR, &dataFile, &position);
  if(exportPublicationFlag && exportUserFlag) cslPrinter.printLine("Zapis zakonczony powodzeniem.");
}