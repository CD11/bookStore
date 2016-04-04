#include "User.h"

User::User(int ID, int discAmnt)
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
	products->remove(item);
}

void User::addProduct(Product* item)
{
	products->add(item);
}

Product* User::searchProduct(string name)
{
	products->findProduct(name);
}