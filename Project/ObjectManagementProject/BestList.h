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
	/*
	@brief: stack�� top data�� �˻�Ƚ�� ��
	@pre: set stack
	@post: none
	@param: ItemType for compare
	@return: top data�� �� ������ 1, ������ 0, ������ -1�� return
	*/
	int CompareSearchNum(const ItemType& data);

	/*
	@brief: Stack�� ���� �߰�
	@pre: none
	@post: stack�� �� �����ʾҴٸ� ������ �߰��ϰ�, 
		   �� á�ٸ� top data�� ���Ͽ� �� ũ�� top data���� �� �߰�
	*/
	void AddItem();

	/*
	@brief: �˻� Ƚ���� ���� stack���� ��ġ ������
	@pre: stack has more than 1 element
	@post: Readjust stack
	*/
	void RearrangeList();

	/*
	@brief: stack�� �ִ� ��� ���� ���� ���
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@brief: Stack �ʱ�ȭ
	@pre: none
	@post: Stack�� �� ���·� �����, ���ǵ��� �˻� Ƚ���� 0���� �ʱ�ȭ
	*/
	void MakeEmpty();

	/*
	@brief: ������ �˻� Ƚ���� 0���� �ʱ�ȭ
	@pre: index�� ������ ���� �̳����� �Ѵ�.
	@post: �ش� index�� ������ �˻� Ƚ���� 0���� �ʱ�ȭ
	@param: index of stack for reset SearchNum
	*/
	void ResetObjectSearch(int index);
};


#endif // !__BESTLIST_H
