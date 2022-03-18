//
// Created by Jakub Sitarczyk on 03/01/2022.
//

#include "consolePrinter.h"

using namespace std;

void consolePrinter::printLine(string txt) {
#ifdef _WIN64
  cout << tr(txt) << endl;
#elif __APPLE__
  cout << txt << endl;
#endif
}

void consolePrinter::printBooks(vector<PublicationPtr> &publications) {
  int countBooks = 0;
  vector<PublicationPtr> sortedPublications;
  for (int i = 0; i < publications.size(); i++) {
    PublicationPtr ptr = publications[i];
    if (dynamic_cast<Book *>(ptr.get())) { //Checking if the Publication is a Book
      sortedPublications.push_back(ptr);
      countBooks++;
    }
  }
//    Sort
  sort.getSort(sortedPublications);
//    Print
  for (auto &publication: sortedPublications)
    cout << publication->toString() << endl;

  if (countBooks == 0) {
    printLine("Brak ksiażek w bibliotece");
  }
}

void consolePrinter::printMagazines(vector<PublicationPtr> &publications) {
  vector<PublicationPtr> sortedPublications;
  int countMagazine = 0;
  for (int i = 0; i < publications.size(); i++) {
    PublicationPtr ptr = publications[i];
    if (dynamic_cast<Magazine *>(ptr.get())) { //Checking if the Publication is a Magazine
      sortedPublications.push_back(ptr);
      countMagazine++;
    }
  }
//    Sort
  sort.getSort(sortedPublications);
//    Print
  for (auto &publication: sortedPublications)
    cout << publication->toString() << endl;
  if (countMagazine == 0) {
    printLine("Brak gazet w bibliotece");
  }
}

void consolePrinter::printUsers(vector<User> &users) {
  int countBooks = 0;
//  vector<PublicationPtr> sortedPublications;
  for (int i = 0; i < users.size(); i++) {
    printLine(users[i].toString());
    countBooks++;
  }
/*//    Sort
  sort.getSort(sortedPublications);
//    Print
  for (auto &publication: sortedPublications)
    cout << publication->toString() << endl;*/

  if (countBooks == 0) {
    printLine("Brak użytkowników w bazie.");
  }
}

char *tr(char *str) {
  static char buff[256];
  char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215����󜿟��ʣ�ӌ��";
  if(strlen(str)>=sizeof(buff)) return str;
  char *bf=buff;
  while(*str)
  {
    char *pos=strchr(cp+18,*str);
    *(bf++)=pos?*(pos-18):*str;
    ++str;
  }
  *bf=0;
  return buff;
}


