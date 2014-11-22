#include "collectrent.h"
#include "behavior.h"
#include "player.h"
#include "group.h"
#include <iostream>

using namespace std;

CollectRent::CollectRent(Cell &c) : Event(c) {}
CollectRent::~CollectRent() {}

void CollectRent::event(Player *p) {
	theCell.event(p);
	//check if the the property is owned and Player p is not the owner
	if(isSold() && getOwner()->getID() != p->getID()) {
		//get current rent level
		int rent = getRent(getLevel());
		//check if the group is monopolized
		if(getGroup()->isMonopoly() && getLevel() == 0) {
			cout << "Monolopy! Double Rent" << endl;
			rent *= 2;
		}
		cout << "Pay rent " << rent << endl;
		while(1) {
			// player has enought money to pay rent
			if(bh->affordable(p, rent)) {
				bh->modifyMoney(p, -rent);
				bh->modifyMoney(getOwner(), rent);
				break;
			}
			//insufficient fund, need to sell off or trade or declare bankruptcy
			else {
				cout << "Not Enough" << endl;
				//update
				break;
			}
		}
	}
}
