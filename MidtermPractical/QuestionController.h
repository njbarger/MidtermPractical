#pragma once
#include "Questions.h"
class QuestionController
{
public:
	int numberOfAnswersPerQuestion = 4;

	int GetAnswer(std::string prompt);
	void ShuffleAnswers(std::string answers[]);
	bool CheckAnswer(Question currQuestion, int answer);
	void ShowCorrect();
	void ShowIncorrect();

};

