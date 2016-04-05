#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"
#include "User.h"
#include "Book.h"
#include "Course.h"
#include "Product.h"
#include "Dlist.h"

/*	Purpose:
	This is a derived class for teachers that can use the bookstore management system
	All teachers have a discount percent, id. 
	Teacher has polymorphic methods: view, addProduct, removeProduct, addCourse, removeCourse (from the main list)
*/

class Teacher :public User
{

  public:
    Teacher(int=0, double=0.00);//id, discountAmnt (in decimal)
	virtual ~Teacher();
    int 	getCode();
	double  getDiscount();
    void	addBook(Course*, Book*);
    void 	add(Course*);
	void	addMany(Dlist<Course*>&);
	void 	remove(Course*);
	void	removeMany(Dlist<Course*>&);
   // virtual void 	searchProduct(string);//search for course by course code or textbook by isbn
    void 	addProduct(Product*);
    void 	removeProduct(Product*);
	virtual Dlist<Product*>& getList();
	virtual void searchProduct(string, Product*);
	virtual void printList(Dlist<Product*>&);
	virtual string getProduct();
  private:
    int   id;
    double      discountAmnt;
    Dlist<Course*>*    courses;
};

#endif
