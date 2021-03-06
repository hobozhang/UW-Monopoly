#include "rollrimcup.h"
#include "behavior.h"
#include <cstdlib>
#include <iostream>

using namespace std;

RollRimCup::RollRimCup(Cell &c) : Event(c) {}
RollRimCup::~RollRimCup() {}

void RollRimCup::event(Player* p) {
	if(bh->getNumRimCup() < 4) {
		int r = rand() % 100;
		if(r < 1) {
			bh->showmsg( "Congradulations! You found a RimCup" );
			bh->setNumRimCup(bh->getNumRimCup() + 1);
			bh->addItem(p, "RimCup");
			return;
		}
	}
	theCell.event(p);
}
