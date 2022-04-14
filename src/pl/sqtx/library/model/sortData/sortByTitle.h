//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_SORTBYTITLE_H
#define LIBRARYSYSTEM_SORTBYTITLE_H

/*Libraries*/
#include <cstring>
//Header
#include "../../include/main_h.h"
#include "../../include/publicationType_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;
class sortByTitle{
private:
//  Convert upper case to low case
  std::string toLowCase(std::string str);
public:
  void getSort(std::vector<PublicationPtr> &publications);
};

#endif //LIBRARYSYSTEM_SORTBYTITLE_H
