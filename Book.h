#ifndef BOOK_H
#define BOOK_H

#include "defs.h"
#include "Product.h"

/*	Purpose:
	This is a derived class of products for Books
	All books have a title, author, ISBN, Edition, and year
	Books are stored in the products array as well as in 
	a bookarry for courses. 
*/

class Book : public Product
{

  public:
    Book(string="", string="", string="", int=1, int=0, int=0);
	virtual ~Book();
    string  getTitle();
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    int     getYear();
	int     getPrice();

  private:
    string    title;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
	int		  price;
};

#endif

