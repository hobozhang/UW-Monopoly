#include "human.h"

#include <iostream>
#include <string>
using namespace std;

Human::Human() {}
Human::~Human() {}

int		Human::command(Player *p) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "roll") return 1;
		if(cmd == "next") return 0;
	}
	return -1;
}

bool	Human::buyProperty(Cell *b, Player *p) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}

int		Human::unblock(Player *p, int fee, std::string itemname) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "r") return 0;
		if(cmd == "p") return 1;
		if(cmd == "i") return 2;
	}
	return -1;
}