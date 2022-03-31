//
// Created by Jakub Sitarczyk on 09/12/2021.
//

#include "libraryControl.h"

using namespace std;

//  Main method
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
      case option.EXIT:
        exit();
        break;
      default:
        cslPrinter.printLine("Nie ma takiej opcji, wprowadz ponownie: ");
    }
  } while (choice != option.EXIT);
}

int libraryControl::getChoice() {
  options::Option option;
  consolePrinter cslPrinter;
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
      cslPrinter.printLine(message);
    } catch (invalid_argument err) {
      cslPrinter.printLine(err.what());
    }
  } while (!choiceRight);
  return choice;
}

//  Print all options in numbered list
void libraryControl::printOptions() {
  options::Option option;
  cslPrinter.printLine("Wybierz opcje: ");
  for (int i = 0; i < option.getOptionsSize(); i++) {
    cslPrinter.printLine(option.toString(i));
  }
}

//  Add publications
void libraryControl::addBook() {
  try {
    PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
    library.addBook(book);
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", publikacja nie zostala dodana.");
    cslPrinter.printLine(message);
  } catch (out_of_range err) {
    cslPrinter.printLine("Przekroczono dozwolony limit publikacji.");
  }
}

void libraryControl::addMagazine() {
  try {
    PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
    library.addMagazine(magazine);
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", publikacja nie zostala dodana.");
    cslPrinter.printLine(message);
  } catch (out_of_range err) {
    cslPrinter.printLine("Przekroczono dozwolony limit publikacji.");
  }
}

//  Print publications
void libraryControl::printBooks() {
  vector<PublicationPtr> publications = library.getPublications();
  cslPrinter.printBooks(publications);
}

void libraryControl::printMagazines() {
  vector<PublicationPtr> publications = library.getPublications();
  cslPrinter.printMagazines(publications);
}

//  Remove publications
void libraryControl::removeBook() {
  try {
    PublicationPtr book = make_shared<Book>(dataReader.readAndCreateBook());
    library.removeBook(book);
    cslPrinter.printLine("Ksiazka została usunieta z bazy danych.");
  } catch (invalid_argument err) {
    string message = err.what();
    message.append("");
    cslPrinter.printLine(message);
  }
}

void libraryControl::removeMagazine() {
  try {
    PublicationPtr magazine = make_shared<Magazine>(dataReader.readAndCreateMagazine());
    library.removeMagazine(magazine);
    cslPrinter.printLine("Gazeta została usunieta z bazy danych.");
  } catch (invalid_argument err) {
    string message = err.what();
    message.append("");
    cslPrinter.printLine(message);
  }
}

void libraryControl::addUser() {
  try {
    User user = dataReader.readAndCreateUser();
    libraryUser.addUser(user);
  } catch (invalid_argument err) {
    string message = err.what();
    message.append(", uzytkownik nie został dodany.");
    cslPrinter.printLine(message);
  } catch (out_of_range err) {
    cslPrinter.printLine("Przekroczono dozwolony limit uzytkownikow.");
  }
}

void libraryControl::printUsers() {
  vector<User> users = libraryUser.getUsers();
  cslPrinter.printUsers(users);
}

void libraryControl::borrowPublication() {
  borrowEngine.borrowPublication(&library, &libraryUser);
}

void libraryControl::returnPublication() {
  borrowEngine.returnPublication(&library, &libraryUser);
}

void libraryControl::historyOfUser() {
  borrowEngine.printUserHistory(&libraryUser);
}

void libraryControl::exit() {
  srlFileManager.exportData(&library, &libraryUser);
  cslPrinter.printLine("Koniec programu.");
}

//  Class Options =====================================================================================================
int options::Option::getOptionsSize() const {
  return options::Option::optionsSize;
}

const map<unsigned int, const string> &options::Option::getMyMap() const {
  return MyMap;
}

string options::Option::toString(int value) {
  return to_string(value) + " - " + MyMap[value];
}