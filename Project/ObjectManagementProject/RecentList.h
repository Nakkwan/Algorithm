#ifndef __RECENTLIST_H
#define __RECENTLIST_H

#include "pch.h"


class RecentList : public Base {
private:
	Queue<ItemType> r_Array;		//�ֱ� �˻��� ������ ����Ʈ
	int r_length;					//�ֱ� �˻� ����� ũ��

public:
	RecentList();					//������
	~RecentList(){}					//�Ҹ���
	/*
	@brief: Queue�� ���� �߰�
	@pre: none
	@post: Queue�� �� ���� �ʾҴٸ�, ������ �߰��ϰ�, 
			á�ٸ�, ���� ���� ������ ���� �� �߰�
	*/
	int AddItem(ItemType& data);

	/*
	@brief: Queue�� �ִ� ��� ���� ���� ���
	@pre: none
	@post: none
	@param: ����� ������ ����
	*/
	void DisplayItem(int size);

	/*
	@brief: Queue �ʱ�ȭ
	@pre: none
	@post: Queue�� �� ���·� ����
	*/
	void MakeEmpty();
};

#endif // !__RECENTLIST_H
