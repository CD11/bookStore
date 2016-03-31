#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>


using namespace std;

#include "Dlist.h"

// constructs a course Dlist
template <class T>
class Node
{
	friend class Dlist;
	private:	
			
		Course* data;		
		Node* next;
		Node* prev;
};

template <class T>
class Dlist
{
	template <class T>
	friend string& operator<<(string&, Dlist&);
	public:
	    Dlist();
	    ~Dlist();
	    void add(Course*);
		void remove(Course*);
	    Course* getCourse(int);
		//void findCourse(string,Course*);
		Course* findCourse(string);
		void findCourse(string,Course**);
	    int getSize();
		void cleanup();
		string formatString(Course**);
		void operator+=(Course*);
		void operator-=(Course*);
		void operator+=(Dlist&);
		void operator-=(Dlist&);
	  private:
	    int size;
		Node* head;
};
template <class T>
Dlist::Dlist():head(0)
{
	//cout << "  --- Dlist ctor " <<endl;
	size = 0;
}

template <class T>
Dlist::~Dlist()
{

	//cout << "  --- Dlist dtor " <<endl;
}

template <class T>
int    Dlist::getSize()        { return size; }

// gets a course node from the list
Course* Dlist::getCourse(int index) 
{
  	Node* currNode = head;
 	Node* nextNode;

	for(int i = 0; i < index; i++){
    	nextNode = currNode->next;
		currNode = nextNode;
  	}

	return currNode->data;
}


template <class T>
Course* Dlist::findCourse(string code)
{
	Node* currNode = head;
  	Node* nextNode;
	Course* c; 
	if(head == NULL){
		c = NULL;
	}
	while(currNode!=NULL)
	{
		if(currNode->data->getCode()  == code)
			break;
    	nextNode = currNode->next;
		currNode = nextNode;
  	}
	c = currNode->data;
	return c;

}


// adds a course to the list
template <class T>
void Dlist::add(Course* course)
{
	Node* currNode = head;
	Node* prevNode = 0;

	Node* newCourseNode = new Node;
	newCourseNode->data = course;
	
	//cout << "----------------   currNode " << course->getCode() <<endl;
	while (currNode != NULL) {
		if(currNode->data->getCode() > (course)->getCode()){
			break; 		
		}
		prevNode = currNode;
		currNode->prev = currNode;
		currNode = currNode->next;
	}

	// adding to head of the list
	if (prevNode == 0) {
		//cout<< " adding to head " << endl;
		head = newCourseNode;
		newCourseNode->prev = NULL;
		newCourseNode->next = currNode;
		prevNode = newCourseNode; 
		
	}/* adding to tail of list */
	else if (currNode == NULL){
		//cout<< " adding to tail " << endl;
		newCourseNode->next  = NULL;
		newCourseNode->prev  = prevNode;
		prevNode->next = newCourseNode;
	} 
	//adding to the middle of the list
	else {
		//cout << " adding to middle " << endl;
		prevNode->next = newCourseNode;
		newCourseNode->prev = currNode->prev;
		newCourseNode->next = currNode;
		currNode->prev = newCourseNode;
	}
	newCourseNode->next = currNode;
	size++;
}


// removes a course from the list
template <class T>
void Dlist::remove(Course* course)
{
	Node* currNode = head;
	Node* prevNode = 0;

	while (currNode != NULL)
	{
		if (currNode->data->getCode() == (course)->getCode())
      	break;
   		prevNode = currNode;
    	currNode = currNode->next;
  	}

	// deleting from the head of the list
	if (prevNode == 0) 
	{
		head = currNode->next;	
		currNode->prev = 0; 
	}	
	// deleting from the middle of the list
	else
	{
    	prevNode->next = currNode->next;
  	}
  	delete currNode;
	size--;
}

template <class T>
void Dlist::cleanup()
{
	Node* currNode = head;
	Node* nextNode = 0; 
	
	while (currNode != 0) {
   		delete currNode->data->getBooks(); // deletes the book array
		delete currNode->data;
		nextNode = currNode->next;	
		delete currNode;
    	currNode =nextNode;
    }	
}

template <class T>
void Dlist::operator+=(Course* course){
	return this->add(course);
}

template <class T>
void Dlist::operator-=(Course* course){
	return this->remove(course);
}

template <class T>
void Dlist::operator+=(Dlist& list){
	Node* newNode = list.head;
	while(newNode != NULL){
		Course* c = (newNode->data);
		  *this += (c);
		newNode = newNode->next;
		list-=c;
	}
}

template <class T>
void Dlist::operator-=(Dlist& list){
	Node* newNode = list.head;
	
	while(newNode != NULL){
		Course* c =(newNode->data);
		*this -= (c);
		newNode = newNode->next;
		list -=c;
	}
}

template <class T>
string Dlist::formatString(Course** c){
	string course, instructor, enrolment, textbooks;
	course = "Course : " + (*c)->getCode() +  " " + (*c)->getName() + " \n";
	instructor =  "Instructor : " +  (*c)->getInstr() + " \n";
	textbooks = "TextBooks: ";
	stringstream ss;   
	ss << (*c)->getEnrol(); 
	enrolment = "Enrolment: " + ss.str() + " \n"; 
	if ((*c)->getNumBooks() == 0) {
			textbooks += "none"; 
	}
	else {
		for(int j =0 ; j< (*c)->getNumBooks(); j++){
		   	textbooks += (*c)->getBooks()->getBook(j)->getTitle()+ " ";
		}
		textbooks += "\n";	
	}

	return "\n"+course + instructor +  enrolment + textbooks+"\n\n";
}

template <class T>
string& operator<<(string& out, Dlist& list){ 
    string course, instructor, enrolment, textbooks;
	out += " \n\n ALL COURSES INCREASING:\n";
	for (int i=0; i< list.getSize(); ++i) {
	    Course* c = list.getCourse(i);
		out+=list.formatString(&c);
	}

	out += "\n\n ALL COURSES DECREASING:\n";
	for (int i= list.getSize()-1; i>=0; --i) {
	    Course* c = list.getCourse(i);
		out +=list.formatString(&c);
	}
	cout << out <<endl;
	return out;   
}

