#pragma once
#include <string>
#include <array>
#include "Questions.h"

class QuestionFactory
{
public:
	// truth table for how many questions are asked
	bool askTable[5] = { true, true, true, true, true };		
	// numberOfQuestions and askedTable.size must be changed together, if at all;
	int numberOfQuestions = 5;
	int numberOfAnswersPerQuestion = 4;
	
public:

	int GiveQuestion();
	void ShowQuestion(Question currQuestion);
	bool CheckForEncode(std::string answerToCheck);
	std::string Decode(std::string);
	bool CheckAskTableAtIndex(int tableIndex);
	bool CheckAskTableEmpty();
};

