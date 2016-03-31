#include "Ereader.h"

Ereader::Ereader(string n, int p, string b, int s):Product(n, p)
{
	//cout << "  --- eReader ctor " << endl;
	name    = n;
	price   = p;
	brand   = b;
	storage = s;
}	

Ereader::~Ereader()
{
	//cout << "  --- eReader dtor " << endl;
}

string 	Ereader::getName()      { return name; }
int    	Ereader::getPrice()     { return price; }
string	Ereader::getBrand()     { return brand; }
int	    Ereader::getStorage()   { return storage; }


