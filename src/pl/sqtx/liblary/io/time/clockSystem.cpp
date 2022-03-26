//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#include "clockSystem.h"

using namespace std;

string clockSystem::getTime(){
  string time;
  chrono::system_clock::time_point now = chrono::system_clock::now();
  time_t tt = chrono::system_clock::to_time_t(now);
  tm local_tm = *localtime(&tt);
  time.append(to_string(local_tm.tm_hour) + ":" + to_string(local_tm.tm_min) + ":" + to_string(local_tm.tm_sec));
  return time;
};

string clockSystem::getDate(){
  string date;
  chrono::system_clock::time_point now = chrono::system_clock::now();
  time_t tt = chrono::system_clock::to_time_t(now);
  tm local_tm = *localtime(&tt);
  date.append(to_string(local_tm.tm_year + 1900) + ":" + to_string(local_tm.tm_mon + 1) + ":" + to_string(local_tm.tm_mday));
  return date;
};
