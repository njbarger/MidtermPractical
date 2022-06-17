#include "QuestionController.h"
#include <algorithm>
#include <random>

int QuestionController::GetAnswer(std::string prompt)
{
	int response;
	std::cout << "\n\n" << prompt << std::endl;

	// loop until input is valid
	while (true) {
		// ensure answer is 1-4
		if (std::cin >> response && response > 0 && response <= numberOfAnswersPerQuestion) {
			break;
		}
		std::cout << "Please enter a valid entry... " << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	return response;

}

// Shuffles the answers randomly
void QuestionController::ShuffleAnswers(std::string answers[]) {
	unsigned seed = 0;
	std::shuffle(answers, answers + numberOfAnswersPerQuestion, std::default_random_engine(seed));
}

// Check if chosen answer is correct (meaning it starts with '*')  returns true if correct.
bool QuestionController::CheckAnswer(Question currQuestion, int answer)
{
	if (currQuestion.mAnswers[answer-1][0] == '*') {
		return true;
	}
	return false;
}

// Correct answer message
void QuestionController::ShowCorrect() {
	std::cout << "\n\n\t\t\t\tThat's correct! Good job! " << std::endl;
}
// Incorrect answer message
void QuestionController::ShowIncorrect() {
	std::cout << "\n\n\t\t\t\tSorry, that's incorrect. " << std::endl;
}
