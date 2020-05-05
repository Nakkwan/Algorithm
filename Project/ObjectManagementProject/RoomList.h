#pragma once

#include "pch.h"

//���� ��Ҹ� ��ü������ ��Ÿ���� Class
class RoomList : public Base {
private:
	UnsortedList<RoomType> R_List;
	int R_length;
public:
	RoomList();
	~RoomList(){}

	/*
	@brief: ���� �߰���
	@pre: Set Room value
	@post: RoomList�� ���� �߰���
	@return: ���� �߰��Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int RoomAdd(RoomType& data);

	/*
	@brief: ���� ������ ������
	@pre: Set Room value for update
	@post: RoomList���� �ش� ���� ������ ������
	@return: �� ������ �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int RoomUpdate(RoomType& data);

	/*
	@brief: ���� ������ ����
	@pre: Set RoomID for get RoomType
	@post: �ش��ϴ� ���� ������ reference�� ��ȯ��
	@return: ���� ������ ������ 1, �ƴϸ� 0�� ��ȯ��
	*/
	int RoomGet(RoomType& data);

	/*
	@brief: ��� ���� ������ �����
	@pre: none
	@post: none
	@return: ���� ������ ��µǸ� 1, ��µ� ���� ������ 0�� ��ȯ��
	*/
	int DisplayAllRoomInfo();


	/*
	@brief: �������� �߰���
	@pre: Set Drawer value
	@post: �ش��ϴ� Room�� DrawerList�� �������� �߰���
	@return: �������� �߰��Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int DrawerAdd(DrawerType& data);

	/*
	@brief: �������� ������
	@pre: Set DrawerID for delete
	@post: �ش��ϴ� Room�� DrawerList�� �������� ������
	@return: �������� �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int DrawerDelete(DrawerType& data);

	/*
	@brief: �������� ������ ������
	@pre: Set Drawer value for update
	@post: �ش��ϴ� �������� ������ ������
	@return: �������� ������ �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int DrawerUpdate(DrawerType& data);

	/*
	@brief: ������� �ش�Ǵ� ���� ������ ����
	@pre: Set RoomID about Drawer, and DrawerID for Get
	@post: �ش��ϴ� ������� ���� ������ reference�� ��ȯ��
	@return: ������ ������ 1, �ƴϸ� 0�� ��ȯ��
	*/
	int DrawerGet(RoomType& rodata, DrawerType& data);

	/*
	@brief: ��� �������� ������ �����
	@pre: none
	@post: none
	@return: �������� ������ ��µǸ� 1, ��µ� �������� ������ 0�� ��ȯ��
	*/
	int DisplayAllDrawerInfo();


	/*
	@brief: ������ ���� ������ �߰���
	@pre: Set Container value for add
	@post: �ش��ϴ� Drawer�� ContainerList�� Container�� �߰���
	@return: Container�� �߰��Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ContainerAdd(ContainerType& data);

	/*
	@brief: Container�� ������
	@pre: Set ContainerID for delete
	@post: �ش��ϴ� Container�� ������
	@return: Container�� �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ContainerDelete(ContainerType& data);

	/*
	@brief: Container�� ������ ������
	@pre: Set Container value for update
	@post: �ش��ϴ� Container�� ������ ������
	@return: Container�� ������ �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ContainerUpdate(ContainerType& data);

	/*
	@brief: Container�� �ش�Ǵ� ������, ���� ������ ����
	@pre: Set RoomID, DrawerID about Container, and ContainerID for Get
	@post: �ش��ϴ� Container, ������, ���� ������ reference�� ��ȯ��
	@return: ������ ������ 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ContainerGet(RoomType& rodata, DrawerType& drdata, ContainerType& data);

	/*
	@brief: ��� Container�� ������ �����
	@pre: none
	@post: none
	@return: Container�� ������ ��µǸ� 1, ��µ� Container�� ������ 0�� ��ȯ��
	*/
	int DisplayAllContainerInfo();


	/*
	@brief: ������ �߰���
	@pre: Set Object value for add
	@post: ������ ���� ������ ������ ������ �߰���
	@return: ������ �߰��Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ObjectAdd(SimpleItemType& data);

	/*
	@brief: ������ ������
	@pre: Set ObjectID for delete
	@post: ���� ��ҿ��� ������ ������
	@return: ������ �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ObjectDelete(SimpleItemType& data);

	/*
	@brief: ������ ������ ������
	@pre: Set Object value for add
	@post: �ش��ϴ� ������ ������ ������
	@return: ������ ������ �����Ǹ� 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ObjectUpdate(SimpleItemType& data);

	/*
	@brief: ������ ������ �ش�Ǵ� Container, ������, ���� ������ ����
	@pre: Set RoomID, DrawerID, ContainerID about Object, and ObjectID for Get
	@post: �ش��ϴ� ����, Container, ������, ���� ������ reference�� ��ȯ��
	@return: ������ ������ 1, �ƴϸ� 0�� ��ȯ��
	*/
	int ObjectGet(RoomType& rodata, DrawerType& drdata, ContainerType& codata, SimpleItemType& data);

	/*
	@brief: ��� ������ ������ �����
	@pre: none
	@post: none
	@return: ������ ������ ��µǸ� 1, ��µ� ������ ������ 0�� ��ȯ��
	*/
	int DisplayAllObjectInfo();

	/*
	@brief: RoomList�� ���¸� �ʱ�ȭ��
	@pre: none
	@post: initialize List
	*/
	void ResetList();
};