#ifndef EREADER_H
#define EREADER_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

/*	Purpose:
	This is a derived class of products for eReaders
	All eReaders have a name such as Kindle, or Ipad and brand such as Apple or Samsung
*/
class Ereader : public Product
 {

  public:
    Ereader(string="", int=0, string="", int=0);
	virtual ~Ereader();
    string  getName();
    int     getPrice();
	string	getBrand();
	int 	getStorage();
	
	
  private:
    string   name;
    int      price;
	string 	 brand;
	int		 storage; 
};

#endif

