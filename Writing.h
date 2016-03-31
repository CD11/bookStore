#ifndef WRITING_H
#define WRITING_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

/*	Purpose:
	This is a derived class of products for writing implements
	All writing implments have a form of implementation (e.g. pen, marker) 
	as well as a color. 
*/
class Writing: public Product
{

  public:
	Writing(string="", int=0, string="", string="");
	virtual ~Writing();
    string  getName();
    int    	getPrice();
	string	getColor();
	string	getImplement();

  private:
    string  name;
    int     price;
	string 	color;
	string	implement;
};

#endif

