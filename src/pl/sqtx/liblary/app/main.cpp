//
// Created by Jakub Sitarczyk on 02/12/2021.
//
#include "libraryControl.h"
#include "../include/main_h.h"  //All librarys
#include "../include/consolePriner_h.h"

static const std::string appName = "Biblioteka v2.8.0";  //App version
int main() {
  consolePrinter cslPrinter;
  cslPrinter.printLine(appName);
  libraryControl libraryControl;
  libraryControl.controlLoop(); //Main app

  return 0;
}
