//
// Created by Jakub Sitarczyk on 02/12/2021.
//
#include "libraryControl.h"
#include "../include/main_h.h"
#include "../io/consolePrinter.h"

static const std::string appName = "Biblioteka v3.1.0";  //App version
int main() {
  consolePrinter cslPrinter;
  cslPrinter.printLine(appName);  //Print version
  libraryControl libraryControl;
  libraryControl.controlLoop(); //Main app

  return 0;
}
