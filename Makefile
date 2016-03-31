OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o Product.o Game.o Ereader.o Writing.o

a3:	$(OBJ)
	g++ -o  a4 $(OBJ)

main.o:	main.cc 
	g++ -c -g main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h Dlist.h
	g++ -c  -g BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h Dlist.h
	g++ -c  -g UImanager.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c  -g BookArray.cc

Course.o:	Course.cc Course.h defs.h 
	g++ -c  -g Course.cc

Book.o:	Book.cc Book.h defs.h Product.h
	g++ -c  -g Book.cc

Product.o:	Product.cc Product.h defs.h
	g++ -c  -g Product.cc

Game.o:	Game.cc Game.h Product.h
	g++ -c  -g Game.cc

Ereader.o:	Ereader.cc Ereader.h Product.h
	g++ -c  -g Ereader.cc

Writing.o:	Writing.cc Writing.h Product.h
	g++ -c  -g Writing.cc

clean:
	rm -f *.o a4

