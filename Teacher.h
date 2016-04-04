#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"

/*	Purpose:
	This is a derived class for teachers that can use the bookstore management system
	All teachers have a discount percent, id. 
	Teacher has polymorphic methods: view, addProduct, removeProduct, addCourse, removeCourse (from the main list)
*/

class Teacher {

  public:
    Teacher(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~Teacher();
    int 	getId();
         void addProduct(string, Book*);
     void removeProduct(string, string);
     void addCourse(Course*);
     void removeCourse(string);
     void searchProduct(string);//search for course by course code or textbook by isbn

    double    	getDiscount();

  private:
    int   id;
    double      discountAmnt;
        Dlist<Product*>*    courses;

};

#endif

