#include "QuestionFactory.h"
#include <algorithm>

void QuestionFactory::GiveQuestion() {
	int randQuestion = rand() % 2;	// random question from list of "n" questions
	if (askedTable[randQuestion]) {
		Question currQuestion = Questions[randQuestion];
		ShowQuestion(currQuestion);
		askedTable[randQuestion] = false;
	}
}

void QuestionFactory::ShowQuestion(Question currQuestion) {

	std::cout << currQuestion.mQuestion << "\n\n";

	std::random_shuffle(std::begin(currQuestion.mAnswers), std::end(currQuestion.mAnswers));
	for (int i = 0; i < 4; i++)
	{
		if (currQuestion.mAnswers[i][0] == '*') {
			for (int j = 0; j < std::strlen(currQuestion.mAnswers[i]); j++)
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

