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

	int targetValue;
	int arrayPosition = IntegerSearch(3, array, arraySize);
	assert(arrayPosition == 2); //3 is at the third position, so value 2. simple enough


	arrayPosition = IntegerSearch(7, array, arraySize);
	assert(arrayPosition == 11);


	arrayPosition = IntegerSearch(67, array, arraySize);
	assert(arrayPosition == 0);


	arrayPosition = IntegerSearch(88, array, arraySize);
	assert(arrayPosition == -1);

	cout << "Give me a number, any number, and we'll see if it's in the array!\n\n";
	
	do
	{
		std::cin >> targetValue;
		arrayPosition = IntegerSearch(targetValue, array, arraySize);
		if (arrayPosition >= 0)
		{
			cout << "\n\nYour number was found at position " << arrayPosition + 1 << ". Good job. Let's go again!\n\n";
		} //Made it arrayPosition + 1 purely because people tend to start counting from 1 instead of from 0.
		else if (arrayPosition == -1)
		{
			cout << "\n\nYour number wasn't in the array. Womp womp.\n\n";
		}
	} while (arrayPosition >= 0);
}