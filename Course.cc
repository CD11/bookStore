#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
   //cout << "  --- Course ctor " << endl;
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
   books = NULL;
}

Course::~Course()
{ 
 //cout << "  --- Course dtor " << endl;	
}


string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }
int    Course::getNumBooks()  { return books->getSize(); }
BookArray* Course::getBooks()  { return books;} 
void Course::setBooks(BookArray* b){
	books = b;
}
void   Course::addBook(Book* b)  
{ 
  books->add(b);
}

