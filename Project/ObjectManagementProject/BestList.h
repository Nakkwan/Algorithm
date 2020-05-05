#ifndef __BESTLIST_H
#define __BESTLIST_H

#include "pch.h"


class BestList : public Base {
private:
	Stack<ItemType> B_Array;		//���� ���� �˻��� ������ ����Ʈ
	int B_length;					//�ֺ� ���� ����Ʈ�� ũ��
public:
	BestList();						//������
	~BestList(){}					//�Ҹ���

	/*
	@brief: stack�� top data�� �˻�Ƚ�� ��
	@pre: set stack
	@post: none
	@param: ItemType for compare
	@return: top data�� �� ������ 1, ������ 0, ������ -1�� return
	*/
	bool CompareSearchNum(const ItemType& data);

	/*
	@brief: Stack�� ���� �߰�
	@pre: none
	@post: stack�� �� �����ʾҴٸ� ������ �߰��ϰ�, 
		   �� á�ٸ� top data�� ���Ͽ� �� ũ�� top data���� �� �߰�
	*/
	int AddItem(ItemType& data);

	/*
	@brief: �˻� Ƚ���� ���� stack���� ��ġ ������
	@pre: stack has more than 1 element
	@post: Readjust stack
	*/
	void RearrangeStack();

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
	//void MakeEmpty();

	/*
	@brief: ������ �˻� Ƚ���� 0���� �ʱ�ȭ
	@pre: index�� ������ ���� �̳����� �Ѵ�.
	@post: �ش� index�� ������ �˻� Ƚ���� 0���� �ʱ�ȭ
	@param: index of stack for reset SearchNum
	*/
	/*void ResetObjectSearch(int index);*/
};


#endif // !__BESTLIST_H
