// 7) Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;



void BubbleSort(int array[], int arraySize) //Task said we didn't need to return any values, so this can be void
{
	bool OnSwitch = true; //As it says on the tin. Setting OnSwitch to true here just means it will play at least once
	int i = 0;
	

	do
	{
		OnSwitch = false; //Each loop will set the OnSwitch to off, which would turn it off if it wasn't for the one in the for loop below
		for (i = 1; i < arraySize; ++i) //Starting on i = 1, since we're checking numbers in pairs and want to make sure that we don't overshoot or undershoot the array
		{
			if (array[i-1] > array[i])
			{
				int swap = array[i-1];
				array[i-1] = array[i];
				array[i] = swap;
				OnSwitch = true; //This will continue to set OnSwitch to true so long as this if statement is active. So each time it completes a for loop, the do while will check again.
				                 //Once everything is correctly sorted into place, the if statement shouldn't trigger, OnSwitch will remain false, and the do while loop will end.
			}
		}
	} while (OnSwitch == true);
}

int BinarySearch(int targetValue, int array[], int arraySize)
{
	int low = 0;
	int high = arraySize - 1; //Gotta add the -1, or our high point in an array of 0-19 will be position 20 and break everything
	

	do
	{
		int middle = low + (high - low) / 2; //Gotta put this in the do loop or middle will be calculated only once and this will continue to loop forever
		if (array[middle] == targetValue)
			return middle;
		else if (array[middle] > targetValue)
			high = middle - 1;
		else if (array[middle] < targetValue)
			low = middle + 1;
	} while (low <= high);

	return -1;
}


int main()
{
	const int arraySize = 20;
	int array[arraySize] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };
	int i = 0;
	

	BubbleSort(array, arraySize);

	for (i = 1; i < arraySize; ++i)
	{
		assert(array[i - 1] < array[i]);
	}
	
	int targetValue;
	int valuePosition = BinarySearch(11, array, arraySize);
	assert(valuePosition == 4);

	valuePosition = BinarySearch(23, array, arraySize);
	assert(valuePosition == 8);

	valuePosition = BinarySearch(97, array, arraySize);
	assert(valuePosition == 19);

	valuePosition = BinarySearch(88, array, arraySize);
	assert(valuePosition == -1);

	cout << "Pick a number, and we'll see if it's in the provided array!\n\n";
	do
	{
		
		std::cin >> targetValue;
		valuePosition = BinarySearch(targetValue, array, arraySize);
		if (valuePosition != -1)
		{
			cout << "\nYour value was found at position " << valuePosition << ".\n";
			cout << "\n\nLet's see if you can get another one!\n\n";
		}
		else
		{
			cout << "\nYour value was not found in the array. Womp womp.\n";
		}

	} while (valuePosition != -1);
		
}