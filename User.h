#include "User.h"

User::User()
{
		
  	products = new Dlist<Product*>();
	
}

User::~User()
{
	cout << "  --- User dtor " << endl;
}

double User::getDiscount()    { return discountAmnt; }
int    User::getCode()   { return id; } // Called get Code so it can be used to sort in the Dlist Class.

void User::removeProduct(Product* item)
{
	*products  -= item;
}

void User::addProduct(Product* item)
{
	*products -= item;
}








