#include "Book.h"

Book::Book(string t, string a, string i, int e, int y, int p):Product(t, p)
{
	//cout << "  --- Book ctor " << endl;
	title   = t;
	authors = a;
	isbn    = i;
	edition = e;
	year    = y;
	price   = p;
}

Book::~Book()
{
	//cout << "  --- Book dtor " << endl;
}

string 	Book::getTitle()    { return title; }
string 	Book::getAuthors()  { return authors; }
string 	Book::getISBN()     { return isbn; }
int    	Book::getEdition()  { return edition; }
int    	Book::getYear()     { return year; }
int    	Book::getPrice()    { return price; }



