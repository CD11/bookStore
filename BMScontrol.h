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
	int cartSize();
		
  private:
    UImanager*  view;
    Dlist<Course*>*    courses;
	Dlist<Product*>*    products;
	Dlist<Product*>*    cart;
};

#endif
