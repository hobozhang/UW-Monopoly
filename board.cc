#include "board.h"
#include "cell.h"
#include "group.h"
#include "facility.h"
#include "property.h"
#include "textdisplay.h"
//#include "xdisplay.h"
#include "player.h"

#include "strategy.h"
#include "human.h"

#include "sellproperty.h"
#include "collectrent.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*****Instance*****/
void Board::cleanInstance() { delete instance; }
Board *Board::getInstance(const string save, const bool testing) {
	if(!instance) {
		instance = new Board(save, testing);
		atexit(cleanInstance);
	}
	return instance;
}
Board *Board::instance = NULL;

/*****Constructor*****/
Board::Board(const string save, const bool test) : savefile(save), testing(test) {
	numPlayer = numCell = numGroup = 0;
	td = new TextDisplay;
}
Board::~Board() {
	delete td;
	//delete xd;
	for(int i = 0; i < numCell; i ++)
		delete cells[i];
	for(int i = 0; i < numPlayer; i ++)
		delete players[i];
	for(int i = 0; i < groups.size(); i ++)
		delete groups[i];
}

/*****setGame*****/
void Board::loadMap(const string &mapfile) {
	string tmp;
	ifstream stream(mapfile.c_str());
	getline(stream, tmp);
	istringstream str(tmp);
	str >> width >> height;
	numCell = width * 2 + height * 2 - 4;

	for(int i = 0; i < numCell; i ++) {
		int cost, n, rent;
		string name, group;

		getline(stream, name);
		getline(stream, group);

		Cell *p; 
		if(group == "NONE") p = new Facility(i, name);
		else {
			Property *tp = new Property(i, name);	
			p = tp;
			bool found = false;
			for(vector <Group*>::iterator i = groups.begin(); i != groups.end(); i ++)
				if((*i)->getName() == group) { 
					(*i)->addProperty(tp); 
					found = true;
				}
			if(!found) {
				groups.push_back(new Group(numGroup ++, group));
				(*(groups.end() - 1))->addProperty(tp);
			}
		}

		stream >> cost;
		if(cost) {
			stream >> cost >> rent;
			p->setCost(cost);
			p->addRent(rent);
			p = new SellProperty(*p);
			p = new CollectRent(*p);
		}

		stream >> cost;
		if(cost) {
			stream >> cost >> n;
			p->setCostImprove(cost);
			while(n --) {
				stream >> rent;

				p->addRent(rent);
			}
		}

		stream >> n;
		for(int i = 0; i < n; i ++) {
			//set event
		}

		cells.push_back(p);

		getline(stream, tmp);
		getline(stream, tmp);
	}
	//xd = new XDisplay(width, height);
}

void Board::loadGame() {
}

void Board::initGame() {
	string mapfile = "uw.map";
	numPlayer = 6;

	loadMap(mapfile);	
	for(int i = 0; i < numPlayer; i ++) {
		players.push_back(new Player(i, string("") + char('A' + i)));
		cells[0]->addPlayer(players[i]);
		players[i]->setMoney(1500);
		players[i]->setStrategy(0);
	}

	printBoard();
	printPlayerInfo();
	for(int i = 0; !gameEnd(); i = (i + 1) % numPlayer) {
		int decision;
		while(decision = players[i]->getStrategy()->command(players[i])) {
			if(decision == 1) {
				int step = players[i]->roll(testing);
				int id = players[i]->getCurrentCell()->getID();
				id = (id + step) % numCell;
				cells[id]->movePlayer(players[i]);	
				cells[id]->event(players[i]);
			}
		}
		printBoard();
		printPlayerInfo();
	}

}

bool Board::gameEnd() { return false; }

/*****printBoard*****/
void Board::printBoard() {
	td->printAll(width, height, cells);
}

/*****startGame*****/
void Board::startGame() {
	if(savefile.length() > 0) loadGame();
	else initGame();
}

void Board::printPlayerInfo() {
	for(int i = 0; i < numPlayer; i ++) {
		players[i]->printInfo();	
	}
}
