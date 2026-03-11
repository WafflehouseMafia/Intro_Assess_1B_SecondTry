// 9) Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;


void SwappingPointers(int* ValueOne, int* ValueTwo) //Making it a void, since the assessment says that it shouldn't return anything.
{ //All of these are specifically *pointers, as to my knowledge we're less returning a spot in memory and more just, for lack of a better word, pointing at the value at that particular spot
	int swapping = *ValueOne; //Gotta store one of the values before they swap. So far, so normal
	*ValueOne = *ValueTwo;
	*ValueTwo = swapping;
}