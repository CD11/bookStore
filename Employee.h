#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"
#include "User.h"
#include "Product.h"
#include "Dlist.h"

/*	Purpose:
	This is a derived class for employees that can use the bookstore management system
	All employees have a discount percent, id. 
	Employee has polymorphic methods: view, addProduct, removeProduct (from the main list)
*/

class Employee: public User{

  public:
    Employee(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~Employee();
    int 	getCode(); // called getCode so it can be used to sort in the Dlist class
 	double  getDiscount();
    void 	addProduct(Product*);
    void 	removeProduct(Product*);
	virtual Dlist<Product*>& getList();
	virtual void searchProduct(string, Product*);
	virtual void printList(Dlist<Product*>&);
	virtual string getProduct();
  private:
    int   		id;
    double      discountAmnt;

};

#endif
