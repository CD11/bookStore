#include "Teacher.h"

Teacher::Teacher(int ID, double discAmnt)
{
	cout << "  --- Teacher ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	courses = new Dlist<Course*>();
	
}

Teacher::~Teacher()
{
	cout << "  --- Teacher dtor " << endl;
}

double Teacher::getDiscount()    { return discountAmnt; }
int    Teacher::getCode()   { return id; } // called getCode so it can be used to sort in the Dlist class

void Teacher::addCourse(Course* c)
{
		*courses += c;

}

void Teacher::removeCourse(Course* c)
{
		*courses -= c;

}

void Teacher::addBook(string name, Book* b, Course* c)
{
	c = *courses->findObj(name);
	c->addBook(b);
}

void Teacher::searchCourse(string name, Course* c)
{
	c = *courses->findObj(name);
}

void Teacher::printCourses(Dlist<Course*>& c){
	string s = "";
	cout << " Printing Courses " << endl;
	for (int i=0; i<c.getSize(); i++)
	{
		Course** course = c.getObj(i);//returns a pointer
		s += c.formatString(&course);//takes a course double pointer
	}
    cout << s << endl << endl;
}


Dlist<Course*>& Teacher::getCourses(){
	return *courses;
}
string Teacher::getCourse() { return 0; }
