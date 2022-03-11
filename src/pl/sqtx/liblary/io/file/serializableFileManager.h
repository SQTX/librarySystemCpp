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
#include "../../include/consolePriner_h.h"
#include "../../include/publicationType_h.h"

class serializableFileManager {
private:
  const short MAX_CHAR = 50;
  consolePrinter cslPrinter;
  std::fstream dataFile;

//  Add symbol between text
  std::string addHyphen(std::string txt);

public:
//  IMPORT========================================================================================================
  void importData(library *library);

//EXPORT========================================================================================================
  void exportData(library *library);
};

#endif //LIBRARYSYSTEM_SERIALIZABLEFILEMANAGER_H
