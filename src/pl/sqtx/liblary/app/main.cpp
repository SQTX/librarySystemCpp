//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
#include "libraryControl.cpp"
//Headers
#include "../include/main_h.h"  //All libs and namespace

//App version
static const string appName = "Biblioteka v1.5";
int main() {
  cout << appName << endl;
  LibraryControl libraryControl;
  libraryControl.controlLoop(); //Turn on app

  return 0;
}
