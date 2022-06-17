#pragma once
#include "Questions.h"
class QuestionController
{
public:
	int GetAnswer();
	void ShuffleAnswers(std::string answers[]);
	bool CheckAnswer(Question currQuestion, int answer);
	void ShowCorrect();
	void ShowIncorrect();

};

