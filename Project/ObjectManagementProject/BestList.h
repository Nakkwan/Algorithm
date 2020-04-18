#ifndef __BESTLIST_H
#define __BESTLIST_H

#include "Stack.h"
#include "ItemType.h"
#include "Base.h"


class BestList : public Base{
private:
	Stack<ItemType> b_Array;
	int b_length;
	int b_curPointer;
public:

};


#endif // !__BESTLIST_H
