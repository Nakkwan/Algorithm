#ifndef __SIMPLEITEMTYPE_H
#define __SIMPLEITEMTYPE_H
#include "pch.h"

class SimpleItemType{
private:
	int S_label;						//����� �������� ���� ��ȣ
	string S_name;						//�������� �̸�
	string S_type;						//�������� type
public:
	SimpleItemType();					//������
	SimpleItemType(int inlabel);		//������
	~SimpleItemType() {}				//�Ҹ���

	/*
	@brief: ���� ID�� ����
	@pre: set unique ID
	@post: none
	@return: unique label
	*/
	int getLabel() const;

	/*
	@brief: get ID of Room
	@pre: set roomID
	@post: none
	@return: roomID
	*/
	int GetRoomID();

	/*
	@brief: get ID of Drawer
	@pre: set drawerID
	@post: none
	@return: drawerID
	*/
	int GetDrawerID();

	/*
	@brief: get ID of Container
	@pre: set containerID
	@post: none
	@return: containerID
	*/
	int GetContainerID();


	/*
	@brief: ������ �̸��� ����
	@pre: set name of object
	@post: none
	@return: name of object
	*/
	string getName() const;

	/*
	@brief:	������ ������ ����
	@pre: set usage of object
	@post: none
	@rreturn: return integer correspond with usage
	*/
	string getType() const;

	/*
	@brief: ���� ID�� ������
	@pre: none
	@post: ���� ID�� ������
	@param: ������ ID integer
	*/
	void setLabel(int inlabel);

	/*
	@brief: ������ �̸��� ������
	@pre: none
	@post: �̸��� ������
	@param: ������ �̸�
	*/
	void setName(string inname);

	/*
	@brief: ������ �뵵�� ������
	@pre: none
	@post: ������ �뵵�� ������
	@param: ������ �뵵�� �ش��ϴ� integer
	*/
	void setType(string intype);

	/*
	@brief: SimpleItemType�� member value�� ������
	@pre: none
	@post: member value�� ������
	@param: member value�� �ش��ϴ� object�� ID, name, usage
	*/
	void setRecord(int inlabel, string inname, string inusage);

	/*
	@brief: ItemType���� SimpleItemType�� ������ ������
	@pre: Set ItemType
	@post: Set value of SimpleItemType by ItemType (ID, Name, Type)
	*/
	void SetRecordByItemType(const ItemType& data);

	/*
	@brief: member value�� display
	@pre: none
	@post: none
	*/
	void DisplayItem();

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ������ 1, �ٸ��� 0�� ����
	*/
	bool operator==(const SimpleItemType& data) {
		if (this->S_label == data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ���� ��ü�� �� ũ�� 1, �ƴϸ� 0�� ����
	*/
	bool operator>(const SimpleItemType& data) {
		if (this->S_label > data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: �� ��ü�� ũ�� �� operator
	@pre: ���� ��ü�� ID ����
	@post: none
	@param: ���� ��ü
	@return: ���� ��ü�� �� ������ 1, �ƴϸ� 0�� ����
	*/
	bool operator<(const SimpleItemType& data) {
		if (this->S_label < data.getLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: assign operator of member value
	@pre: set object for assign
	@post: �ش��ϴ� ������ member value�� ���� �Ҵ��
	@param: ���� �Ҵ��� ��ü
	*/
	void operator=(const SimpleItemType& data) {
		S_label = data.getLabel();
		S_name = data.getName();
		S_type = data.getType();
	}
};


#endif // !
