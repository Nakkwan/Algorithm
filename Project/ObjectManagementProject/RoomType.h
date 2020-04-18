#ifndef __ROOMTYPE_H
#define __ROOMTYPE_H

#include "Base.h"
#include "DrawerType.h"
#include "UnsortedList.h"
#include <string>
class RoomType : public Base {
private:
	int r_ID;
	string r_type;
	int r_length;
	int r_curPointer;
	UnsortedList<DrawerType> r_Array;

public:
};


#endif // !__ROOMTYPE_H
