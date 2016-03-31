#ifndef GAME_H
#define GAME_H

#include "defs.h"
#include "Product.h"

/*	Purpose:
	This is a derived class of products for Game
	All Games have a name and a type (e.g. puzzle, boardgame, partygame)
*/
class Game : public Product
{

  public:
    Game(string="", int=0, string="", int=0);
	virtual ~Game();
    string  getName();
    int     getPrice();
	string  getType();
    int 	getPlayers();

  private:
    string    name;
    int       price;
	string    type;
	int 	  players;

};

#endif

