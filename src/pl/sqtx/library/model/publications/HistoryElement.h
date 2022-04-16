//
// Created by Jakub Sitarczyk on 05/04/2022.
//

#ifndef LIBRARYSYSTEM_HISTORYELEMENT_H
#define LIBRARYSYSTEM_HISTORYELEMENT_H

#include "../../include/main_h.h"

class HistoryElement {
private:
  //TODO: Potęcjalnie może pojawić się tu jesszcze typ publikacji
  std::string elemTitle;
  std::string elemSecondPart; //Author of book/Date of publication for magazine
  std::string elemLoanDate;
  std::string elemReturnDate;
public:
//  Constructor ------------------------------------------------------------------------------------------
  HistoryElement(const std::string &elemTitle, const std::string &elemSecondPart, const std::string &elemLoanDate,
                 const std::string &elemReturnDate);
//  Destructor ------------------------------------------------------------------------------------------
  virtual ~HistoryElement();
//  Getters and setters ----------------------------------------------------------------------------------
//TODO: Możliwe, że wszytskie settery prócz return będą niepotrzebne
  const std::string &getElemTitle() const;
  void setElemTitle(const std::string &elemTitle);

  const std::string &getElemSecondPart() const;
  void setElemSecondPart(const std::string &elemSecondPart);

  const std::string &getElemLoanDate() const;
  void setElemLoanDate(const std::string &elemLoanDate);

  const std::string &getElemReturnDate() const;
  void setElemReturnDate(const std::string &elemReturnDate);

};

#endif //LIBRARYSYSTEM_HISTORYELEMENT_H
