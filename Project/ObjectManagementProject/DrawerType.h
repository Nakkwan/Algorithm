#ifndef __DRAWERTYPE_H
#define __DRAWERTYPE_H


#include "Base.h"
#include "Stack.h"
#include "ContainerType.h"
#include <string>
using namespace std;

class DrawerType : public Base{
private:
	int d_ID;
	string d_type;
	int d_length;
	int d_curPointer;
	Stack<ContainerType> d_Array;
public:

};

#endif // !__DRAWERTYPE_H
