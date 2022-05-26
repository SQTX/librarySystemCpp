//
// Created by Jakub Sitarczyk on 09/12/2021.
//

#include "libraryControl.h"

using namespace std;

//--- Main function ---
void libraryControl::controlLoop() {
  srlFileManager.importData(&library, &libraryUser);  //Import data
  options::Option option;
  int choice;
  do {
    choice = getChoice();
    switch (choice) {
      case option.ADD_BOOK:
        addBook();
        break;
      case option.ADD_MAGAZINE:
        addMagazine();
        break;
      case option.PRINT_BOOKS:
        printBooks();
        break;
      case option.PRINT_MAGAZINES:
        printMagazines();
        break;
      case option.REMOVE_BOOK:
        removeBook();
        break;
      case option.REMOVE_MAGAZINE:
        removeMagazine();
        break;
      case option.ADD_USER:
        addUser();
        break;
      case option.PRINT_USERS:
        printUsers();
        break;
      case option.BORROW_PUBLICATION:
        borrowPublication();
        break;
      case option.RETURN_PUBLICATION:
        returnPublication();
        break;
      case option.HISTORY_OF_USER:
        historyOfUser();
        break;
      case option.SEARCH_ENGINE:
        searchEngi();
        break;
      case option.EXIT:
        exit();
        break;
      default:
        consolePrinter::printLine("Nie ma takiej opcji, wprowadz ponownie: ");
    }
  } while (choice != option.EXIT);
}
//--- Get choice form user
int libraryControl::getChoice() {
  options::Option option;
  int choice = 0;
  bool choiceRight = false;
  do {
    printOptions();
    try {
      choice = dataReader.getInt();
      if (choice >= 0 && choice < option.END) {
        choiceRight = true;
      } else {
        NoSuchOptionException err;
        throw err;
      }
    } catch (NoSuchOptionException err) {
      choiceRight = false;
      string message = err.what() + to_string(choice);
      consolePrinter::printLine(message);
    } catch (invalid_argument err) {
      consolePrinter::printLine(err.what());
    }
  } while (!choiceRight);
  return choice;
}
//--- Print all options in numbered list ---
void libraryControl::printOptions() {
  options::Option option;
  consolePrinter::printLine("Wybierz opcje: ");
  for (int i = 0; i < option.getOptionsSize(); i++) {
    consolePrinter::printLine(option.toString(i));
  }
}

void operator+(library& library, PublicationPtr book) {
  library.addBook(book);
}
//--- Add new publication ---
void libraryControl::addBook() {
  try {
    PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
//    library.addBook(book);
    library+book;
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", publikacja nie zostala dodana.");
    consolePrinter::printLine(message);
  } catch (out_of_range err) {
    consolePrinter::printLine("Przekroczono dozwolony limit publikacji.");
  }
}
void libraryControl::addMagazine() {
  try {
    PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
    library.addMagazine(magazine);
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", publikacja nie zostala dodana.");
    consolePrinter::printLine(message);
  } catch (out_of_range err) {
    consolePrinter::printLine("Przekroczono dozwolony limit publikacji.");
  }
}
//--- Print publications
void libraryControl::printBooks() {
  vector<PublicationPtr> publications = library.getPublications();
  cslPrinter.printBooks(publications);
}
void libraryControl::printMagazines() {
  vector<PublicationPtr> publications = library.getPublications();
  cslPrinter.printMagazines(publications);
}
//--- Remove publication ---
void libraryControl::removeBook() {
  try {
    PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
    library.removeBook(book);
    consolePrinter::printLine("Ksiazka zostala usunieta z bazy danych.");
  } catch (invalid_argument err) {
    string message = err.what();
    message.append("");
    consolePrinter::printLine(message);
  }
}
void libraryControl::removeMagazine() {
  try {
    PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
    library.removeMagazine(magazine);
    consolePrinter::printLine("Gazeta zostala usunieta z bazy danych.");
  } catch (invalid_argument err) {
    string message = err.what();
    message.append("");
    consolePrinter::printLine(message);
  }
}
//--- Add new user ---
void libraryControl::addUser() {
  try {
    User user = dataReader.readAndCreateUser();
    libraryUser.addUser(user);
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", uzytkownik nie zostal dodany.");
    consolePrinter::printLine(message);
  } catch (out_of_range err) {
    consolePrinter::printLine("Przekroczono dozwolony limit uzytkownikow.");
  } catch (wrongDataException err) {
    consolePrinter::printLine(err.what());
  }
}
//--- Print users ---
void libraryControl::printUsers() {
  vector<User> users = libraryUser.getUsersVector();
  cslPrinter.printUsers(users);
}
//--- Borrow or return publication
void libraryControl::borrowPublication() {
  try{
    borrowEngine.borrowPublication(&library, &libraryUser);
  } catch (UserNotExistException err){
    consolePrinter::printLine(err.what());
  } catch (PublicationNotExistException err){
    string mess = err.what();
    mess.append(", wiec nie zostala wypozyczona.");
    consolePrinter::printLine(mess);
  } catch (PublicationAvailabilityException err){
    string mess = err.what();
    mess.append("jest niedostepna.");
    consolePrinter::printLine(mess);
  }
}
void libraryControl::returnPublication() {
  try{
    borrowEngine.returnPublication(&library, &libraryUser);
  } catch (UserNotExistException err){
    consolePrinter::printLine(err.what());
  } catch (PublicationNotExistException err){
    string mess = err.what();
    mess.append(", wiec nie zostala zwrocona.");
    consolePrinter::printLine(mess);
  } catch (PublicationAvailabilityException err){
    string mess = err.what();
    mess.append("zastala juz zwrocona.");
    consolePrinter::printLine(mess);
  }
}
//--- Print history of user
void libraryControl::historyOfUser() {
  try{
    borrowEngine.printUserHistory(&libraryUser);
  } catch (UserNotExistException err){
    consolePrinter::printLine(err.what());
  }
}
//--- Search engine ---
void libraryControl::searchEngi() {
  searchEngine.searchEng(&library, &libraryUser);
}
//--- Exit ---
void libraryControl::exit() {
  srlFileManager.exportData(&library, &libraryUser);  //Export data
  consolePrinter::printLine("Koniec programu.");
}

//  ====== Class Options ===============================================================================================
int options::Option::getOptionsSize() const {
  return options::Option::optionsSize;
}

/*const map<unsigned int, const string> &options::Option::getMyMap() const {
  return MyMap;
}*/

string options::Option::toString(int value) {
  return to_string(value) + " - " + MyMap[value];
}