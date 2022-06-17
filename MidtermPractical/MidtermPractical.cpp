// MidtermPractical.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "QuestionFactory.h"

int main()
{
	QuestionFactory qFactory;
	std::string quitStr = "quit";
	std::cout << "\n\n\n\n\n\n\n\t\t\tWelcome to the test of randomness... I will continue to ask you questions until" <<
		"\n\t\t\t\t you tell me when to quit (enter 0)\n\n";
	system("pause");



	while (true)
	{
		qFactory.GiveQuestion();

		system("pause");


	}
	
}
