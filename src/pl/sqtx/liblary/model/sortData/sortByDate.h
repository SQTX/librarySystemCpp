//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_SORTBYDATE_H
#define LIBRARYSYSTEM_SORTBYDATE_H

/*Header*/
#include "../../include/main_h.h"
#include "../../include/publicationType_h.h"

typedef std::shared_ptr<Publication> PublicationPtr;
class sortByDate{
private:
public:
  void getSort(std::vector<PublicationPtr> &publications);
};

#endif //LIBRARYSYSTEM_SORTBYDATE_H
