#include "QuestionFactory.h"
#include <algorithm>

bool QuestionFactory::GiveQuestion() {
	srand((unsigned int)time(NULL));
 	int randQuestion = rand() % numberOfQuestions;	// random question from list of "n" questions
	// check for 
	while (!askedTable[randQuestion])
	{
		// retry for random question if truth table = false
		randQuestion = rand() % numberOfQuestions;

		// check to make sure that askedTable isnt empty while keeping randomness
		for (size_t i = 0; i <= (unsigned int)numberOfQuestions; i++)
		{
			if (askedTable[i]) {	
				break;		// making sure theres still options left, will break loop on any trues remaining
			}
			if (i == (unsigned int)numberOfQuestions - 1) {
				return false;	// COMPLETE EXIT CONDITION / NO MORE QUESTIONS IN ARRAY
			}
		}

	}
	if (askedTable[randQuestion]) {
		Question currQuestion = Questions[randQuestion];
		ShowQuestion(currQuestion);
		askedTable[randQuestion] = false;
	}
	
	return true;	// meaning no failed hits on truth table / successful pass
}

void QuestionFactory::ShowQuestion(Question currQuestion) {

	std::cout << "\n\n\t" << currQuestion.mQuestion << "\n\n";

	std::random_shuffle(std::begin(currQuestion.mAnswers), std::end(currQuestion.mAnswers));
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t\t" << i + 1 << ") ";
		if (currQuestion.mAnswers[i][0] == '*') {
			for (size_t j = 0; j < std::strlen(currQuestion.mAnswers[i]); j++)
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

void QuestionFactory::ShowCorrectQuestion(Question currQuestion, bool answeredCorrect) {
	if (answeredCorrect) {
		std::cout << "\n\tThats correct! Good job!\n";
	}
	else {
		std::cout << "\n\tSorry! The correct answer is: " << currQuestion.mAnswers[3];
	}
}

