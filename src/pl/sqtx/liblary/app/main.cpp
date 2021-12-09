//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
#include "libraryControl.cpp"
//Libs
#include <iostream>

using namespace std;
//App version
static const string appName = "Biblioteka v1.0";

int main() {
  cout << appName << endl;
  LibraryControl libraryControl;
  libraryControl.controlLoop(); //Turn on app

  return 0;
}
