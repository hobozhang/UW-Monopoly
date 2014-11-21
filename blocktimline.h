#ifndef __BLOCKTIMLINE_H__
#define __BLOCKTIMLINE_H__

#include "event.h"
#include <string>

class BlockTimline : public Event {
	private:
		int fee;
		std::string itemname;
	public:
		BlockTimline(Cell &c, const int f, const std::string i);
		~BlockTimline();

		void event(Player *p);
};

#endif
