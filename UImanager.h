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
	void employeeMenu(int*);
	void customerMenu(int*);
	void companyMenu(int*);
	void teacherMenu(int*);
	void login(string*);
    void getCourseData(Course**);
	void getCourses(Dlist<Course*>&);
	void removeCourseData(Course**, Dlist<Course*>&);
	void removeCourses(Dlist<Course*>&, Dlist<Course*>&);
	void getBook(Book**, Dlist<Course*>&);
	void getBookData(Product**);
	void getGameData(Product**);
	void geteReaderData(Product**);
	void getWritingData(Product**);
	void getProduct(Product**, Dlist<Product*>&);
    void printCourses(Dlist<Course*>&);
	void printBooks(Dlist<Course*>&);
    void pause();
	void getCourse(Dlist<Course*>&);
	string formatForward(Dlist<Course*>&);
	string formatReverse(Dlist<Course*>&);
	void   printProducts(Dlist<Product*>&);
	void   cleanUpProducts(Product**, int);
  private:
    int getInt();
};

#endif
