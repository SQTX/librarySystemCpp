//
// Created by Jakub Sitarczyk on 02/12/2021.
//
/*Files*/
#include "libraryControl.cpp"
//Headers
#include "../include/main_h.h"  //All libs and namespace
#include "../include/consolePriner_h.h"

static const string appName = "Biblioteka v2.1";  //App version
int main() {
  ConsolePrinter cslPrinter;
  cslPrinter.printLine(appName);
  LibraryControl libraryControl;
  libraryControl.controlLoop(); //Main app

  return 0;
}
