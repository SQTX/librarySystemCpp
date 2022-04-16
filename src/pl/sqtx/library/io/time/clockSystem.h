//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_CLOCKSYSTEM_H
#define LIBRARYSYSTEM_CLOCKSYSTEM_H

#include <chrono>
#include "../../include/main_h.h"

class clockSystem {
public:
  std::string getTime();  //Get actual time
  std::string getDate();  //Get actual date
};

#endif //LIBRARYSYSTEM_CLOCKSYSTEM_H
