#pragma once
#include <string>
#include <array>
#include "Questions.h"

class QuestionFactory
{
public:
	// numberOfQuestions and askedTable.size must be changed together, if at all;
	int numberOfQuestions = 5;
	// truth table for how many questions are asked
	bool askedTable[5] = { true, true, true, true, true };		
	
	int GiveQuestion();
	void ShowQuestion(Question currQuestion);

};

