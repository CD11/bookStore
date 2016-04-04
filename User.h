#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>
#include "Dlist.h"
#include "defs.h"
using namespace std;


/*	Purpose:
	This is a base class for all users that can use the bookstore management system
	All users have a discount percent and an id. 
	User has polymorphic methods: addProduct, removeProduct 
*/

class User {

  public:
    User(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~User();
    int 	getId();
    virtual void addProduct(Product*);
    virtual void removeProduct(Product*);
    double    	getDiscount();
    virtual Product* searchProduct(string) = 0;

  private:
    int   id;
    double      discountAmnt;
    Dlist<Product*>*    products;//could be books, writing material, game, ereader


};

#endif

