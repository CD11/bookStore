#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  courses = new Dlist<Course*>();
  view    = new UImanager;
  int i; 
  for(i = 0; i<MAX_BOOKS; i++){
	 products[i] = NULL;
   }
  numProducts = 0; 
}

BMScontrol::~BMScontrol(){}



void BMScontrol::launch()
{
	int    choice;
	string code;
	
	while (1) {
		choice = -1;
   		view->mainMenu(&choice);
   		if (choice == 0) { // clean up 
			view->cleanUpProducts(products, numProducts);
			courses->cleanup();
			delete courses;
			delete view;		
			break;
    	}
    	else if (choice == 1) { // add single course
			Course* newCourse;
      		view->getCourseData(&newCourse);
			*courses += newCourse;
  		}
		else if (choice == 2) { // add multiple courses
			Dlist<Course*> list;
			view->getCourses(list);
			//view->printCourses(list);
			*courses += list;	
  		}
		else if (choice == 3) { // remove single course
			Course* newCourse;
     	 	view->removeCourseData(&newCourse, *courses);
			*courses -= newCourse;
    	}
		else if (choice == 4) {// remove multiple courses
			Dlist<Course*> list;     		
			view->removeCourses(list, *courses);
			*courses -= list;
  		}
    	else if (choice == 5) { // print courses
			view->printCourses(*courses);
		}
   		else if (choice == 6){ // add Book  
			Book* newBook; 
			view->getBook(&newBook, *courses);
			products[numProducts++] = newBook;
   		}
    	else if (choice == 7) { // print books 
			view->printBooks(*courses);
    	}
		else if (choice == 8){ // add Product  
			Product* newProduct;
			view->getProductData(&newProduct);
			products[numProducts++] = newProduct;
   		}
		else if (choice == 9){ // print Product  
			view->printProducts(products, numProducts);
   		}
    view->pause();
  }
}

