#pragma once
#include <iostream>
#include <vector>



struct Question {
	const char* mQuestion;
	const char* mAnswers[4]; // right answer has * attatched to beginning
};

const struct Question Questions[] = {
	{"What is the meaning of life?", {"Love", "Happiness", "Peace", "*42" }},
	{"How many humans have been on the moon?", {"12", "5", "None, the moon landing was fake.", "*24"}},
	{"Where did my dad go?", {"That makes me uncomfortable...", "", "He was run over by a train.", "**I* am your father"}},
	{"Who shot first?", {"Han", "Han", "Han", "*Han" }},
	{"Where are they taking the hobbits?", {"Who?","New Jersey", "Raccoon City", "*Isengard"}},

};