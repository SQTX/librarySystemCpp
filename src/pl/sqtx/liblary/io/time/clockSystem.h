//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_CLOCKSYSTEM_H
#define LIBRARYSYSTEM_CLOCKSYSTEM_H

#include <chrono>
#include "../../include/main_h.h"

class clockSystem {
public:
//  Get actual time
  std::string getTime();
//  Get actual date
  std::string getDate();
};

#endif //LIBRARYSYSTEM_CLOCKSYSTEM_H
