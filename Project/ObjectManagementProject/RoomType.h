#ifndef __ROOMTYPE_H
#define __ROOMTYPE_H

#include "pch.h"

class RoomType {
private:
	int r_ID;								//DrawerID
	string r_Name;							//DrawerName
	int r_Length;							//Length of DrawerList
	int r_curPointer;						//pointer of drawerList
	SortedList<DrawerType> r_Array;			//DrawerList

public:
	RoomType() {
		r_ID = 0;
		r_Name = "";
		r_Length = 0;
		r_curPointer = -1;
	}

	~RoomType() {}

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
	int AddDrawer(DrawerType& data);

	/*
	@brief: Room���� Drawer�� ��
	@pre: �� Drawer�� ID�� �����Ǿ� �־�� ��
	@post: Room�� DrawerList���� �ش��ϴ� Drawer�� ������.
	@param: DrawerType for delete
	*/
	int DeleteDrawer(DrawerType& data);

	/*
	@brief: Room�� Drawer ������ ������
	@pre: ������ Drawer�� ������ �����Ǿ� �־�� ��
	@post: Room�� DrawerList���� �ش��ϴ� Drawer�� ������ ���ŵ�.
	@param: DrawerType for update
	*/
	int UpdateDrawer(DrawerType& data);

	/*
	 @brief: Drawer ���� �ޱ�
	 @pre: Drawer exist. Set drawerID to get
	 @post: Get DrawerType by reference
	 */
	int GetDrawer(DrawerType& data);

	/*
	@brief: DrawerList�� �ִ� Drawer�� ��� display��
	@pre: none
	@post: DrawerList�� �ִ� Drawer�� ������ ȭ�鿡 ��� display��
	*/
	void DisplayAllDrawer();

	/*
	@brief: Room�� ������ display
	@pre: none
	@post: ���� DrawerType�� ���� ������ ������ Room�� ���� display
	*/
	void DisplayInfo();

	 /*
	 @brief: DrawerList ���� �ʱ�ȭ
	 @pre: none
	 @post: set DrawerList initially
	 */
	void ResetList();

	/*
	@brief: DrawerList ����
	@pre: none
	@post: Make DrawerList Empty
	*/
	void MakeEmpty();

	/*
	@brief: ���� Drawer�� ������ �޴´�.
	@pre: set List
	@post: Get Next DrawerType and Increase Pointer
	@return: return Pointer of DrawerList
	*/
	int GetNextDrawer(DrawerType& data);

	bool operator>(const RoomType& data) {
		if (r_ID > data.r_ID) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator<(const RoomType& data) {
		if (r_ID < data.r_ID) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator==(const RoomType& data) {
		if (r_ID == data.r_ID) {
			return true;
		}
		else {
			return false;
		}
	}
	void operator=(const RoomType& data) {
		r_ID = data.r_ID;
		r_Length = data.r_Length;
		r_Name = data.r_Name;
		r_curPointer = data.r_curPointer;
		r_Array = data.r_Array;
	}
};


#endif // !__ROOMTYPE_H
