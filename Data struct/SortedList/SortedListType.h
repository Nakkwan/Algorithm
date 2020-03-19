#ifndef SORTEDLISTTYPE_H
#define SORTEDLISTTYPE_H
#define MAXSIZE 10

#include <iostream>
using namespace std;

#include "ItemType.h"

class SortedListType {
private:
	int m_CurPointer;
	int m_length;
	ItemType m_Array[MAXSIZE];
public:
	SortedListType() {
		m_CurPointer = -1;
		m_length = 0;
	};
	~SortedListType() {};

	void MakeEmpty();
	int GetLength();
	int IsFull();
	void ResetList();
	int GetNextItem(ItemType& data);
	int Add(const ItemType& data);
	int Delete(ItemType target);
	int Replace(ItemType target);
	int Get(ItemType& target);
	int GetByBinarySearch(ItemType& data);
	ItemType GetItem();
};

#endif


