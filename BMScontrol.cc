#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{

	users = new Dlist<User*>();
  	view    = new UImanager;
}

BMScontrol::~BMScontrol(){}

void BMScontrol::launch()
{
	int    choice, option;
	string code;
	
	while (1) {
		choice = -1;
		option = -1;
		/******  Main Menu ******/
		view->mainMenu(&choice);  
		User* user;
		view->login(&user, &choice);
		*users += user;
	   	if (choice == 0) { // clean up 
			user->getList().cleanupProducts();
			//delete  *user->getList();
			delete users;
			delete view;		
			break;
		}
		/* loads employee menu*/
		else if (choice == 1) {
	  			
			while(1){
				view->employeeMenu(&option);
				if( option == 0){
					break;
				}
				else if( option == 1){ // add book
					Product* newProduct;
					view->getBookData(&newProduct);
					 user->getList() += newProduct;
				}
				else if( option == 2){ // remove book
					Product* newProduct;
					view->getProduct(&newProduct, user->getList());
					 user->getList() -= newProduct;
				}
				else if(option == 3) { // add game
					Product* newProduct;
					view->getGameData(&newProduct);
					user->getList()+= newProduct;
				}
				else if( option == 4){ // remove game
					Product* newProduct;
					view->getProduct(&newProduct,  user->getList());
					 user->getList() -= newProduct;
				}
				else if( option == 5){ // add eReader 
					Product* newProduct;
					view->geteReaderData(&newProduct);
					user->getList() += newProduct;
				}
				else if( option == 6){ // remove eReader
					Product* newProduct;
					view->getProduct(&newProduct, user->getList());
					user->getList() -= newProduct;
				}
				else if( option == 7){ // add Writing
					Product* newProduct;
					view->getWritingData(&newProduct);
					user->getList() += newProduct;
				}
				else if( option == 8){ // remove Writing
					Product* newProduct;
					view->getProduct(&newProduct, user->getList());
					user->getList() -= newProduct;
				}
				else if(option == 9){ // print products
					view->printProducts(user->getList());
				}
				view->pause();
			}
  		}
			/* loads customer menu */
			else if (choice == 2) { 
				while(1){	
					view->customerMenu(&option);
					if( option == 0){
						break;
					}
					else if( option == 1){ // add book
						Product* newProduct;
						view->getBookData(&newProduct);
						user->getList() += newProduct;
					}
					else if( option == 2){ // remove book
						Product* newProduct;
						view->getProduct(&newProduct, user->getList());
						user->getList() -=newProduct;
					}
					else if(option == 3) { // add game
						Product* newProduct;
						view->getGameData(&newProduct);
						user->getList() += newProduct;
					}
					else if( option == 4){ // remove game
						Product* newProduct;
						view->getProduct(&newProduct, user->getList());
						user->getList() -= newProduct;
					}
					else if( option == 5){ // add eReader 
						Product* newProduct;
						view->geteReaderData(&newProduct);
						user->getList() += newProduct;
					}
					else if( option == 6){ // remove eReader
						Product* newProduct;
						view->getProduct(&newProduct, user->getList());
						user->getList() -= newProduct;
					}
					else if( option == 7){ // add Writing
						Product* newProduct;
						view->getWritingData(&newProduct);
						user->getList() += newProduct;
					}
					else if( option == 8){ // remove Writing
						Product* newProduct;
						view->getProduct(&newProduct, user->getList());
						user->getList() -= newProduct;
					}
					else if(option == 9){ // print products
						view->printProducts(user->getList());
					}
					view->pause();
				}
	  		}
			/* loads company menu*/
			else if (choice == 3) { 
				while(1){
					view->companyMenu(&option);
					if( option == 0){
						break;
					}
					else if( option == 1){ // add product ++++
						Product* newProduct;
						string type = user->getProduct();
						if (type == "Book"){
							view->getBookData(&newProduct);
						}
						else if (type == "Game"){
							view->getGameData(&newProduct);
						}
						else if (type == "eReader"){
							view->geteReaderData(&newProduct);
						}
						else if (type == "Writing"){
							view->getWritingData(&newProduct);
						}
						user->getList() += newProduct;
					}
					else if(option == 2) { // remove product   ******* 
						Product* newProduct;
						string type = user->getProduct();
						view->getProduct(&newProduct, user->getList());
						user->getList() -= newProduct;
					}
					else if(option == 3) { // change price 
					
						//user->getList() += newProduct;
					
					}
					else if(option == 4){  // print products  *** EDIT SO ONLY PRINTS 1 TYPE of PRODUCT
						view->printProducts(user->getList());
					}
				view->pause();
				}

			}
			/* loads teacher menu*/
			else if (choice == 4) {
				while(1){
					view->teacherMenu(&option);
					if( option == 0){
						break;
					}
					else if( option == 1){ // add single course
						Course* newCourse;
				  		view->getCourseData(&newCourse);
					//	user->add(newCourse);
					}
					else if(option == 2) { // remove single course
				
						Course* newCourse;
				 	 //	view->removeCourseData(&newCourse, user->getList());
					//	*courses -= newCourse;
					}
					else if (option == 3) {// add multiple courses
						Dlist<Course*> list;
						view->getCourses(list);
						view->printCourses(list);
						//*courses += list;
					}
					else if (option == 4) {//remove multiple courses
						Dlist<Course*> list;     		
					//	view->removeCourses(list, user->getList());
					//	*courses -= list;
		  			}
					else if (choice == 5) { // print courses
					//	view->printCourses(*courses);
					}
			   		else if (choice == 6){ // add Book  
						Book* newBook; 
						Product* newProduct;
					//	view->getBook(&newBook, user->getList());
						newProduct = newBook;
						user->getList() += newProduct;
			   		}
					else if (choice == 7) { // print books 
					//	view->printBooks(user->getList());
					}
				  view->pause();
				}
			 view->pause();
			}
		}	
}
