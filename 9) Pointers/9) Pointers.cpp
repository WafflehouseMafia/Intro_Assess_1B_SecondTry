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

int main()
{
	int ValueOne = 2;
	int ValueTwo = 1;
	
	cout << "The values for our integers are currently all messed up! Value One comes back as " << ValueOne << ", and Value Two is " << ValueTwo << "!\n"
		<< "\nBut with the power of pointers....\n";
	SwappingPointers(&ValueOne, &ValueTwo); //And unlike in the function itself, here we're giving the values the actual point in history they're supposed to be pointing to.
	assert(ValueOne == 1 && ValueTwo == 2);
	cout << "\nNow the integer for Value One returns " << ValueOne << " and Value Two returns " << ValueTwo << "!\n";
}