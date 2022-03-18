//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "serializableFileManager.h"

using namespace std;

// IMPORT=================================================================
//Publications
void serializableFileManager::importData(library *library, libraryUser *libraryUser) {
  position = 0; //Reset
  publicationsData.importPublications(library, MAX_CHAR, &dataFile, &position);
  usersData.importUsers(libraryUser, MAX_CHAR, &dataFile, &position);
}

// EXPORT=================================================================
//Publications
void serializableFileManager::exportData(library *library, libraryUser *libraryUser) {
  position = 0; //Reset
  publicationsData.exportPublications(library, MAX_CHAR, &dataFile, &position);
  usersData.exportUsers(libraryUser, MAX_CHAR, &dataFile, &position);
}