#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "Game.h"
#include "Ereader.h"
#include "Writing.h"
#include "Course.h"


#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);
	void getCourses(Dlist<Course*>&);
	void removeCourseData(Course**, Dlist<Course*>&);
	void removeCourses(Dlist<Course*>&, Dlist<Course*>&);
	void getBook(Book**, Dlist<Course*>&);
	void getBookData(Book**);
    void printCourses(Dlist<Course*>&);
	void printBooks(Dlist<Course*>&);
    void pause();
	void getCourse(Dlist<Course*>&);
	string formatForward(Dlist<Course*>&);
	string formatReverse(Dlist<Course*>&);
	void   getProductData(Product**);
	void   printProducts(Product**, int);
	void   cleanUpProducts(Product**, int);
  private:
    int getInt();
};

#endif

