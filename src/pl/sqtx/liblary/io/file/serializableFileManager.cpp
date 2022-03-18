//
// Created by Jakub Sitarczyk on 15/02/2022.
//

#include "serializableFileManager.h"

using namespace std;

// IMPORT=================================================================
//Publications
void serializableFileManager::importData(library *library) {
  publicationsData.importPublications(library, MAX_CHAR, &dataFile);
}

// EXPORT=================================================================
//Publications
void serializableFileManager::exportData(library *library) {
  publicationsData.exportPublications(library, MAX_CHAR, &dataFile);
}