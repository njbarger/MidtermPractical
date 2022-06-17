#include "QuestionFactory.h"
#include <algorithm>

int QuestionFactory::GiveQuestion() {
	srand((unsigned int)time(NULL));
	int randQuestion = rand() % numberOfQuestions;	// random question from list of "n" questions
	// check for 
	while (!askedTable[randQuestion])
	{
		// retry for random question if truth table = false
		randQuestion = rand() % numberOfQuestions;

		// check to make sure that askedTable isnt empty while keeping randomness
		for (size_t i = 0; i < (unsigned int)numberOfQuestions; i++)
		{
			if (askedTable[i]) {
				break;		// making sure theres still options left, will break loop on any trues remaining
			}
			if (i == (unsigned int)numberOfQuestions - 1) {
				return -1;	// COMPLETE EXIT CONDITION / NO MORE QUESTIONS IN ARRAY
			}
		}

	}
	askedTable[randQuestion] = false;
	return randQuestion;	// meaning no failed hits on truth table / successful pass
}

void QuestionFactory::ShowQuestion(Question currQuestion) {

	std::cout << "\n\n\t\t\t\t" << currQuestion.mQuestion << "\n\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t\t\t\t\t" << i + 1 << ") ";
		if (currQuestion.mAnswers[i][0] == '*') {
			for (size_t j = 0; j < (currQuestion.mAnswers[i]).length(); j++)
			{
				if (j == 0) {
					continue;
				}
				else {
					std::cout << currQuestion.mAnswers[i][j];
				}
			}
			std::cout << '\n';
		}
		else {
			std::cout << currQuestion.mAnswers[i] << std::endl;
		}
	}
}


