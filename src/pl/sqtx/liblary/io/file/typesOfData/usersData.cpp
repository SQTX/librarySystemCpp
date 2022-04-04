//
// Created by Jakub Sitarczyk on 17/03/2022.
//

#include "usersData.h"

using namespace std;

//Import users function
bool usersData::importUsers(libraryUser *libraryUser, const char MAX_CHAR, fstream *dataFile,
                            int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataImportException err;  //Create error

    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::in); //Open data_file

//    File opens good ******************************************
    if (dataFile->is_open()) {
      dataFile->seekg(actualPosition);  //Set actualy position of file cursor

      dataFile->ignore(numeric_limits<streamsize>::max(), '\n');  //Ignore first line

//      Lets save
      int userDataSize;
      *dataFile >> userDataSize; //Get publications number
      dataFile->ignore(1);

//      Create all object form database
      for (int i = 0; i < userDataSize; i++) {
//        Get user type
        char c_type[MAX_CHAR];
        dataFile->get(c_type, MAX_CHAR, ';');
        dataFile->ignore(1);

//        Checking types
        string type(c_type);
//        Person ----------------------------------
        if (type == "Person") {
//          Save standard: Person;FirstName;LastName;Pesel

//          Get data from file and create new obejct of them
          char c_firstName[MAX_CHAR];
          dataFile->get(c_firstName, MAX_CHAR, ';');
          string firstName(c_firstName);
          dataFile->ignore(1);

          char c_lastName[MAX_CHAR];
          dataFile->get(c_lastName, MAX_CHAR, ';');
          string lastName(c_lastName);
          dataFile->ignore(1);

          char c_pesel[MAX_PESEL_CHAR];
          dataFile->get(c_pesel, MAX_PESEL_CHAR + 1, ';');
          string pesel(c_pesel);
          dataFile->ignore(1);

//          Create object and add it to libraryUser vector
          Person user(firstName, lastName, pesel);
          libraryUser->addUser(user);

//        Noname type ----------------------------------
        } else {
          cslPrinter.printLine("Nieznany typ publikacji.");
        }
      }
//      Succesfulle import
//      Close file and print message
      dataFile->close();
      return 1;

//      File opens fail ******************************************
    } else {
//      If the database file doesn't exist, it tries to create a new one
      cslPrinter.printLine("Brak bazy danych.");
      dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out);
      if (dataFile->is_open()) {
        cslPrinter.printLine("Zainicjalizowano nowa baze danych.");
        dataFile->close();
        return 0;
      } else {
        cslPrinter.printLine("Stworzenie nowej bazy danych jest niemozliwe.");
        throw err;
      }
    }
  } catch (DataImportException err) {
    string message = err.what();
    cslPrinter.printLine(message);
  }
}

//Export users function
bool usersData::exportUsers(libraryUser *libraryUser, const char MAX_CHAR, fstream *dataFile,
                            int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataExportException err;
    dataFile->open("../src/pl/sqtx/liblary/data/dataBase.txt", ios::out | ios::app);  //Open database

//    File opens good ******************************************
    if (dataFile->is_open()) {
      dataFile->seekp(actualPosition);

      *dataFile << "\n[Users]\n";  //Set sepparator

//      Get data from libraryUser.cpp
      vector<User> users = libraryUser->getUsersVector(); //Get vector
      int usersNum = users.size();  //Get database size

//      Lets export
      if (usersNum <= 0) {
        *dataFile << '0';
        dataFile->close();
        return 1;
      } else {
        *dataFile << usersNum; //Set publications number

        for (int i = 0; i < usersNum; i++) {
          string saveLine;
          saveLine = "\nPerson;";
          saveLine.append(users[i].toSave());
          *dataFile << saveLine; //Export data
        }
        if (((dataFile->rdstate() ^ fstream::eofbit) == 0) || fstream::eofbit == 2) {
          actualPosition = dataFile->tellp(); //Get actualy position of file cursor
          *position = actualPosition;
          dataFile->close();
          return 1;
        }
        return 0;
      }
      return 0;
    }
  } catch (DataExportException err) {
    string message = err.what();
    cslPrinter.printLine("Blad zapisu.");
    cslPrinter.printLine(message);
  }
}
