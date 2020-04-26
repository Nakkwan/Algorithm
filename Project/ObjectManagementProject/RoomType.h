#ifndef __ROOMTYPE_H
#define __ROOMTYPE_H

#include "Base.h"
#include "DrawerType.h"
#include "SortedList.h"
#include <string>
class RoomType : public Base {
private:
	int r_ID;
	string r_Name;
	int r_Length;
	int r_curPointer;
	SortedList<DrawerType> r_Array;

public:
	RoomType() {
		r_ID = 0;
		r_Name = "";
		r_Length = 0;
		r_curPointer = -1;
	}

	~RoomType() {};
	/*
	@brief: Room�� ���� ID �� �ޱ�
	@pre: RoomID�� �����Ǿ� �־����
	@post: none
	@return: RoomID return
	*/
	int GetRoomID() const;

	/*
	@brief: Room�� ���� �� �ޱ�
	@pre: Room�� ������ �����Ǿ� �־����
	@post: none
	@return: Room Type return
	*/
	string GetRoomName() const;

	/*
	@brief: Room�� �ִ� Drawer ���� �ޱ�
	@pre: none
	@post: none
	@return: Room�� Drawer�� ���� return
	*/
	int GetNumOfDrawer() const;

	/*
	@brief: RoomID ����
	@pre: none
	@post: RoomID ���� ������
	@param: ������ RoomID integer
	*/
	void SetRoomID(int inID);

	/*
	@brief: Room��  ���� ����
	@pre: none
	@post: Room�� ������ ������
	@param: ������ Room ���� string
	*/
	void SetRoomName(string inType);

	/*
	@brief: Room�� ���� ����
	@pre: none
	@post: Room�� ID, ������ ������
	@param: ������ Room�� ID(int), Type(string)
	*/
	void SetRoomRecord(int inID, string inType);


	/*
	@brief: RoomID�� ����ڷκ��� �Է¹���
	@pre: none
	@post: RoomID�� ����ڷκ��� �Է¹��� ������ ������ (1~9)
	*/
	void SetRoomIDfromKB();

	/*
	@brief: Room�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Room�� ������ ����ڷκ��� ����
	*/
	void SetRoomNamefromKB();


	/*
	@brief: Room�� Drawer�� �߰�
	@pre: Drawer ������ �����Ǿ� �־�� ��
	@post: Room�� DrawerList�� Drawer�� �߰���.
	@param: DrawerType for add
	*/
	void AddDrawer(const DrawerType& data);

	/*
	@brief: Room���� Drawer�� ��
	@pre: �� Drawer�� ID�� �����Ǿ� �־�� ��
	@post: Room�� DrawerList���� �ش��ϴ� Drawer�� ������.
	@param: DrawerType for delete
	*/
	void DeleteDrawer(DrawerType& data);

	/*
	@brief: Room�� Drawer ������ ������
	@pre: ������ Drawer�� ������ �����Ǿ� �־�� ��
	@post: Room�� DrawerList���� �ش��ϴ� Drawer�� ������ ���ŵ�.
	@param: DrawerType for update
	*/
	void UpdateDrawer(DrawerType& data);

	/*
	@brief: DrawerList�� �ִ� Drawer�� ��� display��
	@pre: none
	@post: DrawerList�� �ִ� Drawer�� ������ ȭ�鿡 ��� display��
	*/
	void DiplayAllDrawer();

	/*
	@brief: Room�� ������ ��� display
	@pre: none
	@post: none
	*/
	void DisplayInfo();
};


#endif // !__ROOMTYPE_H
