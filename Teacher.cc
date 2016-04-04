#include "Teacher.h"

Teacher::Teacher(int ID, int discAmnt)
{
	cout << "  --- Teacher ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	  courses = new Dlist<Course*>();//a teacher can teach multiple courses
  books = new Dlist<Book*>();//a teacher can have a collection of required books for each course

	
}

//dont deallocate the list of courses and books here. should be done when user quits program.
Teacher::~Teacher()
{
	cout << "  --- Teacher dtor " << endl;
	// courses->cleanup();
	// books->cleanupProducts();
}

double Teacher::getDiscount()    { return discountAmnt; }
int    Teacher::getId()   { return id; }

void Teacher::addProduct(Book* book)
{
	courses += book;
}

void Teacher::addCourse(Course* newCourse)
{
	courses += newCourse;
}

void Teacher::addCourses(Course* newCourses)
{
	courses += newCourses;
}

void Teacher::removeCourse(Course* delCourse)
{
	courses -= delCourse;	
}

void Teacher::removeCourses(Dlist<Course*> delCourses)
{
	courses -= delCourses;	
}

Product* User::searchProduct(string name)
{
	products->findProduct(name);
}

