#include "QuestionController.h"
#include <algorithm>
#include <random>

int QuestionController::GetAnswer()
{
	int response;
	std::cout << "\n\nWhat is your answer? " << std::endl;
	while (true) {
		if (std::cin >> response && response > 0 && response < 5) {
			break;
		}
		else {
			std::cout << "Please enter a valid entry... " << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
	return response;

}



void QuestionController::ShuffleAnswers(std::string answers[]) {
	unsigned seed = 0;
	std::shuffle(answers, answers + 4, std::default_random_engine(seed));
}


bool QuestionController::CheckAnswer(Question currQuestion, int answer)
{
	if (currQuestion.mAnswers[answer-1][0] == '*') {
		return true;
	}
	else {
		return false;
	}
}


void QuestionController::ShowCorrect() {
	std::cout << "\n\n\t\t\t\tThat's correct! Good job! " << std::endl;
}
void QuestionController::ShowIncorrect() {
	std::cout << "\n\n\t\t\t\tSorry, that's incorrect. " << std::endl;
}
