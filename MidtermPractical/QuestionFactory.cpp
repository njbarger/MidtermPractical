#include "QuestionFactory.h"
#include <algorithm>

int QuestionFactory::GiveQuestion() {

	// Check that there are still questions left
	if (CheckAskTableEmpty()) {

					// *********************************************************
		return -1; // ************ TOTAL EXIT, ALL OUT OF QUESTIONS ***********
				   // *********************************************************
	}

	srand((unsigned int)time(NULL));

	// get a random question out of the list
	int randQIndex = rand() % numberOfQuestions;

	// check to make sure question hasn't been asked (using askTable truths)
	while (!CheckAskTableAtIndex(randQIndex))
	{
			// retry for random question if askTable[randQIndex] = false
			randQIndex = rand() % numberOfQuestions;
	}

	// Set the askTable truth to false for selected question
	askTable[randQIndex] = false;

	// Return index of question to be processed.
	return randQIndex;
}

// Prints out the question along with the
void QuestionFactory::ShowQuestion(Question currQuestion) {

	// Print the Question
	std::cout << "\n\n\t\t\t\t" << currQuestion.mQuestion << "\n\n";

	// Loop through to print possible answers
	for (int i = 0; i < numberOfAnswersPerQuestion; i++)
	{
		// 1) ****
		// 2) ****
		// 3) ****
		// 4) ****
		std::cout << "\t\t\t\t\t" << i + 1 << ") ";

		// Check to see if the current answer is correct (ALL CORRECT ANSWERS BEGIN WITH '*')
		if (CheckForEncode(currQuestion.mAnswers[i])) {

			//Send correct answer to decode
			std::cout << Decode(currQuestion.mAnswers[i]) << std::endl;
		}

		// Else if incorrect answer, display as normal
		else {
			std::cout << currQuestion.mAnswers[i] << std::endl;
		}
	}
}

// Checks if answer is correct, meaning it starts with '*', returns true if encoded as correct answer.
bool QuestionFactory::CheckForEncode(std::string answerToCheck)
{
	// if first letter of string is *, answer is correctAnswer - meaning '*' should not be displayed
	if (answerToCheck[0] == '*') {
		return true;
	}
	return false;
}

// Decodes answer strings beginning with '*'.
std::string QuestionFactory::Decode(std::string answerToDecode) {
	std::string result = answerToDecode.substr(1);
	return result;
}

// Checks to see if a question at a specific index has been asked
bool QuestionFactory::CheckAskTableAtIndex(int tableIndex)
{
	if (askTable[tableIndex]) {
		return true;
	}
	return false;
}

// Check askTable to see if its empty, returns true if empty.
bool QuestionFactory::CheckAskTableEmpty() {
	// check to make sure that askTable isnt completely empty while maintaining randomness (NOT EFFICIENT BUT KEEPS RANDOMNESS)
	for (size_t i = 0; i < (unsigned int)numberOfQuestions; i++)
	{
		// making sure theres still options left, will break loop on any true values remaining
		if (askTable[i]) {
			return false;
		}
	}
	return true;
}