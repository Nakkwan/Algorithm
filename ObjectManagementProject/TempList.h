#ifndef __TEMPTYPE_H
#define __TEMPTYPE_H

#include "pch.h"

class TempList : public Base {
private:
	int numOfItems;
	LinkedQueue<ItemType> tItemList;
public:
	TempList() {				//constructor
		numOfItems = 0;
	}
	~TempList() {}				//destructor

	/*
	@breif: tItemList�� ������ �߰�
	@pre: ���� ��Ҹ� �� ItemType ����
	@post: tItemList�� head�� ������ �߰�
	*/
	int Enqueue(const ItemType& data);				//queue�� ������ �߰�4

	/*
	@breif: tItemList���� ���� �� ������ ����
	@pre: ItemType�� ����
	@post: tItemList���� ���� ���� �� �����Ͱ� �����ǰ� reference�� ��ȯ
	*/
	int Dequeue(ItemType& data);					//queue�� ������ �����ϰ� ��ȯ

	/*
	@breif: tItemList�� ����ִ� element �� �ٲٱ�
	@pre: �ٲ� data�� ����
	@post: tItemList�� element�� �ٲ�
	*/
	int Replace(const ItemType& data);					//queue�� ������ ��ü

	/*
	@breif: tItemList�� ũ��
	@pre: none
	@post: tItemList�� ũ�� ����
	*/
	int getNumofItem();

	/*
	@breif: tItemList�� ���
	@pre: none
	@post: tItemList�� ������� ũ�Ⱑ 0�� ��
	*/
	void MakeEmpty();

	/*
	@breif: tItemList�� �� á���� Ȯ��
	@pre: none
	@post: tItemList�� �� á���� Ȯ��
	@return: tItemList�� queue�� á���� 1, �ƴϸ� 0�� ����
	*/
	bool IsFull();

	/*
	@breif: tItemList�� ������� Ȯ��
	@pre: none
	@post: tItemList�� ������� Ȯ��
	@return: tItemList�� queue�� ������� 1, �ƴϸ� 0�� ����
	*/
	bool IsEmpty();

	/*
	@breif: tItemList�� ����ִ� element display
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@breif: �ش��ϴ� ������ ã��
	@pre: ã�� ������ ����
	@post: �ش��ϴ� �����Ͱ� reference�� ��ȯ��
	*/
	int Get(ItemType& data);

	/*
	@breif: tItemList���� element ����
	@pre: ������ ������ ����
	@post: parameter�� �ش��ϴ� element ����
	@param: ������ �������� primary ID�� �ִ� ����
	*/
	int Delete(ItemType& data);

	/*int AllocateItem(ItemType& data);*/

};


#endif // !__TEMPTYPE_H
