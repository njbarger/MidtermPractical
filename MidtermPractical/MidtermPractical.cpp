#include <iostream>
#include <vector>
#include <algorithm>
#include "QuestionFactory.h"
#include "QuestionController.h"

int main()
{
	QuestionFactory qFactory;		// Factory for generating questions
	QuestionController qController; // Controller for submitting answers
	bool dontQuit = true;			// complete exit condition

	int response;					// response variable for answer

	std::cout << "\n\n\n\n\n\n\n\t\tWelcome to the test of randomness... \n\t\tI will continue to ask you questions until I run out of questions.\n\n";
	system("pause");
	
	// main loop
	while (true)
	{
		// get the index of the question/answers
		int currQuestionNDX = qFactory.GiveQuestion();

		//**********************************************************************************************************************************
		// check to see if question was given (-1 means list is empty)
		if (currQuestionNDX == -1) {
														// --------------- EXIT ------------
			break;
		}
		//**********************************************************************************************************************************




		// Get the question at valid index
		Question currQuestion = Questions[currQuestionNDX];

		// Shuffle the answers
		qController.ShuffleAnswers(currQuestion.mAnswers);

		// Print the question and answer
		qFactory.ShowQuestion(currQuestion);

		// Get the answer
		response = qController.GetAnswer("What is your answer?");

		// Check if answer is correct
		if (qController.CheckAnswer(currQuestion, response)) {
			// Correct
			qController.ShowCorrect();
		}
		else {
			// Incorrect
			qController.ShowIncorrect();
		}

		system("pause");

	}
	std::cout << "\n\n\tIt seems I've run out of questions for you. Have a nice day!" << std::endl;
	system("pause");
	
}
