#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#define MAXSIZE 50

#include <iostream>
using namespace std;

#include "ItemType.h"

class SortedList {
private:
	int m_CurPointer;
	int m_length;
	ItemType m_Array[MAXSIZE];
public:
	SortedList();		//constructor
	~SortedList() {};	//destructor

	/*
	@brief: add data tot array
	@pre: set data
	@post: data added to array sorted by size in ascending order
	@param: ItemType to add the array
	@return: return 1 if add success, return 0 if fail to add
	*/
	int Add(const ItemType& data);

	/*
	@brief: make array empty
	@pre: none
	@post: array is empty
	*/
	void MakeEmpty();

	/*
	@brief: get length of array
	@pre: none
	@post: none
	@return array length
	*/
	int GetLength();

	/*
	@brief: confirm if array is full
	@pre: none
	@post: none
	@return: return 1 if array is full, otherwise 0
	*/
	bool IsFull();

	/*
	@brief: confirm if array is empty
	@pre: none
	@post: none
	@return: return 1 if array is empty, otherwise 0
	*/
	bool IsEmpty();

	/*
	@brief: reset pointer of list
	@pre: none
	@post: set pointer of list initially
	*/
	void ResetList();

	/*
	@brief: Get pointer of list and correspond element
	@pre: Set list object
	@post: Receive index and corresponding data
	@param: ItemType that receive array data
	@return: current pointer of list
	*/
	int GetNextItem(ItemType& data);

	/*
	@brief: Get data from list correspond with parameter
	@pre: set ItemType for finding, and sorted list 
	@post: parameter assigned data of list
	@param: ItemType that receive array data
	@return: return 1 if array is empty, otherwise 0
	*/
	int Get(ItemType& data);

	/*
	@brief: delete element of list correspond with parameter
	@pre: set ItemType for delete
	@post: element of list is deleted
	@param: ItemType for delete
	@return: return 1 if delete success, otherwise 0
	*/
	int Delete(ItemType data);

	/*
	@brief: replace element of list correspond with ItemType
	@pre: set ItemType for replace
	@post: element of list are replaced
	@return: return 1 if replace success, otherwise 0
	*/
	int Replace(ItemType data);
};

#endif

