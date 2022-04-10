//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_SERIALIZABLEFILEMANAGER_H
#define LIBRARYSYSTEM_SERIALIZABLEFILEMANAGER_H

/*Libraries*/
#include <cstdio>
#include <fstream>
//Headers
#include "../../include/main_h.h"
#include "../../include/exception_h.h"
#include "../../include/library_h.h"
#include "../../model/libraryUser.h"
#include "typesOfData/publicationsData.h"
#include "typesOfData/usersData.h"


class serializableFileManager {
private:
  publicationsData publicationsData;
  usersData usersData;
  consolePrinter cslPrinter;
  const short MAX_CHAR = 50;  //Max char in string
  std::fstream dataFile;
  int position = 0; //Reset

public:
//  IMPORT========================================================================================================
  void importData(library *library, libraryUser *libraryUser);

//EXPORT========================================================================================================
  void exportData(library *library, libraryUser *libraryUser);
};

#endif //LIBRARYSYSTEM_SERIALIZABLEFILEMANAGER_H