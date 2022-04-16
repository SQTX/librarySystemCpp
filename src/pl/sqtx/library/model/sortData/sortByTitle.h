//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_SORTBYTITLE_H
#define LIBRARYSYSTEM_SORTBYTITLE_H

#include <cstring>
#include "../../include/main_h.h"
#include "../../include/publicationType_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;
class sortByTitle{
private:
  /**Convert upper case to low case.*/
  std::string toLowCase(std::string str);
public:
  /**Creates a sorted vector from the root vector.*/
  void getSort(std::vector<PublicationPtr> &publications);
};

#endif //LIBRARYSYSTEM_SORTBYTITLE_H
