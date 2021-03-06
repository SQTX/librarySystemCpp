//
// Created by Jakub Sitarczyk on 20/04/2022.
//

#include "searchEngine.h"

using namespace std;

int searchEngine::findUser(libraryUser *libraryUser, string txt, int lastIteratorIndex) {
  string fromUser = dataReader.toLowerCase(txt);
  auto it_users = libraryUser->getIteratorUsers();

  ++lastIteratorIndex;
  if (lastIteratorIndex <= libraryUser->getUsersVector().size()) {
    for (int i = lastIteratorIndex; i < libraryUser->getUsersVector().size(); i++) {
//      Transform user data to the same case
      const string firstname = dataReader.toLowerCase((it_users + i)->getFirstName());
      const string lastname = dataReader.toLowerCase((it_users + i)->getLastName());
      const string pesel = dataReader.toLowerCase((it_users + i)->getPesel());
      const string firstNLastName = firstname + " " + lastname;

      if (fromUser == firstname || fromUser == lastname || fromUser == pesel || fromUser == firstNLastName) return i;
    }
  } else {
    return -1;
  }
  return -1;
}

int searchEngine::findPublication(library *library, std::string txt, int lastIteratorIndex) {
  string fromUser = dataReader.toLowerCase(txt);
  auto it_publication = library->getIteratorPublications();

  ++lastIteratorIndex;
  if (lastIteratorIndex <= library->getPublications().size()) {
    for (int i = lastIteratorIndex; i < library->getPublications().size(); i++) {
//      Transform user data to the same case
      const string title = dataReader.toLowerCase((it_publication + i)->get()->getTitle());
      string secondPart = "";
      int authorIndex = -1;
      string isbn = "";
      if (dynamic_cast<Book *>((it_publication + i)->get())) {
        secondPart = dataReader.toLowerCase(dynamic_cast<Book *>((it_publication + i)->get())->getAuthor());
//        detect single word in author string
        authorIndex = secondPart.find(fromUser);
        isbn = dynamic_cast<Book *>((it_publication + i)->get())->getIsbn();
      } else if (dynamic_cast<Magazine *>((it_publication + i)->get()))
        secondPart = dynamic_cast<Magazine *>((it_publication + i)->get())->createFullDateOfPublication();
      const string publisher = dataReader.toLowerCase((it_publication + i)->get()->getPublisher());
      const string titleNAuthor = title + " " + secondPart;

//      detect single word in title string
      const int wordIndex = title.find(fromUser);

      if (fromUser == title || wordIndex >= 0 || fromUser == secondPart || authorIndex >= 0 || fromUser == publisher || fromUser == isbn) return i;
    }
  } else {
    return -1;
  }
  return -1;
}

//Main Search Function
void searchEngine::searchEng(library *library, libraryUser *libraryUser) {
  cin.ignore();
  consolePrinter::printLine("Poszukiwana fraza:");
  string txt = dataReader.getTextLine();
  auto it_user = libraryUser->getIteratorUsers();

  int wantedIteratorIndex = -1;
  consolePrinter::printLine("Uzytkownicy:");
  do {
    wantedIteratorIndex = findUser(libraryUser, txt, wantedIteratorIndex);
    if (wantedIteratorIndex >= 0) consolePrinter::printLine((it_user + wantedIteratorIndex)->toString());
  } while (wantedIteratorIndex >= 0);

  wantedIteratorIndex = -1;
  consolePrinter::printLine("Publikacje:");
  auto it_publication = library->getIteratorPublications();
  do {
    wantedIteratorIndex = findPublication(library, txt, wantedIteratorIndex);
    if (wantedIteratorIndex >= 0) consolePrinter::printLine((it_publication + wantedIteratorIndex)->get()->toString());
  } while (wantedIteratorIndex >= 0);
}