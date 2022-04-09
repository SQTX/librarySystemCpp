//
// Created by Jakub Sitarczyk on 05/04/2022.
//

#include "HistoryElement.h"

HistoryElement::HistoryElement(const std::string &elemTitle, const std::string &elemSecondPart,
                               const std::string &elemLoanDate, const std::string &elemReturnDate = "0") {
  this->elemTitle = elemTitle;
  this->elemSecondPart = elemSecondPart;
  this->elemLoanDate = elemLoanDate;
  this->elemReturnDate = elemReturnDate;
}

HistoryElement::~HistoryElement() {

}

const std::string &HistoryElement::getElemTitle() const {
  return elemTitle;
}

void HistoryElement::setElemTitle(const std::string &elemTitle) {
  HistoryElement::elemTitle = elemTitle;
}

const std::string &HistoryElement::getElemSecondPart() const {
  return elemSecondPart;
}

void HistoryElement::setElemSecondPart(const std::string &elemSecondPart) {
  HistoryElement::elemSecondPart = elemSecondPart;
}

const std::string &HistoryElement::getElemLoanDate() const {
  return elemLoanDate;
}

void HistoryElement::setElemLoanDate(const std::string &elemLoanDate) {
  HistoryElement::elemLoanDate = elemLoanDate;
}

const std::string &HistoryElement::getElemReturnDate() const {
  return elemReturnDate;
}

void HistoryElement::setElemReturnDate(const std::string &elemReturnDate) {
  HistoryElement::elemReturnDate = elemReturnDate;
}
