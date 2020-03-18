#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define MAXSIZE 5

#include <iostream>
using namespace std;

#include "ItemType.h"

class ArrayList {
private:
	int m_CurPointer;
	int m_length;
	ItemType m_Array[MAXSIZE];
public:
	ArrayList();
	~ArrayList() {};

	void Add(ItemType data);
	void MakeEmpty();
	int GetLength();
	int IsFull();
	void ResetList();
	int GetNextItem(ItemType& data);
	int Get(ItemType& data);
	void Delete(ItemType data);
	void Replace(ItemType data);

};

#endif

