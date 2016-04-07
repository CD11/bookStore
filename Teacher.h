#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"
#include "User.h"
#include "Product.h"
#include "Dlist.h"
/*  Purpose:
    This is a derived class for Teacher that can use the bookstore management system
    All Teachers have a discount percent, id. 
    Employee has polymorphic methods: view, addProduct, removeProduct (from the main list)
*/

class Teacher: public User
{

  public:
    Teacher(int=0, double=0.00);//id, discountAmnt (in decimal)
    virtual ~Teacher();
    int     getCode(); // called getCode so it can be used to sort in the Dlist class
    void    addCourse(Course*);
    void    removeCourse(Course*);
    virtual Dlist<Course*>& getCourses();
    virtual void searchCourse(string, Course*);
    virtual void printCourses(Dlist<Course*>&);
    void    addBook(string, Book*, Course*);
    void    removeBook(string, Book*, Course*);
    virtual string getCourse();

  private:
    int     id;
    double discountAmnt;
    Dlist<Product*>*    courses;

};

#endif

