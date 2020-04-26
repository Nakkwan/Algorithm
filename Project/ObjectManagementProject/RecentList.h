#ifndef __RECENTLIST_H
#define __RECENTLIST_H

#include "ItemType.h"
#include "Queue.h"
#include "Base.h"


class RecentList : public Base{
private:
	Queue<ItemType> r_Array;
	int r_length;
	int r_curPointer;

private:
	/*
	@brief: Queue�� ���� �߰�
	@pre: none
	@post: Queue�� �� ���� �ʾҴٸ�, ������ �߰��ϰ�, 
			á�ٸ�, ���� ���� ������ ���� �� �߰�
	*/
	void AddItem();

	/*
	@brief: Queue�� �ִ� ��� ���� ���� ���
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@brief: Queue �ʱ�ȭ
	@pre: none
	@post: Queue�� �� ���·� ����
	*/
	void MakeEmpty();
};

#endif // !__RECENTLIST_H
