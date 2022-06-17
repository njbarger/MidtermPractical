#pragma once
#include <iostream>
#include <vector>



struct Question {
	const char* mQuestion;
	std::string mAnswers[4]; // right answer has * attatched to beginning
};

//*************************IMPORTANT************************************
// 
//	IF YOU WANT TO ADD A QUESTION TO THE LIST, DO NOT FORGET TO CHANGE
//	NUMBER OF QUESTIONS / SIZE OF TRUTH TABLE (located in QuestionFactory.h)
// 
//  ALL QUESTIONS FOLLOW THE SAME FORMAT
//	* 1 QUESTIONS
//	* 3 WRONG ANSWERS
//	* 1 CORRECT ANSWER (beginning with *)
// 
//
// If more answers per question need to be added/removed, QuestionController's numberOfAnswersPerQuestion must be modified for shuffling purposes
// 
//**********************************************************************

const struct Question Questions[] = {
	{"What is the meaning of life?", {"Love", "Happiness", "Peace", "*42" }},
	{"How many humans have been on the moon?", {"12", "5", "None, the moon landing was fake.", "*24"}},
	{"Where did my dad go?", {"Is Darth Vader", "Was never told.", "Killed by Darth Vader", "*Texas, probably."} },
	{"Who shot first?", {"*Han", "*Han", "*Han", "*Han" }},
	{"Where are they taking the hobbits?", {"Who?","New Jersey", "Raccoon City", "*Isengard"}}
};