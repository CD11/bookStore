#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"
#include "User.h"
#include "Product.h"
#include "Dlist.h"
/*	Purpose:
	This is a derived class for customer that can use the bookstore management system
	All customers have a discount percent, id. 
	Employee has polymorphic methods: view, addProduct, removeProduct (from the main list)
*/

class Customer: public User
{

  public:
    Customer(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~Customer();
    int 	getCode(); // called getCode so it can be used to sort in the Dlist class
	double  getDiscount();
    void 	addProduct(Product*);
    void 	removeProduct(Product*);
	virtual Dlist<Product*>& getList();
	virtual void searchProduct(string, Product*);
	virtual void printList(Dlist<Product*>&);
	virtual string getProduct();

  private:
    int   	id;
    double	discountAmnt;
	Dlist<Product*>*    cart;

};

#endif

