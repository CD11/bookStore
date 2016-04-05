#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"
#include "Course.h"
#include "User.h"


class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
	int getSize();
	int cartSize();
		
  private:
    UImanager*  view;
	Dlist<User*>*		users;
};

#endif
