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
//  Convert upper case to low case
  string toLowCase(string str){
    for(int i = 0; i < str.length(); i++){
      if(str[i] <= 'Z' && str[i] >= 'A')
        str[i] += ('a' - 'A');
    }
    return str;
  }
public:
  void getSort(vector<PublicationPtr> &publications){
   for(int i = 0; i < publications.size(); i++){
    for(int j = 0; j < publications.size() - 1; j++) {
//     Get titles
      string firstTitle = publications[j]->getTitle();  //Get title
      char ch_firstTitle[(firstTitle.length()) + 1];  //Create char array
      strcpy(ch_firstTitle, toLowCase(firstTitle).c_str()); //Impute string to array
      string secondTitle = publications[j+1]->getTitle();
      char ch_secondTitle[(secondTitle.length()) + 1];
      strcpy(ch_secondTitle, toLowCase(secondTitle).c_str());

//      Bubble Sort
      int k = 0;
      do{
//        Same letter
        if(ch_firstTitle[k] == ch_secondTitle[k]){
          k++;
        }else if(ch_firstTitle[k] > ch_secondTitle[k]){
          swap(publications[j], publications[j+1]);
          break;
        } else{
          break;
        }
      } while(true);
    }
   }
  }
};