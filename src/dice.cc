#include "dice.h"

using namespace std;

//constructor, n represents the number of time to roll
Dice::Dice(const int v) : n(v) {}

//destructor
Dice::~Dice() {}

vector <int> Dice::roll() {
	vector <int> v;
	//roll n times and store results in vector v
	for(int i = 0; i < n; i ++)
		v.push_back(rand() % DICEMAX + 1);
	return v;
}

void Dice::cleanInstance() { delete instance; }

Dice *Dice::getInstance(const int v) {
   //if dice do not already exist, create an instance
	if(!instance) {
		instance = new Dice(v);
		atexit(cleanInstance);
	}
	return instance;
}

int		Dice::getNumDice() { return n; }

Dice *Dice::instance = NULL;
