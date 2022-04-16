//
// Created by Jakub Sitarczyk on 11/03/2022.
//

#ifndef LIBRARYSYSTEM_BOOK_H
#define LIBRARYSYSTEM_BOOK_H

/*Headers*/
#include "publication.h"

//*********************************************************************************************************************
class Book : public Publication {
private:
  std::string author;
  int pages;
  std::string isbn;

public:
//    Constructors  ---------------------------------------------------------------------
  Book(std::string title, std::string author, int releaseDate, int pages, std::string publisher, std::string isbn);

//    Destructors  ---------------------------------------------------------------------
  virtual ~Book();

//  Getter and Setter  ---------------------------------------------------------------------
  const std::string &getAuthor() const;
  void setAuthor(const std::string &author);

  int getPages() const;
  void setPages(int pages);

  const std::string &getIsbn() const;
  void setIsbn(const std::string &isbn);

  //  Equals  ---------------------------------------------------------------------
  bool operator==(const Book &rhs) const;
  bool operator!=(const Book &rhs) const;

//    Methods  ---------------------------------------------------------------------
  /**Create string-line with the information about Book object.*/
  std::string toString() override;
  /**Create string-line with the information arranged for data export.*/
  std::string toSave() override;
};

#endif //LIBRARYSYSTEM_BOOK_H
