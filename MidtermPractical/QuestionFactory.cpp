#include "QuestionFactory.h"
#include <algorithm>

int QuestionFactory::GiveQuestion() {
	srand((unsigned int)time(NULL));

	// get a random question out of the list
	int randQIndex = rand() % numberOfQuestions;

	// check to make sure question hasn't been asked (using askedTable truths)
	while (!askedTable[randQIndex])
	{
		// retry for random question if askedTable[randQIndex] = false
		randQIndex = rand() % numberOfQuestions;

		// check to make sure that askedTable isnt completely empty while maintaining randomness (NOT EFFICIENT BUT KEEPS RANDOMNESS)
		for (size_t i = 0; i < (unsigned int)numberOfQuestions; i++)
		{
			// making sure theres still options left, will break loop on any true values remaining
			if (askedTable[i]) {
				break;		
			}
			// if all truths in askedTable are false, all questions have been asked -> exit
			if (i == (unsigned int)numberOfQuestions - 1) {
				return -1;	// COMPLETE EXIT CONDITION / NO MORE QUESTIONS IN ARRAY
			}
		}

	}
	// set the askedTable truth to false for selected question
	askedTable[randQIndex] = false;

	// return index of question to be processed.
	return randQIndex;
}

void QuestionFactory::ShowQuestion(Question currQuestion) {

	std::cout << "\n\n\t\t\t\t" << currQuestion.mQuestion << "\n\n";
	for (int i = 0; i < 4; i++)
	{
		// 1) ****
		// 2) ****
		// 3) ****
		// 4) ****
		std::cout << "\t\t\t\t\t" << i + 1 << ") ";

		// check to see if the current answer is correct (ALL CORRECT ANSWERS BEGIN WITH '*')
		if (currQuestion.mAnswers[i][0] == '*') {
			// Loop through question one char at a time, to skip showing the encoded '*' (NOT EFFICIENT)
			for (size_t j = 0; j < (currQuestion.mAnswers[i]).length(); j++)
			{
				// if beginning of word (meaning '*'), do not print
				if (j == 0) {
					continue;
				}
				// else print char one by one
				else {
					std::cout << currQuestion.mAnswers[i][j];
				}
			}
			std::cout << '\n';
		}
		// else if incorrect answer, display as normal
		else {
			std::cout << currQuestion.mAnswers[i] << std::endl;
		}
	}
}


