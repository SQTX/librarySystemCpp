//
// Created by Jakub Sitarczyk on 02/12/2021.
//
/*Files*/
#include "libraryControl.h"
//Headers
#include "../include/main_h.h"  //All libs and namespace
#include "../include/consolePriner_h.h"

static const std::string appName = "Biblioteka v2.5.1";  //App version
int main() {
  consolePrinter cslPrinter;
  cslPrinter.printLine(appName);
  libraryControl libraryControl;
  libraryControl.controlLoop(); //Main app

  return 0;
}
