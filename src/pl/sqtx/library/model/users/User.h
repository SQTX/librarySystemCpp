//
// Created by Jakub Sitarczyk on 25/03/2022.
//

#ifndef LIBRARYSYSTEM_USER_H
#define LIBRARYSYSTEM_USER_H

#include "../../include/main_h.h"
#include "Person.h"
#include "../../include/publicationType_h.h"
#include "../../model/publications/publication.h"
#include "../../model/publications/HistoryElement.h"

typedef std::shared_ptr<Publication> PublicationPtr;

class User : public Person{
private:
  std::vector<PublicationPtr> borrowedPublications;
  std::vector<HistoryElement> userHistory;
  unsigned int allLoanNumb = 0;
  unsigned int currentlyLoan = 0;
  unsigned int returnedNumb = 0;
public:
//  Constructor ---------------------------------------------------------------------------------------------------
  User(const std::string &firstName, const std::string &lastName, const std::string &pesel);
//  Destructor ---------------------------------------------------------------------------------------------------
  virtual ~User();
//  Getters and setters ------------------------------------------------------------------------------------------
  const std::vector<HistoryElement> &getUserHistory() const;

  unsigned int getAllLoanNumb() const;
  void setAllLoanNumb(unsigned int allLoanNumb);

  unsigned int getCurrentlyLoan() const;
  void setCurrentlyLoan(unsigned int currentlyLoan);

  unsigned int getReturnedNumb() const;
  void setReturnedNumb(unsigned int returnedNumb);
//  Other methods ---------------------------------------------------------------------------------------------------
  std::string toString(); //Prepare data to printout
  std::string toSave(); //Perpere data to save
  std::string toSaveUserHistory(int i); //Perpere history of usert to save
  /**Functions that push data to a vector.*/
  void addBorrowedPublications(PublicationPtr publication);
  void addHistoryElement(HistoryElement historyElement);
  /**Saves the loan in the user's history. Updates statistics.*/
  void lendPublication(PublicationPtr publication, HistoryElement historyElement);
  /**I assign a return date to user history. Updates statistics.*/
  void returnPublication(std::string title, std::string secondPart, std::string time);
};

#endif //LIBRARYSYSTEM_USER_H
