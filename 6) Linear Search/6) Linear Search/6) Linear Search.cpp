// 6) Linear Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

int IntegerSearch(int targetValue, int array[], int arraySize)
{
	int i = 0;

	for (i = 0; i < arraySize; ++i) //The usual state of things for a loop
	{
		if (array[i] == targetValue) //If we land on the value we're looking for...
			return i; //The loop should stop and we return whatever value i was when we found it.
	}
	return -1; //Just as the task says, if we don't find it then return -1.
}

int main()
{
	const int arraySize = 20;
	int array[arraySize] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

	int targetValue = 3;
	int arrayPosition = IntegerSearch(targetValue, array, arraySize);
	assert(arrayPosition == 2); //3 is at the third position, so value 2. simple enough
	if (arrayPosition > -1)
		cout << "Your number was found at position " << arrayPosition << "\n";
	else
		cout << "That value was not in the array.\n";

	targetValue = 7;
	arrayPosition = IntegerSearch(targetValue, array, arraySize);
	assert(arrayPosition == 11);
	if (arrayPosition > -1)
		cout << "Your number was found at position " << arrayPosition << "\n";
	else
		cout << "That value was not in the array.\n";

	targetValue = 67;
	arrayPosition = IntegerSearch(targetValue, array, arraySize);
	assert(arrayPosition == 0);
	if (arrayPosition > -1)
		cout << "Your number was found at position " << arrayPosition << "\n";
	else
		cout << "That value was not in the array.\n";

	targetValue = 88;
	arrayPosition = IntegerSearch(targetValue, array, arraySize);
	assert(arrayPosition == -1);
	if (arrayPosition > -1)
		cout << "Your number was found at position " << arrayPosition << "\n";
	else
		cout << "That value was not in the array.\n";

}