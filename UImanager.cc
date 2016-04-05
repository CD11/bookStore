#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

/*	Purpose:	Outputs a menu to the screen

*/
void UImanager::mainMenu(int* choice)
{
	string str;

	*choice = -1;

	cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
	cout << "  Login as a user " << endl;
	cout << "  ( 1 )  Employee" << endl;
	cout << "  ( 2 )  Customer" << endl;
	cout << "  ( 3 )  Product Company " << endl;
	cout << "  ( 4 )  Teacher" << endl;
	cout << "  ( 0 )  Exit" << endl << endl;
	while (*choice < 0 || *choice > 4) {
		cout << "Enter your selection:  ";
		*choice = getInt();
	}
}


/*	Purpose:	Outputs the employee menu to the screen

*/
void UImanager::employeeMenu(int* choice)
{
	string str;

	*choice = -1;
	
	cout << endl << endl << "Welcome Employee" << endl<<endl;
	cout << "  Product Management:" << endl;
	cout << "  ( 1 )  Add a Book" << endl;
	cout << "  ( 2 )  Remove a Book" << endl;
	cout << "  ( 3 )  Add a Game" << endl;
	cout << "  ( 4 )  Remove a Game" << endl;
	cout << "  ( 5 )  Add an eReader " << endl;	
	cout << "  ( 6 )  Remove a eReader" << endl;
	cout << "  ( 7 )  Add a writing object" << endl;
	cout << "  ( 8 )  Remove a Writing object" << endl;
	cout << "  ( 9 )  Print Products " << endl;
	cout << "  ( 0 )  Exit" << endl << endl;
	while (*choice < 0 || *choice > 9) {
		cout << "Enter your selection:  ";
		*choice = getInt();
	}
}

/*	Purpose:	Outputs a company menu to the screen

*/
void UImanager::companyMenu(int* choice)
{
	*choice = -1;
	cout << endl << endl << "Welcome Company" << endl<<endl;
	cout << "  ( 1 )  Add Product" << endl;
	cout << "  ( 2 )  Remove Prodct" << endl;
	cout << "  ( 3 )  Change price"  <<endl;
	cout << "  ( 4 )  Print Products" << endl;
	cout << "  ( 0 )  exit "<< endl<< endl;
	while (*choice < 0 || *choice > 4) {
		cout << "Enter your selection:  ";
		*choice = getInt();
	}
}

/*	Purpose:	Outputs the client menu to the screen

*/
void UImanager::customerMenu(int* choice)
{
	string str;

	*choice = -1;
	cout << endl << endl << "Welcome Customer" << endl<<endl;
	cout << "  ( 1 )  Add a Book to cart" << endl;
	cout << "  ( 2 )  Remove a Book from cart" << endl;
	cout << "  ( 3 )  Add a Game to cart" << endl;
	cout << "  ( 4 )  Remove a Game from cart" << endl;
	cout << "  ( 5 )  Add an eReader to cart " << endl;	
	cout << "  ( 6 )  Remove a eReader from cart" << endl;
	cout << "  ( 7 )  Add a writing object to cart" << endl;
	cout << "  ( 8 )  Remove a Writing object from cart" << endl;
	cout << "  ( 9 ) Print cart " << endl;
	cout << "  ( 0 )  Exit" << endl << endl;
	while (*choice < 0 || *choice > 9) {
		cout << "Enter your selection:  ";
		*choice = getInt();
	}
}


/*	Purpose:	Outputs the client menu to the screen

*/
void UImanager::teacherMenu(int* choice)
{

cout << endl << endl << "Welcome Teacher" << endl<<endl;
	cout << "  Course Management:" << endl;
	cout << "  ( 1 )  Add single course" << endl;
	cout << "  ( 2 )  Add multiple courses" << endl;
	cout << "  ( 3 )  Remove course " << endl;
	cout << "  ( 4 )  Remove multiple courses" << endl;
	cout << "  ( 5 )  List all courses" << endl << endl;
	cout << "  Textbook Management:" << endl;
	cout << "  ( 6 )  Add textbook" << endl;	
	cout << "  ( 7 )  List course textbooks" << endl << endl;
	cout << "  ( 0 )  exit "<< endl<< endl;
	while (*choice < 0 || *choice > 7) {
		cout << "Enter your selection:  ";
		*choice = getInt();
	}
}


/* Purpose:  Verifies that the users login 
   Params: 	 Takes a string
*/
void UImanager::login(User** user, int* choice){
	string str = "";
	string p = "";
	string sub = "";
	string num = "";
	int n1;
	int n2;
	int id;


	while (1) {
		while(str.length() != 9 ) {
			cout << "Enter your user ID: "; 
			getline(cin, str);
			sub = str.substr(0,3);
	  		num  = str.substr(6);
			stringstream s1(sub);
			s1 >> n1;
			stringstream s2(num);
			s2 >> n2;
			stringstream s3(str);
			s3 >> id;
		}
		if (*choice == 1 && n1 == 100 ){	
			*user = new Employee(id, 0.10);
			cout << " Employee Logged in ";
			break;
		}
		else if (*choice == 2 && n1 == 200){
			*user = new Customer(id, 0.00);
			cout << " Customer Logged in:";
			break;
		}	
		else if (*choice == 3 && n1 == 300){
			cout << "Enter your product type (e.g. Writing): "; 
			getline(cin, str);
			*user = new Company(id, 0.25, str );
			cout << " Comapny Logged in ";
			break;
		}
		else if (*choice == 4 && n1 ==400 ){
			*user = new Teacher(id, 0.20);
			cout<< " Teacher Logged in ";
			break;
		} else {
			cout << " invalid "<< endl;
			str = "";
		}

	}
		
	
}

/*	Purpose:	Get data and creates a new course object as well as allocate 
				a bookArray for each course
	Params:		Takes the course pointer 
*/
void UImanager::getCourseData(Course** course)
{
	string    str = "";
	string    subj, num, name, inst;
	int       enrol;
	cout << endl;

	while (str.length() != 8) {
		cout << "Enter course code (e.g. COMP2404):  ";
   		getline(cin, str);
  	}
 	subj = str.substr(0,4);
  	num  = str.substr(4);

  	cout << endl << "Enter course name (e.g. Introduction to SE):  ";
	getline(cin, name);

	cout << endl << "Enter instructor name:   ";
	getline(cin, inst);

	cout << endl << "Enter enrolment:   ";
	getline(cin, str);
	stringstream ss(str);
	ss >> enrol;

	*course =  new Course(subj, num, name, inst, enrol);
	(*course)->setBooks(new BookArray()); 
	
}
/*	Purpose:	Gets number of courses to add and creates list of courses 
				to add to the all courses
	Params:		Takes a list of courses to add teh courses to	

*/

void UImanager::getCourses(Dlist<Course*>& list)
{
	//Dlist tmp;
	string str; 
	int num;
	cout << "Number of Courses to add: ";
   	getline(cin, str);
	stringstream ss(str);
	ss >> num;
	for(int i = 0; i < num; ++i){
		Course* course;
		getCourseData(&course);
		list += course;

	}
}

/*	Purpose:	removes one course from a list
	Params:		Takes a course and list of courses 
*/
void UImanager::removeCourseData(Course** c, Dlist<Course*>& list)
{
	string code;
	while (code.length() != 8) {
		cout << "Enter course code (e.g. COMP2404):  ";
   		getline(cin, code);
  	}
	*c = *list.findObj(code);
	//cout<< "Course removed ";
}

/*	Purpose:	finds number of courses to remove and creates a list 
				of courses to remove from all courses
	Params:		Takes a list of courses
*/
void UImanager::removeCourses(Dlist<Course*>& temp, Dlist<Course*>& list)
{
	Course* c;
	string str; 
	int num; 
	cout << "Number of Courses to remove: ";
   	getline(cin, str);
	stringstream ss(str);
	ss >> num;
	for(int i = 0 ; i < num; i++){	// gets course to remove 
		string code;
		while (code.length() != 8) {
			cout << "Enter course code (e.g. COMP2404):  ";
	   		getline(cin, code);
  		} 
		c = *list.findObj(code);
		
		temp += c;
	}
}

/*	Purpose:	calls the format functions on list
	Params:		Takes a list of Course Objects
*/
void UImanager::printCourses( Dlist<Course*>& list)
{
	
	string s = "" ;
	cout<< " Printing courses " << endl;
	s << list;
    cout << endl<<endl;
}

/*	
Purpose: Pause between menu selections
*/
void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}



int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}



/*	Purpose:	Adds a book to a Bookarray for a course 
	Params:		Takes a book pointer as well as a list of course objects
*/

void UImanager::getBook(Book** book, Dlist<Course*>& list)
{
	
   	Course* c;
	Book* b; 
	string code;	
	while (code.length() != 8) {
		cout << "Enter course code (e.g. COMP2404):  ";
   		getline(cin, code);
  	}
	c  = *list.findObj(code);
	if(list.getSize() == 0 || &c == NULL){
		cout<< "No courses" << endl;  
	}
	else{ 
		string    str = "";
		string     title, author, ISBN;
		int       edition, year, price;
		cout << "Enter Book title:  ";
		getline(cin, title);

		cout << endl << "Enter Book Author:  ";
		getline(cin, author);
				
		cout << endl << "Enter ISBN:   ";
		getline(cin, ISBN);

		cout << endl << "Enter Edition:   ";
		getline(cin, str);
		stringstream ss(str);
		ss >> edition;
			
		while (str.length() != 4)
		{
			cout << endl << "Enter year:   ";
			getline(cin, str);
			stringstream st(str);
			st >> year;
		}

		cout << endl << "Enter price:   ";
		getline(cin, str);
		stringstream s(str);
		s >> price;
				
		b  = new Book(title, author, ISBN, edition, year, price);
		c->addBook(b);
		*book= b;
		
	}	
}

/*	Purpose:	takes a List and prints out the books in the array for 
				the chosen course
	Params:		Takes a list of Course objects 

*/
void UImanager::printBooks(Dlist<Course*>& list){	
   	Course* c;
	string code;	
	cout << "Enter Course Code:  ";
	getline(cin, code); 
	c = *list.findObj(code);
	cout << c->getCode();
	if(c!= NULL){
		cout << " Textbooks for "<< c->getCode()<<endl << endl;
		for(int j =0 ; j< c->getNumBooks(); j++){
			Book* b = c->getBooks()->getBook(j); 
			cout <<"  Title: " << b->getTitle()<<endl;
			cout <<"  Author: " << b->getAuthors()<<endl;
			cout <<"  ISBN: " << b->getISBN()<<endl;
			cout <<"  Edition: " << b->getEdition()<<endl;
			cout <<"  Year: " << b->getYear()<<endl;
			cout <<endl;
		}
	}
	else{
		cout<< "Course not found"<<endl;
	}
}

/*	Purpose:	Gets the data for a book Object and creates a new book object
	Params:		Takes a book product
*/
void UImanager::getBookData(Product** product)
{
	Product *p;
	string    str = "";
	string     title, author, ISBN;
	int       edition, year, price;
	cout << "Enter Book title:  ";
	getline(cin, title);

	cout << endl << "Enter Book Author:  ";
	getline(cin, author);
				
	cout << endl << "Enter ISBN:   ";
	getline(cin, ISBN);

	cout << endl << "Enter Edition:   ";
	getline(cin, str);
	stringstream ss(str);
	ss >> edition;
			
	while (str.length() != 4)
	{
		cout << endl << "Enter year:   ";
		getline(cin, str);
		stringstream st(str);
		st >> year;
	}

	cout << endl << "Enter price:   ";
	getline(cin, str);
	stringstream s(str);
	s >> price;
				
	p  = new Book(title, author, ISBN, edition, year, price);
	*product = p;
}


/*	Purpose:	Gets the data for a game Object and creates a new game object
	Params:		Takes a product pointer
*/
void UImanager::getGameData(Product** product)
{ 
	Product* p;

	string  str = "";
	string	name, type;
	int     price, players;

	cout << "Enter Game name:  ";
	getline(cin, name);
	cout << endl << "Enter price:  ";
	
	getline(cin, str);
	stringstream sp(str);
	sp >> price;
				
	cout << endl << "Enter type (e.g. puzzle):   ";
	getline(cin, type);

	cout << endl << "Enter number of players:   ";
	getline(cin, str);
	stringstream s(str);
	s >> players;
	
	p = new Game(name, price, type, players);
	*product = p;
}

/*	Purpose:	Gets the data for a eReader Object and creates a new eReader object
	Params:		Takes a product pointer
*/
void UImanager::geteReaderData(Product** product)
{ 
	Product* p;

	string  str = "";
	string	name, type;
	int     price, storage;
 	cout << "Enter eReader name:   ";
	getline(cin, name);
	

	cout << endl << "Enter price:  ";
	getline(cin, str);
	stringstream sp(str);
	sp >> price;
				
	cout << endl << "Enter brand (e.g. apple, samsung):   ";
	getline(cin, type);

	cout << endl << "Enter storage in gb (e.g.8):   ";
	getline(cin, str);
	stringstream s(str);
	s >> storage;

	p= new Ereader(name, price, type, storage);
	*product == p;
}

/*	Purpose:	Gets the data for a writing Object and creates a new writing object
	Params:		Takes a product pointer
*/
void UImanager::getWritingData(Product** product)
{ 
	Product* p;

	string  str = "";
	string	name, type, color;
	int     price;

	cout << "Enter Implement type (e.g.pen, marker):   ";
	getline(cin, name);
			
	cout << endl << "Enter name(e.g. fountain, sharpie):   ";
	getline(cin, type);
	
	cout << endl << "Enter price:  ";
	getline(cin, str);
	stringstream sp(str);
	sp >> price;
				
	cout << endl << "Enter color:   ";
	getline(cin, color);
	
	p = new Writing(name, price, type, color);
	*product = p;
}
	

void UImanager::getProduct(Product** p, Dlist<Product*>& list){
	string    str = "";
	string    name;
	cout << "Enter Product name:  ";
	getline(cin, name);

	*p = *list.findObj(name);
	
}	

/*Purpose:	prints out the base object of all products in the array
  Params:	Takes an array of product pointers and their size

*/

void UImanager::printProducts(Dlist<Product*>& p)
{
	/*cout << "All Products "<< endl;
	for(int i = 0; i < size; i++){
		cout << i << ". " << (*p[i]).print() <<endl;	
	}*/

	string s = "" ;
	cout<< " Printing Products " << endl;
	p.printProducts(s, p);
    cout << s << endl<<endl;
	
	
}

/*	Purpose: deallocates each product in the product array
	Params:	 Takes an array of product pointers and their size
*/

void UImanager::cleanUpProducts(Product** p, int size){
	for(int i = 0; i < size; i++){
		delete  p[i];	
	}
}




