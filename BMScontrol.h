#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"
#include "Course.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
	int getSize();
		
  private:
    UImanager*  view;
    Dlist<Course*>*    courses;
    Product* 	products[MAX_BOOKS];
	int 		numProducts;

};

#endif

