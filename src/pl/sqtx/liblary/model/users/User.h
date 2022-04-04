//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_USER_H
#define LIBRARYSYSTEM_USER_H

#include "../../include/main_h.h"
#include "Person.h"
#include "../../include/publicationType_h.h"
#include "../../model/publications/publication.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class User {
private:
  Person person;
  std::vector<PublicationPtr> lendPublications;
  std::vector<std::string> userHistory;
  unsigned int allLoanNumb = 0;
  unsigned int currentlyLoan = 0;
  unsigned int returedNumb = 0;
public:
//  Constructor ---------------------------------------------------------------------------------------------------
  User(const Person &person);
//  Destructor ---------------------------------------------------------------------------------------------------
  virtual ~User();
//  Getters and setters ------------------------------------------------------------------------------------------
  const Person &getPerson() const;
  void setPerson(const Person &person);

  unsigned int getAllLoanNumb() const;
  void setAllLoanNumb(unsigned int allLoanNumb);

  unsigned int getCurrentlyLoan() const;
  void setCurrentlyLoan(unsigned int currentlyLoan);

  unsigned int getReturedNumb() const;
  void setReturedNumb(unsigned int returedNumb);
//  Other methods ---------------------------------------------------------------------------------------------------
  std::string toString();
  std::string toSave();
//  std::string historyToString();
//  void borrowPublication(PublicationPtr publication);
//  void returnPublication();

/*  const std::vector<PublicationPtr> &getHistoryOfUser() const;
  std::vector<PublicationPtr>::iterator getIteratorHistoryOfUser();
  std::string getHistory();*/
};

#endif //LIBRARYSYSTEM_USER_H
