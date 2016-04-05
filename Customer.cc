#include "Customer.h"

Customer::Customer(int ID, double discAmnt)
{
	cout << "  --- Customer ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	cart = new Dlist<Product*>();
	
}

Customer::~Customer()
{
	cout << "  --- Customer dtor " << endl;
}

double Customer::getDiscount()    { return discountAmnt; }
int    Customer::getCode()   { return id; } // called getCode so it can be used to sort in the Dlist class

void Customer::addProduct(Product* item)
{
		*cart += item;

}

void Customer::removeProduct(Product* item)
{
		*cart -= item;

}

void Customer::searchProduct(string name, Product* p)
{
	p = *products->findObj(name);
}


void Customer::printList(Dlist<Product*>& p){
	string s = "" ;
	cout<< " Printing Products " << endl;
	p.printProducts(s, p);
    cout << s << endl<<endl;
}


Dlist<Product*>& Customer::getList(){
	return *cart;
}
string Customer::getProduct() { return NULL; }
