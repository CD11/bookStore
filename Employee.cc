#include "Employee.h"

Employee::Employee(int ID, int discAmnt)
{
	cout << "  --- Employee ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	
}

Employee::~Employee()
{
	cout << "  --- Employee dtor " << endl;
}

double Employee::getDiscount()    { return discountAmnt; }
int    Employee::getId()   { return id; }

void Employee::addProduct(Product* item)
{
		products += item;

}

void Employee::removeProduct(Product* item)
{
		products -= item;

}

Product* User::searchProduct(string name)
{
	products->findProduct(name);
}
