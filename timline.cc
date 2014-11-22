#include "timline.h"
#include "behavior.h"
#include "strategy.h"
#include "player.h"
#include "dice.h"

#include <iostream>
#include <vector>
using namespace std;

//constructor and destructor
TimLine::TimLine(Cell &c, const int f, const string i) : Event(c), fee(f), itemname(i) {}
TimLine::~TimLine() {}

void TimLine::event(Player *p) {
	theCell.event(p);

	if(p->getBlock() > 0) {
		cout << "You are block in " << getName() << endl;
		while(1) {
			cout << "Do you want to roll dice / pay $" << fee << " use " << itemname << "? (r/p/i)" << endl;
			int decision = p->getStrategy()->unblock(p, fee, itemname);
			if(decision == 0) {
				cout << "Roll dice ";
				vector <int> t = bh->roll();
				cout << t[0] << " " << t[1] << endl;
				//check if the two rolled result is same
				if(t[0] == t[1]) {
					cout << "Unblock!" << endl;
					bh->unblock(p);
				}
				else bh->addBlock(p);
				//if a player got trapped for the third rounds, must pay to leave
				if(p->getBlock() > 3) {
					cout << "Pay $" << fee << endl << "Unblock!" << endl;
					while(!bh->affordable(p, fee)) {
						//no money
						break;
					}
					bh->modifyMoney(p, -fee);
					bh->unblock(p);
				}
				break;
			}
			else if(decision == 1) {
				if(bh->affordable(p, fee)) {
					cout << "Pay $" << fee << endl << "Unblock!" << endl;
					bh->modifyMoney(p, -fee);
					bh->unblock(p);
					break;
				}
				else cout << "Money is not enough!" << endl;
			}
			else if(decision == 2) {
				cout << "Use " << itemname << endl << "Unblock!" << endl;
				bh->unblock(p);
				break;
				//update use item
			}
		}
	}
}
