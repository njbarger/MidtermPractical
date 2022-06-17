#pragma once
#include <string>
#include <vector>
#include "Questions.h"

class QuestionFactory
{
public:
	bool askedTable[2];
	void GiveQuestion();
	void ShowQuestion(Question currQuestion);


};

