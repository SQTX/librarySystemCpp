//
// Created by Jakub Sitarczyk on 02/03/2022.
//
/*Libraries*/
#include <cstring>
//Header
#include "../../include/main_h.h"
#include "../../include/publicationType_h.h"

typedef shared_ptr<Publication> PublicationPtr;
class sortByTitle{
private:
public:
  void getSort(vector<PublicationPtr> &publications){
   for(int i = 0; i < publications.size(); i++){
    for(int j = 0; j < publications.size() - 1; j++) {
//     Get titles
      string firstTitle = publications[j]->getTitle();
      char ch_firstTitle[(firstTitle.length()) + 1];
      strcpy(ch_firstTitle, firstTitle.c_str());

      string secondTitle = publications[j+1]->getTitle();
      char ch_secondTitle[(secondTitle.length()) + 1];
      strcpy(ch_secondTitle, secondTitle.c_str());
//      Boubble Sort
      int k = 0;
      do{
        if(firstTitle[k] > secondTitle[k]){
          swap(publications[j], publications[j+1]);
          break;
        } else if(ch_firstTitle[k] == ch_secondTitle[k]){
          k++;
        } else{
          break;
        }
      } while(true);
    }
   }
  }
};