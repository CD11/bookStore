#include "Game.h"

Game::Game(string n,  int pr, string t, int pl): Product(n, pr)
{
	//cout << "  --- Toy ctor " << endl;
	name = n;
	price = pr;
	type   = t;
	players  = pl;
	
}

Game::~Game()
{
	//cout << "  --- Game dtor " << endl;
}

string 	Game::getType()    	{ return type; }
string 	Game::getName()    	{ return name; }
int    	Game::getPlayers() 	{ return players; }
int    	Game::getPrice()   	{ return price; }


