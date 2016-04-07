#include "User.h"

User::User(int ID, double discAmnt)
{
	cout << "  --- User ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	
}

User::~User()
{
	cout << "  --- User dtor " << endl;
}

double User::getDiscount()    { return discountAmnt; }
int    User::getId()   { return id; }

void User::removeProduct(Product* item)
{
	*products -= item;
}

void User::addProduct(Product* item)
{
	*products += item;
}

void User::searchProduct(string name, Product* p)
{
	p = *products->findObj(name);
}
