#ifndef DLIST_H
#define DLIST_H

using namespace std;


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

template <class T>
class Dlist
{

	template <class V>
	class Node
	{
		friend class Dlist<V>;
		private:	
			
			V data;		
			Node<V>* next;
	};

	template <class V>
	friend string& operator<<(string&, Dlist<V>&);
	public:
	    Dlist();
	    ~Dlist();
	    void add(T*);
		void remove(T*);
	    T* getObj(int);
		T* findObj(string);
		T* findProduct(string);
	    int getSize();
		void cleanup();
		void cleanupProducts();
		void printProducts(string&, Dlist<T>&);
		string formatString(T**);
		Dlist<T>& operator+=(T&);
		Dlist<T>& operator-=(T&);
		Dlist<T>& operator+=(Dlist<T>&);
		Dlist<T>& operator-=(Dlist<T>&);
	  private:
	    int size;
		Node<T>* head;
};
template <class T>
Dlist<T>::Dlist():head(0)
{
	//cout << "  --- Dlist ctor " <<endl;

	size = 0;
}

template <class T>
Dlist<T>::~Dlist()
{

	//cout << "  --- Dlist dtor " <<endl;
}

template <class T>
int    Dlist<T>::getSize()        { return size; }

// gets a Obj node from the list
template <class T>
T* Dlist<T>::getObj(int index) 
{
  	Node<T>* currNode = head;
 	Node<T>* nextNode;
	T c;

	for(int i = 0; i < index; i++){
    	nextNode = currNode->next;
		currNode = nextNode;
  	}
	return &currNode->data;
}


template <class T>
T* Dlist<T>::findObj(string code)
{
	Node<T>* currNode = head;
  	Node<T>* nextNode;
	T* c; 
	if(head == NULL){
		c = NULL;
	}
	while(currNode!=NULL)
	{
		if((currNode->data)->getCode()  == code)
			break;
    	nextNode = currNode->next;
		currNode = nextNode;
  	}
	
	return &currNode->data;;
}




// adds a Obj to the list
template <class T>
void Dlist<T>::add(T* obj)
{ 
	
	
	Node<T>* currNode = this->head;
	Node<T>* prevNode = 0;

	Node<T>* newNode = new Node<T>;
	newNode->data = *obj;

	while (currNode != 0) {
		if((currNode->data)->getCode() > (newNode->data)->getCode()){
			break; 		
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	// adding to head of the list
	if (prevNode == 0) {
		//cout<< " adding to head " << endl;
		head = newNode;
		newNode->next = currNode;
		
	}/* adding to tail of list */
	else {
		//cout<< " adding to tail " << endl;
		newNode->next  = NULL;
		prevNode->next = newNode;
	} 
	newNode->next = currNode;
	size++;

}



// removes a Obj from the list
template <class T>
void Dlist<T>::remove(T* obj)
{
	Node<T>* currNode = this->head;
	Node<T>* prevNode = 0;

	while (currNode != NULL)
	{
		if ((currNode->data)->getCode() == (*obj)->getCode())
    		break;
   		prevNode = currNode;
    	currNode = currNode->next;
  	}

	// deleting from the head of the list
	if (prevNode == 0) 
	{
		head = currNode->next;	
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
void Dlist<T>::cleanup()
{
	Node<T>* currNode = head;
	Node<T>* nextNode = 0; 
	
	while (currNode != 0) {
   		delete (currNode->data)->getBooks(); // deletes the book array
		delete currNode->data;
		nextNode = currNode->next;	
		delete currNode;
    	currNode =nextNode;
    }	
}

template <class T>
void Dlist<T>::cleanupProducts()
{
	Node<T>* currNode = head;
	Node<T>* nextNode = 0; 
	
	while (currNode != 0) {
		delete currNode->data;
		nextNode = currNode->next;	
		delete currNode;
    	currNode =nextNode;
    }	
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(T& obj){
	add(&obj);
	return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(T& obj){
	remove(&obj);
	return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(Dlist<T>& list){
	Node<T>* newNode = list.head;

	while(newNode != NULL){
		T c = newNode->data;
		*this += (c);
		newNode = newNode->next;
		list -= c;
	}
	return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(Dlist<T>& list){
	Node<T>* newNode = list.head;
	string s;
	s << list;
	cout << s;
	while(newNode != NULL){
		T c = (newNode->data);
		*this -= (c);
		newNode = newNode->next;
		list -= c;
	}
	return *this;
}

template <class T>
string Dlist<T>::formatString(T** c){

	T* o = *c;	
	string Obj, instructor, enrolment, textbooks;
	Obj = "Course : " + (*o)->getCode() +  " " + (*o)->getName() + " \n";
	instructor =  "Instructor : " +  (*o)->getInstr() + " \n";
	textbooks = "TextBooks: ";
	stringstream ss;   
	ss << (*o)->getEnrol(); 
	enrolment = "Enrolment: " + ss.str() + " \n"; 
	if ((*o)->getNumBooks() == 0) {
			textbooks += "none"; 
	}
	else {
		for(int j =0 ; j< (*o)->getNumBooks(); j++){
		   	textbooks += (*o)->getBooks()->getBook(j)->getTitle()+ " ";
		}
		textbooks += "\n";	
	}

	return "\n"+Obj + instructor +  enrolment + textbooks+"\n\n";
}

template <class T>
void Dlist<T>::printProducts(string& out, Dlist<T>& list){

	string p;
	for (int i=0; i< list.getSize(); ++i) {
	    T* c = list.getObj(i);
		stringstream ss;   
		ss << (*c)->getPrice(); 
		p =  ss.str() + " \n"; 
		out += (*c)->getCode() + " " + p;
	}
}

template <class V>
string& operator<<(string& out, Dlist<V>& list){ 
    string Obj, instructor, enrolment, textbooks;
	out += " \n\n ALL Courses INCREASING:\n";
	for (int i=0; i< list.getSize(); ++i) {
	    V* c = list.getObj(i);
		out += list.formatString(&c);
	}

	out += "\n\n ALL Courses DECREASING:\n";
	for (int i= list.getSize()-1; i>=0; --i) {
	    V* c = list.getObj(i);
		out += list.formatString(&c);
	}
	cout << out <<endl;
	return out;   
}

#endif 
