#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>
#include "Dlist.h"
#include "defs.h"
#include "Product.h"
using namespace std;


/*	Purpose:
	This is a base class for all users that can use the bookstore management system
	All users have a discount percent and an id. 
	User has polymorphic methods: addProduct, removeProduct 
*/

class User {

  public:
    User();
	virtual ~User();
    int 	getCode(); // called getCode so it can be used to sort in the Dlist class
	double    	getDiscount();
    virtual void addProduct(Product*);
    virtual void removeProduct(Product*);
	virtual void printList(Dlist<Product*>&) = 0;
	virtual Dlist<Product*>& getList() = 0;
	virtual string getProduct() = 0;

  protected:
    int   id;
    double      discountAmnt;
    Dlist<Product*>*    products;//could be books, writing material, game, ereader


};

#endif
