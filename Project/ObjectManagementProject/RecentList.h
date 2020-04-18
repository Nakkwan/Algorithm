#ifndef __RECENTLIST_H
#define __RECENTLIST_H

#include "ItemType.h"
#include "Queue.h"
#include "Base.h"


class RecentList : public Base{
private:
	Queue<ItemType> r_Array;
	int r_length;
	int r_curPointer;

private:

};

#endif // !__RECENTLIST_H
