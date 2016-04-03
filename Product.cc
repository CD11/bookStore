#include "Product.h"

Product::Product(string n, int p)
{
	//cout << "  --- Product ctor " << endl;
	int i; 
	name   = n;
	price  = p;
	
}

Product::~Product()
{
	//cout << "  --- Product dtor " << endl;
}

string Product::getCode()    { return name; }
int    Product::getPrice()   { return price; }
string   Product::print()     
{
	stringstream ss;  
	ss << price ;
	string p = ss.str(); 
	return "name: " + name + ", price: $" + p;
}

