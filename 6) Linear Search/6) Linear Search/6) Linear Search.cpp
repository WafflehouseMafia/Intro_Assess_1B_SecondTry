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