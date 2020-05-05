#ifndef __DRAWERTYPE_H
#define __DRAWERTYPE_H

#include "pch.h"

class DrawerType {
private:
	int d_ID;									//DrawerID
	string d_Name;								//DrawerName
	string d_type;								//DrawerType
	int d_length;								//Length of ContainerList
	int d_curPointer;							//Pointer of ContainerList
	SingleLinkedList<ContainerType> d_Array;	//ContainerList
public:
	DrawerType();					//������
	~DrawerType(){}					// default �Ҹ���

	/*
	@brief: Drawer�� ���� ID �� �ޱ�
	@pre: DrawerID�� �����Ǿ� �־����
	@post: none
	@return: DrawerID return
	*/
	int GetDrawerID() const;

	/*
	@brief: Room�� ���� ID �� �ޱ�
	@pre: RoomID�� �����Ǿ� �־����
	@post: none
	@return: RoomID return
	*/
	int GetRoomID();

	/*
	@brief: Drawer�� ���� ID �� �ޱ�
	@pre: DrawerID�� �����Ǿ� �־����
	@post: none
	@return: DrawerID return
	*/
	string GetDrawerName() const;

	/*
	@brief: Drawer�� ���� �� �ޱ�
	@pre: Drawer�� ������ �����Ǿ� �־����
	@post: none
	@return: Drawer Type return
	*/
	string GetDrawerType() const;

	/*
	@brief: Drawer�� �ִ� Container ���� �ޱ�
	@pre: none
	@post: none
	@return: Drawer�� Container�� ���� return
	*/
	int GetNumOfContainer() const;

	/*
	@brief: DrawerID ����
	@pre: none
	@post: DrawerID ���� ������
	@param: ������ DrawerID integer
	*/
	void SetDrawerID(int inID);

	/*
	@brief: Drawer��  ���� ����
	@pre: none
	@post: Drawer�� ������ ������
	@param: ������ Drawer ���� string
	*/
	void SetDrawerName(string inName);

	/*
	@brief: Drawer��  ���� ����
	@pre: none
	@post: Drawer�� ������ ������
	@param: ������ Drawer ���� string
	*/
	void SetDrawerType(string inType);

	/*
	@brief: Drawer�� ���� ����
	@pre: none
	@post: Drawer�� ID, ������ ������
	@param: ������ Drawer�� ID(int), Type(string)
	*/
	void SetDrawerRecord(int inID, string inName, string inType);

	/*
	@brief: DrawerID�� ����ڷκ��� �Է¹���
	@pre: none
	@post: DrawerID�� ����ڷκ��� �Է¹��� ������ ������ (10~99)
	*/
	void SetDrawerIDfromKB();

	/*
	@brief: Drawer�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Drawer�� ������ ����ڷκ��� ����
	*/
	void SetDrawerNamefromKB();

	/*
	@brief: Drawer�� ������ ����ڷκ��� �Է¹���
	@pre: none
	@post: Drawer�� ������ ����ڷκ��� ����
	*/
	void SetDrawerTypefromKB();

	/*
	@brief: Drawer�� Container�� �߰�
	@pre: Container ������ �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList�� Container�� �߰���.
	@param: ContainerType for add
	*/
	int AddContainer(const ContainerType& data);

	/*
	@brief: Drawer���� Container�� ��
	@pre: �� Container�� ID�� �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList���� �ش��ϴ� Container�� ������.
	@param: ContainerType for delete
	*/
	int DeleteContainer(ContainerType& data);

	/*
	@brief: Drawer�� Container ������ ������
	@pre: ������ Container�� ������ �����Ǿ� �־�� ��
	@post: Drawer�� ContainerList���� �ش��ϴ� Container�� ������ ���ŵ�.
	@param: ContainerType for update
	*/
	int UpdateContainer(ContainerType& data);

	/*
	@brief: Container�� ���� ID �� �ޱ�
	@pre: ContainerID�� �����Ǿ� �־����
	@post: none
	@return: ContainerID return
	*/
	int GetContainer(ContainerType& data);

	/*
	@brief: ContainerList�� �ִ� Container�� ��� display��
	@pre: none
	@post: ContainerList�� �ִ� Container�� ������ ȭ�鿡 ��� display��
	*/
	void DisplayAllContainer();

	/*
	@brief: Drawer�� ������ display
	@pre: none
	@post: ���� ContainerType�� ���� ������ ������ Drawer�� ���� display 
	*/
	void DisplayInfo();

	/*
	@brief: ContainerList ���� �ʱ�ȭ
	@pre: none
	@post: set ContainerList initially
	*/
	void ResetList();

	/*
	@brief: ���� Container�� ������ �޴´�.
	@pre: set List
	@post: Get Next ContainerType and Increase Pointer
	@return: return Pointer of ContainerList
	*/
	int GetNextContainer(ContainerType& data);

	/*
	@brief: ContainerList ����
	@pre: none
	@post: Make ContainerList Empty
	*/
	void MakeEmpty();

	bool operator>(const DrawerType& data) {
		if (d_ID > data.d_ID) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(const DrawerType& data) {
		if (d_ID < data.d_ID) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(const DrawerType& data) {
		if (d_ID == data.d_ID) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator=(DrawerType& data) {
		d_ID = data.d_ID;
		d_Name = data.d_Name;
		d_type = data.d_type;
		d_length = data.d_length;
		d_curPointer = data.d_curPointer;
		d_Array = data.d_Array;
	}
};

#endif // !__DRAWERTYPE_H
