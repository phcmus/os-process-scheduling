// ProcessScheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include "MainProgram.h"
#include "FCFS.h"

int main()
{
	MainProgram mainProgram = MainProgram();
	int feature = -1;
	do
	{
		feature = mainProgram.runMenu();

		switch (feature)
		{
		case 1:
			mainProgram.feature1();
			break;
		case 2:
			mainProgram.feature2();
			break;
		case 3:
			mainProgram.feature3();
			break;
		case 4:
			mainProgram.feature4();
			break;
		case 5:
			return 0;
		default:
			break;
		}
		system("pause");
	} while (feature != 5);
	return 0;
}