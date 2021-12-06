/*
Peter Schellhorn
BCS 370 - Data Structures 
Assignment 2

This is a quick excecise. Make sure you do a clean house keeping of the dynamic memories. You may submit one .cpp file for this assignment. 

1. Given the Student struct definition as follows:
stuct Student {
    std::string name;
      int age;
};

2. Create a class  Class that has int classSize and Student* students as its  private member variables.

  1) Create a parameterized  constructor that takes an  int argument to be passed in and assigned to the member variable  classSize. 

  The constructor creates a  dynamic array of Student objects with   classSize elements.The function uses  pointer arithmetic to assign default values  (such as name="", age=0) to each object.

  2) Also, construct the destructor, ~Student(), for the class.

3. In main(), simply instantiate an object to ensure the program works.
*/

#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
};

class Class {
  private:
    int classSize;
    Student * students;

  public:
    Class(int x) {//constructor

      classSize = x;
      students = new Student[x];//create array
  
      for (int i = 0; i < x; i++) { //pointer arithmetic to fill array
        ( * (students + i)).name = "";
        ( * (students + i)).age = 0;
      }
    }
    
    ~Class() {//destructor
      delete[] students;
    }
};

int main() {

  Class bcs370(14);//instantiate the object of Class with 14students
 
  return 0;
}