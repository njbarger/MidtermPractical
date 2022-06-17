#pragma once
#include <iostream>
#include <vector>

struct Question {
	const char* mQuestion;
	const char* mAnswers[4]; // right answer has * attatched to beginning
};

const struct Question Questions[] = {
	{"question1", {"answer1", "answer2", "answer3", "*rightanswer1" }},
	{"question2", {"answer2.1", "answer2.2", "answer2.3", "*rightanswer2"}},
};