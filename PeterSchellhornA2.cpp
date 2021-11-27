/*
Peter Schellhorn
BCS 370 - Data Structures 
Assignment 2
*/


#include "Assignment2.h"

int main(){

  Circle < int > x; 
  cin >> x;
  cout << x;

  x=x++; // increment  ++ unary operator
  cout << x;

  x = x + 10; // increment using + binary operator
  cout << x; 
  
return 0;
}