//
// Created by Jakub Sitarczyk on 15/02/2022.
//
#include "../../include/main_h.h"
#include "../../include/exception_h.h"
#include "fileManager.cpp"
#include <fstream>

class SerializableFileManager : public FileManager{
  fstream dataFile;
  void importData(){
    dataFile.open("save.txt", ios::in);
    if(dataFile.is_open()){

    }else{

    }
  }
};
