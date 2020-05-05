#ifndef __SIMPLEITEMTYPE_H
#define __SIMPLEITEMTYPE_H
#include "pch.h"

class SimpleItemType{
private:
	int S_label;						//저장된 아이템의 고유 번호
	string S_name;						//아이템의 이름
	string S_type;						//아이템의 type
public:
	SimpleItemType();					//생성자
	SimpleItemType(int inlabel);		//생성자
	~SimpleItemType() {}				//소멸자

	/*
	@brief: 고유 ID를 받음
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
	@brief: 물건의 이름를 받음
	@pre: set name of object
	@post: none
	@return: name of object
	*/
	string getName() const;

	/*
	@brief:	물건의 종류를 받음
	@pre: set usage of object
	@post: none
	@rreturn: return integer correspond with usage
	*/
	string getType() const;

	/*
	@brief: 고유 ID를 설정함
	@pre: none
	@post: 고유 ID가 설정됨
	@param: 설정할 ID integer
	*/
	void setLabel(int inlabel);

	/*
	@brief: 물건의 이름를 설정함
	@pre: none
	@post: 이름이 설정됨
	@param: 설정할 이름
	*/
	void setName(string inname);

	/*
	@brief: 물건의 용도를 설정함
	@pre: none
	@post: 물건의 용도가 설정됨
	@param: 물건의 용도에 해당하는 integer
	*/
	void setType(string intype);

	/*
	@brief: SimpleItemType의 member value를 설정함
	@pre: none
	@post: member value가 설정됨
	@param: member value에 해당하는 object의 ID, name, usage
	*/
	void setRecord(int inlabel, string inname, string inusage);

	/*
	@brief: ItemType으로 SimpleItemType의 정보를 설정함
	@pre: Set ItemType
	@post: Set value of SimpleItemType by ItemType (ID, Name, Type)
	*/
	void SetRecordByItemType(const ItemType& data);

	/*
	@brief: member value를 display
	@pre: none
	@post: none
	*/
	void DisplayItem();

	/*
	@brief: 두 객체의 크기 비교 operator
	@pre: 비교할 객체의 ID 설정
	@post: none
	@param: 비교할 객체
	@return: 같으면 1, 다르면 0을 리턴
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
	@brief: 두 객체의 크기 비교 operator
	@pre: 비교할 객체의 ID 설정
	@post: none
	@param: 비교할 객체
	@return: 현재 객체가 더 크면 1, 아니면 0을 리턴
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
	@brief: 두 객체의 크기 비교 operator
	@pre: 비교할 객체의 ID 설정
	@post: none
	@param: 비교할 객체
	@return: 현재 객체가 더 작으면 1, 아니면 0을 리턴
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
	@post: 해당하는 값으로 member value의 값이 할당됨
	@param: 값을 할당할 객체
	*/
	void operator=(const SimpleItemType& data) {
		S_label = data.getLabel();
		S_name = data.getName();
		S_type = data.getType();
	}
};


#endif // !
