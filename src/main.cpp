//
// Created by Jakub Sitarczyk on 02/12/2021.
//
//Libs
#include <iostream>
//Files
#include "book.cpp"

using namespace std;
int main() {
  const string appName = "Biblioteka v0.2";

  Book book;  //New Class
  book.title = "W pustyni i w puszczy";
  book.author = "Henryk Sienkiewicz";
  book.releaseDate = 2010;
  book.pages = 296;
  book.publisher = "Greg";
  book.isbn = "9788373271890";

  cout << appName << endl;
  cout << "Książki dostępne w bibliotece:" << endl;
  cout << book.title << endl;
  cout << book.author << endl;
  cout << book.releaseDate << endl;
  cout << book.pages << endl;
  cout << book.publisher << endl;
  cout << book.isbn << endl;

  return 0;
}
