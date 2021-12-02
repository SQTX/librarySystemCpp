//
// Created by Jakub Sitarczyk on 02/12/2021.
//
#include <iostream>

using namespace std;
int main() {
  const string appName = "Biblioteka v0.1";

  string title = "W pustyni i w puszczy";
  string author = "Henryk Sienkiewicz";
  int releaseDate = 2010;
  int pages = 296;
  string publisher = "Greg";
  string isbn = "9788373271890";

  cout << appName << endl;
  cout << "Książki dostępne w bibliotece:" << endl;
  cout << title << endl;
  cout << author << endl;
  cout << releaseDate << endl;
  cout << pages << endl;
  cout << publisher << endl;
  cout << isbn << endl;


  return 0;
}
