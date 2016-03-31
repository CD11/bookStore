#include <iostream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray()
{ 
	//cout << "  --- BookArray ctor " << endl;
	int i; 
	for(i = 0; i<MAX_BOOKS; i++){
	 books[i] = NULL;
	}
 	size = 0;
}

BookArray::~BookArray()
{
	//cout << "  --- BookArray dtor " << endl;
}	

int   BookArray::getSize()        { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Book* book)
{
  if (size == MAX_BOOKS)
    return;

  books[size] = book;
  size++;
}

