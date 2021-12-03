//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
#include "book.cpp"
//Libs
#include <iostream>

using namespace std;
int main() {
  const string appName = "Biblioteka v0.3";

  Book book1("W pustyni i w puszczy", "Henryk Sienkiewicz", 2010, 296, "Greg","9788373271890");  //Create Book
  Book book2("Opus magnum C++ 11", "Jerzy Grębosz", 2020, 1648, "Helion", "9788328371026");

  cout << appName << endl;
  book1.printInfo();  //Print information
  book2.printInfo();

  return 0;
}
