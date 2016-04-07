#include "Employee.h"

Employee::Employee(int ID, double discAmnt)
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
int    Employee::getCode()   { return id; }// called getCode so it can be used to sort in the Dlist class

void Employee::printList(Dlist<Product*>& p){
	string s = "" ;
	cout<< " Printing Products " << endl;
	p.printProducts(s, p);
    cout << s << endl<<endl;
}
