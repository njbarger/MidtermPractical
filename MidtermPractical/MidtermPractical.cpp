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

	int response;

	std::cout << "\n\n\n\n\n\n\n\t\tWelcome to the test of randomness... \n\t\tI will continue to ask you questions until I run out of questions.\n\n";
	system("pause");
	
	while (true)
	{
		int currQuestionNDX = qFactory.GiveQuestion();
		if (currQuestionNDX == -1) {
			break;
		}
		else {
			Question currQuestion = Questions[currQuestionNDX];
			qController.ShuffleAnswers(currQuestion.mAnswers);
			qFactory.ShowQuestion(currQuestion);
			response = qController.GetAnswer();
			if (qController.CheckAnswer(currQuestion, response)) {
				qController.ShowCorrect();
			}
			else {
				qController.ShowIncorrect();
			}
		}
		system("pause");
	}
	std::cout << "\n\n\tIt seems I've run out of questions for you. Have a nice day!" << std::endl;
	system("pause");
	
}
