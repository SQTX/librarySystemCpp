//
// Created by Jakub Sitarczyk on 17/03/2022.
//

#include "usersData.h"

using namespace std;

//Import users function
bool usersData::importUsers(libraryUser *libraryUser, const char MAX_CHAR, fstream *dataFile, int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataImportException err;  //Create error

    dataFile->open("../src/pl/sqtx/library/data/dataBase.txt", ios::in); //Open data_file
    //TODO: Potęcjalny błąd dla windows \ zamiast /

//    File opens good ******************************************
    if (dataFile->is_open()) {
      dataFile->seekg(actualPosition);  //Set actualy position of file cursor

      dataFile->ignore(numeric_limits<streamsize>::max(), '\n');  //Ignore first line - [User]

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
//        cout << type << endl;
//        Person ----------------------------------
        if (type == "User") {
//          Save standard: Person;FirstName;LastName;Pesel;all;currently;returns

//          Get data from file and create new obejct of them
          char c_firstName[MAX_CHAR];
          dataFile->get(c_firstName, MAX_CHAR, ';');
          string firstName(c_firstName);
          dataFile->ignore(1);

          char c_lastName[MAX_CHAR];
          dataFile->get(c_lastName, MAX_CHAR, ';');
          string lastName(c_lastName);
          dataFile->ignore(1);

          char c_pesel[MAX_PESEL_CHAR+1];
          dataFile->get(c_pesel, MAX_PESEL_CHAR + 1, ';');
          string pesel(c_pesel);
          dataFile->ignore(1);

          int allLoanNumb = 0;
          char c_allLoanNumb[MAX_CHAR];
          dataFile->get(c_allLoanNumb, MAX_CHAR, ';');
          sscanf(c_allLoanNumb, "%d", &allLoanNumb);//Last element
          dataFile->ignore(1);

          int currentlyLoan = 0;
          char c_currentlyLoan[MAX_CHAR];
          dataFile->get(c_currentlyLoan, MAX_CHAR, ';');
          sscanf(c_currentlyLoan, "%d", &currentlyLoan);//Last element
          dataFile->ignore(1);

          int returnedNumb = 0;
          char c_returnedNumb[MAX_CHAR];
          dataFile->get(c_returnedNumb, MAX_CHAR, '\n');
          sscanf(c_returnedNumb, "%d", &returnedNumb);//Last element
          dataFile->ignore(1);

//          Create object and add it to libraryUser vector
          User user(firstName, lastName, pesel);
          user.setAllLoanNumb(allLoanNumb);
          user.setCurrentlyLoan(currentlyLoan);
          user.setReturnedNumb(returnedNumb);
//          --- Get history of user ---
          dataFile->ignore(numeric_limits<streamsize>::max(), '\n');
//        Get history of this user
          if(allLoanNumb != 0){
            for (int j = 0; j < allLoanNumb; j++) {
//          Save standard: Title;SecondPart;LoanDate;ReturnDate
              char c_hisElemTitle[MAX_CHAR];
              dataFile->get(c_hisElemTitle,MAX_CHAR, ';');
              string hisElemTitle(c_hisElemTitle);
              dataFile->ignore(1);

              char c_hisElemSecondPart[MAX_CHAR];
              dataFile->get(c_hisElemSecondPart,MAX_CHAR, ';');
              string hisElemSecondPart(c_hisElemSecondPart);
              dataFile->ignore(1);

              char c_hisElemLoanDate[MAX_CHAR];
              dataFile->get(c_hisElemLoanDate,MAX_CHAR, ';');
              string hisElemLoanDate(c_hisElemLoanDate);
              dataFile->ignore(1);

              char c_hisElemReturnDate[MAX_CHAR];
              dataFile->get(c_hisElemReturnDate,MAX_CHAR, '\n');
              string hisElemReturnDate(c_hisElemReturnDate);
              dataFile->ignore(1);

//            Create history element
              HistoryElement historyElement(hisElemTitle, hisElemSecondPart, hisElemLoanDate, hisElemReturnDate);
              user.addHistoryElement(historyElement);
            }
          }
//          Set this user in base-data
          libraryUser->addUser(user);

//        Noname type ----------------------------------
        } else {
          cslPrinter.printLine("Nieznany status osoby.");
        }
      }
//      Succesfulle import
      actualPosition = dataFile->tellg(); //Get actualy position of file cursor
      *position = actualPosition;
//      Close file and print message
      dataFile->close();
      return 1;

//      File opens fail ******************************************
    } else {
//      If the database file doesn't exist, it tries to create a new one
      cslPrinter.printLine("Brak bazy danych.");
      dataFile->open("../src/pl/sqtx/library/data/dataBase.txt", ios::out);
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
bool usersData::exportUsers(libraryUser *libraryUser, const char MAX_CHAR, fstream *dataFile, int *position) {
  int actualPosition = *position; //Get actual position of file cursor

  try {
    DataExportException err;
    dataFile->open("../src/pl/sqtx/library/data/dataBase.txt", ios::out);  //Open database
    //TODO: Potęcjalny błąd dla windows \ zamiast /

//    File opens good ******************************************
    if (dataFile->is_open()) {
      dataFile->seekp(actualPosition);

      *dataFile << "[Users]\n";  //Set sepparator

//      Get data from libraryUser.cpp
      vector<User> users = libraryUser->getUsersVector(); //Get vector
      int usersNum = users.size();  //Get database size
//      Lets export
      if (usersNum <= 0) {
        *dataFile << '0';
        actualPosition = dataFile->tellp(); //Get actualy position of file cursor
        *position = actualPosition;
        dataFile->close();
        return 1;
      } else {
        *dataFile << usersNum; //Set publications number

        for (int i = 0; i < usersNum; i++) {
          *dataFile << users[i].toSave(); //Export data
          *dataFile << "\n*History*";
          if(users[i].getAllLoanNumb() != 0){
            for(int j = 0; j < users[i].getUserHistory().size(); j++){
              string textLine;
              textLine.append('\n' + users[i].toSaveUserHistory(j));
              *dataFile << textLine;
            }
          }
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
