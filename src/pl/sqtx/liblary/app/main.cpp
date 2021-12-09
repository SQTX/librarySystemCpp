//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Files
//#include "../model/book.cpp"  <-- Called in the file dataReader.cpp
#include "../io/dataReader.cpp"
//Libs
#include <iostream>

using namespace std;
int main() {
  const string appName = "Biblioteka v0.8";

  const int booksSize = 1000;
  Book books[booksSize];  //Books array and size
  DataReader dataReader;  //Create object

  //Create books
  books[0] = Book("W pustyni i w puszczy", "Henryk Sienkiewicz", 2010,
             296, "Greg","9788373271890");  //Create Book
  books[1] = Book("Opus magnum C++ 11", "Jerzy Grębosz", 2020,
             1648, "Helion", "9788328371026");
  books[2] = Book("SCJP Sun Certified Programmer for Java 6 Study Guide", "Bert Bates, Katherine Sierra",
             2008, 851, "McGraw-Hill Osborne Media");
//  App ON
  cout << appName << endl;
  cout << "Wprowadz ksiazke: " << endl;
  books[3] = dataReader.readAndCreateBook();
  books[0].printInfo();  //Print informations
  books[1].printInfo();
  books[2].printInfo();
  books[3].printInfo();
  cout << "System może przechowywać do " << booksSize << " książek" << endl;

  return 0;
}
