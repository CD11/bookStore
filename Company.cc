#include "Company.h"

Company::Company(int ID, double discAmnt, string p)
{
	cout << "  --- Company ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	product = p;
	prodList = new Dlist<Product*>();
}

Company::~Company()
{
	cout << "  --- Company dtor " << endl;
}

double Company::getDiscount()    { return discountAmnt; }
int    Company::getCode()   { return id; }// called getCode so it can be used to sort in the Dlist class
string Company::getProduct() { return product;}
void Company::addProduct(Product* item)
{
		*products += item;

}

void Company::removeProduct(Product* item)
{
		*products -= item;

}

void Company::searchProduct(string name, Product* p)
{
	p = *products->findObj(name);
}

void Company::printList(Dlist<Product*>& p){
	string s = "" ;
	cout<< " Printing Products " << endl;
	p.printProducts(s, p);
    cout << s << endl<<endl;
}

Dlist<Product*>& Company::getList(){
	
	for(int i = 0; i < products->getSize(); i++){
		Product* p = *products->getObj(i);
		if(p->getProduct() == product){
				*prodList += p;	
		}
	}
	return *prodList;
}

