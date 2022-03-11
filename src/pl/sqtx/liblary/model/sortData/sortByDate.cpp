//
// Created by Jakub Sitarczyk on 02/03/2022.
//

#include "sortByDate.h"

using namespace std;

void sortByDate::getSort(vector<PublicationPtr> &publications) {
  for (int i = 0; i < publications.size(); i++) {
    for (int j = 0; j < publications.size() - 1; j++) {
//     Get dates
      int firstDate = publications[j]->getReleaseDate();
      int secondDate = publications[j + 1]->getReleaseDate();
//      Boubble Sort
      if (firstDate > secondDate)
        swap(publications[j], publications[j + 1]);
    }
  }
}