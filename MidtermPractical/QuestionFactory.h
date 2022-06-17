#pragma once
#include <string>
#include <array>
#include "Questions.h"

class QuestionFactory
{
public:
	int numberOfQuestions = 5;
	bool askedTable[5] = { true,true,true,true,true };		// truth table for how many questions are asked
	
	bool GiveQuestion();
	void ShowQuestion(Question currQuestion);
	void ShowCorrectQuestion(Question currQuestion, bool answeredCorrect = true);

};

