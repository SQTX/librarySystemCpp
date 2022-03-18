//
// Created by Jakub Sitarczyk on 18/03/2022.
//

#ifndef LIBRARYSYSTEM_PUBLICATIONSDATA_H
#define LIBRARYSYSTEM_PUBLICATIONSDATA_H

/*Libraries*/
#include <cstdio>
#include <fstream>
//Headers
#include "../../../include/main_h.h"
#include "../../../include/consolePriner_h.h"
#include "../../../include/exception_h.h"
#include "../../../include/library_h.h"
#include "../../../include/publicationType_h.h"

/*Functions saving and downloading publications from the database*/
class publicationsData {
private:
  consolePrinter cslPrinter;

public:
  /*Function that imports publications into the main vector that stores
    publications in the library.cpp class*/
  void importPublications(library *library, const char MAX_CHAR,
                          std::fstream *dataFile, int *position);

  /*Function that export publications from the main vector that stores
    publications in the library.cpp class into dataBase file*/
  void exportPublications(library *library, const char MAX_CHAR,
                          std::fstream *dataFile, int *position);
};

#endif //LIBRARYSYSTEM_PUBLICATIONSDATA_H