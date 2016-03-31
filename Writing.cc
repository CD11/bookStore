#include "Writing.h"

using namespace std;


Writing::Writing(string n, int p, string c, string i): Product(n,p)
{
	//cout << "  --- Writing ctor " << endl;
	name   = n;
	price  = p;
	color  = c;
	implement   = i;
}

Writing::~Writing()
{
	//cout << "  --- Writing dtor " << endl;
}

string 	Writing::getName()		{ return name; }
int    	Writing::getPrice()		{ return price; }
string	Writing::getColor()		{ return color; }
string	Writing::getImplement() { return implement; }


