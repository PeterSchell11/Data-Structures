/*
Peter Schellhorn
BCS 370 - Data Structures 
Assignment 2
*/

#include<iostream>

using namespace std;

template < class T > // declare template
class Circle {
    private:
      	T radius; 
    public:
    // member functions
     	Circle & operator + (int r); 
      	Circle & operator ++ (int);

    template < class U > // new template T is private
      	friend ostream & operator << (ostream & out, const Circle < U > & c);

    template < class U >
      	friend istream & operator >> (istream & in , Circle < U > & c);
  };

template < class T > // define + 
  	Circle < T > & Circle < T > ::operator + (int r) {
    	this -> radius += r;
    	return *this; 
  }

template < class T > //define ++
  	Circle < T > & Circle < T > ::operator ++ (int){
    	this -> radius += 1;
    	return *this; 
  }

template < class T >
  	ostream & operator << (ostream & out, const Circle < T > & c) {
    	cout << "\n\tCircle radius: " << c.radius << "\n" 
         	<< "\tCircle Area: " << 3.14159 * c.radius * c.radius << "\n"; 
    	return out;
  }

template < class T >
  	istream & operator >> (istream & in , Circle < T > & c) {
    	cout << "Enter Radius: "; in >> c.radius;
    	return in;
  }




