#include "event.h"
#include "behavior.h"
#include <iostream>
using namespace std;

Event::Event(Cell &c) : theCell(c) {
	bh = Behavior::getInstance();
} 
Event::~Event() { delete &theCell; }

int		Event::getID() { return theCell.getID(); }
string	Event::getName() { return theCell.getName(); }
void	Event::setX(const int a) {theCell.setX(a);}
void	Event::setY(const int a) {theCell.setY(a);}
int		Event::getX() {return theCell.getX();}
int		Event::getY() {return theCell.getY();}
void	Event::addPlayer(Player	*p) { theCell.addPlayer(p); }
void	Event::removePlayer(Player *p) { theCell.removePlayer(p); }
void	Event::movePlayer(Player *p) { theCell.movePlayer(p); }
vector <string> Event::getTextImage() { return theCell.getTextImage(); }
void	Event::generateTextImage() { theCell.generateTextImage(); }
void	Event::drawXImage() {theCell.drawXImage();}

void	Event::setCost(const int c) { theCell.setCost(c); } 
int		Event::getCost() { return theCell.getCost(); }
void	Event::setCostImprove(const int c) { theCell.setCostImprove(c); }
int		Event::getCostImprove() { return theCell.getCostImprove(); }
int		Event::getLevel() { return theCell.getLevel(); }
int		Event::getMaxLevel() { return theCell.getMaxLevel(); }
void	Event::setLevel(const int l) { theCell.setLevel(l); }
Player*	Event::getOwner() { return theCell.getOwner(); }
void	Event::setOwner(Player	*p) { theCell.setOwner(p); }
void	Event::swapOwner(Player *p1, Player *p2) { theCell.swapOwner(p1, p2); }
Group*	Event::getGroup() { return theCell.getGroup(); }
void	Event::setGroup(Group	*g) { theCell.setGroup(g); }
void	Event::addRent(const int r) { theCell.addRent(r); }
int		Event::getRent(const int l) { return theCell.getRent(l); }
bool	Event::isSold() { return theCell.isSold(); }
bool	Event::isMortgaged() { return theCell.isMortgaged(); }
void	Event::mortgage() { theCell.mortgage(); }
void	Event::unmortgage() { theCell.unmortgage(); }
bool	Event::canBuy() { return theCell.canBuy(); }
bool	Event::canImprove() { return theCell.canImprove(); }
int		Event::getPrepaid() { return theCell.getPrepaid(); }
void	Event::setPrepaid(const int p) { return theCell.setPrepaid(p); }
void	Event::reset() { theCell.reset(); }
