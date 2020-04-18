#ifndef __UNSORTEDLIST_H
#define __UNSORTEDLIST_H

template<typename T>
class UnsortedList {
private:
	int m_CurPointer;
	int m_length;				//현재 배열의 크기
	int Array_size;				//배열 크기의 한계
	T* m_Array;
public:
	UnsortedList();		//constructor
	UnsortedList(int size);		//constructor
	~UnsortedList();	//destructor

	/*
	@brief: add element data to array
	@pre: set element data
	@post: data added to array
	@param: ItemType to add the array
	@return: return 1 if add success, return 0 if fail to add
	*/
	int Add(const T& data);

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
	int GetNextItem(T& data);

	/*
	@brief: Get data from list correspond with label
	@pre: set uinque label for finding
	@post: parameter assigned data of list
	@param: ItemType that receive array data
	@return: return 1 if array is empty, otherwise 0
	*/
	int Get(T& data);

	/*
	@brief: delete element of list correspond with unique label
	@pre: set unique label for delete
	@post: element of list is deleted
	@param: data that has unique label for delete
	@return: return 1 if array is empty, otherwise 0
	*/
	int Delete(T data);

	/*
	@brief: replace element of list correspond with unique label
	@pre: set unique label for replace
	@post: element of list are replaced
	@return: return 1 if array is empty, otherwise 0
	*/
	int Replace(T data);

	/*
	@brief: Get Item according to index
	@pre: UnsortedList is not empty
	@post: element of the index is return by reference
	@param: UnsortedList Type, index
	*/
	int GetItemByIndex(T& data, int idx) const;
};
#endif