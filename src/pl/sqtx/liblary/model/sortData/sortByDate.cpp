//
// Created by Jakub Sitarczyk on 02/03/2022.
//
/*Header*/
#include "../../include/main_h.h"
#include "../../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;
class sortByDate{
private:
public:
  void getSort(vector<PublicationPtr> &publications){
    for(int i = 0; i < publications.size(); i++){
      for(int j = 0; j < publications.size() - 1; j++) {
//     Get dates
        int firstDate = publications[j]->getReleaseDate();
        int secondDate = publications[j+1]->getReleaseDate();
//      Boubble Sort
        if(firstDate > secondDate)
          swap(publications[j], publications[j+1]);
      }
    }
  }
};