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
		for (i = 1; i < arraySize; ++i)
		{
			if (array[-1] > array[i])
			{
				int swap = array[-1];
				array[-1] = array[i];
				array[i] = swap;
				OnSwitch = true; //This will continue to set OnSwitch to true so long as this if statement is active. So each time it completes a for loop, the do while will check again.
				                 //Once everything is correctly sorted into place, the if statement shouldn't trigger, OnSwitch will remain false, and the do while loop will end.
			}
		}
	} while (OnSwitch = true);
}