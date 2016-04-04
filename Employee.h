#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"

/*	Purpose:
	This is a derived class for employees that can use the bookstore management system
	All employees have a discount percent, id. 
	Employee has polymorphic methods: view, addProduct, removeProduct (from the main list)
*/

class Employee {

  public:
    Employee(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~Employee();
    int 	getId();
         void addProduct(Product*);
     void removeProduct(Product*);
    double    	getDiscount();

  private:
    int   id;
    double      discountAmnt;

};

#endif

