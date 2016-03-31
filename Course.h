#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {

  public:
    Course(string="", string="", string="", string="", int=0);
    ~Course();
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int     getNumBooks();
    void    addBook(Book*);
	void 	setBooks(BookArray*);
    BookArray* getBooks();

  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray* books;
};

#endif

