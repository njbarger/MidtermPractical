// MidtermPractical.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "QuestionFactory.h"

int main()
{
	QuestionFactory qFactory;		// Factory for generating questions
	bool dontQuit = true;			// complete exit condition
	std::cout << "\n\n\n\n\n\n\n\t\t\tWelcome to the test of randomness... I will continue to ask you questions until" <<
		"\n\t\t\t\t you tell me when to quit (enter 0)\n\n";
	system("pause");



	while (true)
	{
		dontQuit = qFactory.GiveQuestion();
		if (!dontQuit)
		{
			break;
		}
		std::cout << "what is your answer? ";
		std::string response;
		std::cin >> response;
		system("pause");
		
	}
	std::cout << "\n\n\tIt seems I've run out of questions for you. Have a nice day!" << std::endl;
	system("pause");
	
}
