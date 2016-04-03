#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  courses = new Dlist<Course*>();
  products = new Dlist<Product*>();
  cart = new Dlist<Product*>();
  view    = new UImanager;
}

BMScontrol::~BMScontrol(){}

void BMScontrol::launch()
{
	int    choice, option;
	string code, user;
	
	while (1) {
		choice = -1;
		option = -1;
			/******  Main Menu ******/
   		view->mainMenu(&choice);  
   		if (choice == 0) { // clean up 
			products->cleanupProducts();
			cart->cleanupProducts();
			courses->cleanup();

			delete courses;
			delete products;
			delete cart;
			delete view;		
			break;
    	}
		/* loads employee menu*/
    	else if (choice == 1) {  
			while(option != 0){
				view->employeeMenu(&option);
				if( option == 0){
				}
				else if( option == 1){ // add book
					Product* newProduct;
					view->getBookData(&newProduct);
					*products += newProduct;
				}
				else if( option == 2){ // remove book ***** 
					Product* newProduct;
					view->getProduct(&newProduct, *products);
					*products -= newProduct;
				}
				else if(option == 3) { // add game
					Product* newProduct;
					view->getGameData(&newProduct);
					*products += newProduct;
				}
				else if( option == 4){ // remove game *********
					Product* newProduct;
					view->getProduct(&newProduct,  *products);
					*products -= newProduct;
	
				}
				else if( option == 5){ // add eReader 
					Product* newProduct;
					view->geteReaderData(&newProduct);
					*products += newProduct;
				}
				else if( option == 6){ // remove eReader *****
					Product* newProduct;
					view->getProduct(&newProduct, *products);
					*products -= newProduct;
				}
				else if( option == 7){ // add Writing
					Product* newProduct;
					view->getWritingData(&newProduct);
					*products += newProduct;
				}
				else if( option == 8){ // remove Writing ******
					Product* newProduct;
					view->getProduct(&newProduct, *products);
					*products -= newProduct;
				}
				else if(option == 9){ // print products
					view->printProducts(*products);
				}
			}	
  		}
		/* loads customer menu */
		else if (choice == 2) { 
			while(option != 0){
				view->customerMenu(&option);
					if( option == 0){
				}
				else if( option == 1){ // add book
					Product* newProduct;
					view->getBookData(&newProduct);
					*cart += newProduct;
				}
				else if( option == 2){ // remove book ***** 
					Product* newProduct;
					view->getBookData(&newProduct);
					*cart -=newProduct;
				}
				else if(option == 3) { // add game
					Product* newProduct;
					view->getGameData(&newProduct);
					*cart += newProduct;
				}
				else if( option == 4){ // remove game *********
					Product* newProduct;
					view->getBookData(&newProduct);
					*cart -= newProduct;
				}
				else if( option == 5){ // add eReader 
					Product* newProduct;
					view->geteReaderData(&newProduct);
					*cart += newProduct;
				}
				else if( option == 6){ // remove eReader *****
					Product* newProduct;
					view->getBookData(&newProduct);
					*cart -= newProduct;
				}
				else if( option == 7){ // add Writing
					Product* newProduct;
					view->getWritingData(&newProduct);
					*cart += newProduct;
				}
				else if( option == 8){ // remove Writing ******
					Product* newProduct;
					view->getBookData(&newProduct);
					*cart -= newProduct;
				}
				else if(option == 9){ // print products
					view->printProducts(*cart);
				}
			}
  		}
		/* loads company menu*/
		else if (choice == 3) { 
			while(option != 0){
				view->companyMenu(&option);
				if( option == 0){
				}
				else if( option == 1){ // add product ++++
					//Product* newProduct;
					//view->getProductData(&newProduct);
					//products[numProducts++] = newProduct;
				}
				else if(option == 2) { // remove product   ******* 
	
				}
				else if(option == 3) { // change price 
				}
				else if(option == 4){  // print products  *** EDIT SO ONLY PRINTS 1 TYPE of PRODUCT
					//view->printProducts(products, numProducts);
				}
			}
    	}
		/* loads teacher menu*/
		else if (choice == 4) { 
			while(option != 0){
				view->teacherMenu(&option);
				if( option == 0){
				}
				else if( option == 1){ // add single course
					Course* newCourse;
			  		view->getCourseData(&newCourse);
					*courses += newCourse;
				}
				else if(option == 2) { // remove single course
				
					Course* newCourse;
			 	 	view->removeCourseData(&newCourse, *courses);
					*courses -= newCourse;
				}
				else if (option == 3) {// add multiple courses
					Dlist<Course*> list;
					view->getCourses(list);
					view->printCourses(list);
					*courses += list;
				}
				else if (option == 4) {//remove multiple courses
					Dlist<Course*> list;     		
					view->removeCourses(list, *courses);
					*courses -= list;
	  			}
				else if (choice == 5) { // print courses
					//view->printCourses(*courses);
				}
		   		else if (choice == 6){ // add Book  
					Book* newBook; 
					Product* newProduct;
					view->getBook(&newBook, *courses);
					//products[numProducts++] = newBook;
					newProduct = newBook;
					*products += newProduct;
		   		}
				else if (choice == 7) { // print books 
					view->printBooks(*courses);
				}
			}
		 view->pause();
		}		

  view->pause();
  }
}
