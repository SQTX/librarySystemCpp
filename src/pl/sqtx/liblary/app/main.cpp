//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
#include "libraryControl.cpp"
//Headers
#include "../include/main_h.h"  //All libs and namespace
#include "../include/consolePriner_h.h"

//App version
static const string appName = "Biblioteka v1.81";
int main() {
  ConsolePrinter cslPrinter;
  cslPrinter.printLine(appName);
  LibraryControl libraryControl;
  libraryControl.controlLoop(); //Turn on app

  return 0;
}
