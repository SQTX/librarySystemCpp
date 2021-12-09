//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
#include "../model/book.cpp"
//Libs
#include <iostream>

using namespace std;
int main() {
  const string appName = "Biblioteka v0.7";

  Book books[1000];
  books[0] = Book("W pustyni i w puszczy", "Henryk Sienkiewicz", 2010,
             296, "Greg","9788373271890");  //Create Book
  books[1] = Book("Opus magnum C++ 11", "Jerzy Grębosz", 2020,
             1648, "Helion", "9788328371026");
  books[2] = Book("SCJP Sun Certified Programmer for Java 6 Study Guide", "Bert Bates, Katherine Sierra",
             2008, 851, "McGraw-Hill Osborne Media");
  cout << appName << endl;
  books[0].printInfo();  //Print information
  books[1].printInfo();
  books[2].printInfo();

  return 0;
}
