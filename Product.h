#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"

/*	Purpose:
	This is a base class for all products sold by the book store.
	All products have a name and a price. 
	Product has the print method that will print the name and price of
	each produc in the store. 
*/

class Product {

  public:
    Product(string="", int=0);
	virtual ~Product();
    string 	getCode();
    int    	getPrice();
	string	print();

  private:
    string   name;
    int      price;

};

#endif

