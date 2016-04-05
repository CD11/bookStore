#include "Teacher.h"

Teacher::Teacher(int ID, double discAmnt)
{
	cout << "  --- Teacher ctor " << endl;
	id   = ID;
	discountAmnt  = discAmnt;
	courses = new Dlist<Course*>();//a teacher can teach multiple courses
  //books = new Dlist<Book*>();//a teacher can have a collection of required books for each course

	
}

//dont deallocate the list of courses and books here. should be done when user quits program.
Teacher::~Teacher()
{
	cout << "  --- Teacher dtor " << endl;
	// courses->cleanup();
	// books->cleanupProducts();
}

double Teacher::getDiscount()    { return discountAmnt; }
int    Teacher::getCode()   { return id; }  // called getCode so it can be used to sort in the Dlist class
void Teacher::addProduct(Product* item)
{
		//*products += item;

}

void Teacher::removeProduct(Product* item)
{
		//*products -= item;

}
void Teacher::addBook(Course* Course, Book* book)
{
	Course->addBook( book);
}

void Teacher::add(Course* newCourse)
{
	*courses += newCourse;
}

void Teacher::addMany(Dlist<Course*>& temp)
{
	*courses += temp;
}

void Teacher::remove(Course* delCourse)
{
	*courses -= delCourse;	
}

void Teacher::removeMany(Dlist<Course*>& temp)
{
	*courses -= temp;	
}

void Teacher::searchProduct(string name, Product* p)
{
	//p = *courses->findObj(name);
}


void Teacher::printList(Dlist<Product*>& p){
	string s = "" ;
	cout<< " Printing Products " << endl;
	p.printProducts(s, p);
    cout << s << endl<<endl;
}


Dlist<Product*>& Teacher::getList(){
	return *products;
}

string Teacher::getProduct() { return NULL;}
