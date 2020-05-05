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
	DrawerType();					//생성자
	~DrawerType(){}					// default 소멸자

	/*
	@brief: Drawer의 고유 ID 값 받기
	@pre: DrawerID가 설정되어 있어야함
	@post: none
	@return: DrawerID return
	*/
	int GetDrawerID() const;

	/*
	@brief: Room의 고유 ID 값 받기
	@pre: RoomID가 설정되어 있어야함
	@post: none
	@return: RoomID return
	*/
	int GetRoomID();

	/*
	@brief: Drawer의 고유 ID 값 받기
	@pre: DrawerID가 설정되어 있어야함
	@post: none
	@return: DrawerID return
	*/
	string GetDrawerName() const;

	/*
	@brief: Drawer의 종류 값 받기
	@pre: Drawer의 종류가 설정되어 있어야함
	@post: none
	@return: Drawer Type return
	*/
	string GetDrawerType() const;

	/*
	@brief: Drawer에 있는 Container 개수 받기
	@pre: none
	@post: none
	@return: Drawer의 Container의 개수 return
	*/
	int GetNumOfContainer() const;

	/*
	@brief: DrawerID 설정
	@pre: none
	@post: DrawerID 값이 설정됨
	@param: 설정할 DrawerID integer
	*/
	void SetDrawerID(int inID);

	/*
	@brief: Drawer의  종류 설정
	@pre: none
	@post: Drawer의 종류가 설정됨
	@param: 설정할 Drawer 종류 string
	*/
	void SetDrawerName(string inName);

	/*
	@brief: Drawer의  종류 설정
	@pre: none
	@post: Drawer의 종류가 설정됨
	@param: 설정할 Drawer 종류 string
	*/
	void SetDrawerType(string inType);

	/*
	@brief: Drawer의 정보 설정
	@pre: none
	@post: Drawer의 ID, 종류가 설정됨
	@param: 설정할 Drawer의 ID(int), Type(string)
	*/
	void SetDrawerRecord(int inID, string inName, string inType);

	/*
	@brief: DrawerID를 사용자로부터 입력받음
	@pre: none
	@post: DrawerID가 사용자로부터 입력받은 값으로 설정됨 (10~99)
	*/
	void SetDrawerIDfromKB();

	/*
	@brief: Drawer의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Drawer의 종류를 사용자로부터 받음
	*/
	void SetDrawerNamefromKB();

	/*
	@brief: Drawer의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Drawer의 종류를 사용자로부터 받음
	*/
	void SetDrawerTypefromKB();

	/*
	@brief: Drawer에 Container를 추가
	@pre: Container 정보가 설정되어 있어야 함
	@post: Drawer의 ContainerList에 Container가 추가됨.
	@param: ContainerType for add
	*/
	int AddContainer(const ContainerType& data);

	/*
	@brief: Drawer에서 Container를 뺌
	@pre: 뺄 Container의 ID가 설정되어 있어야 함
	@post: Drawer의 ContainerList에서 해당하는 Container가 삭제됨.
	@param: ContainerType for delete
	*/
	int DeleteContainer(ContainerType& data);

	/*
	@brief: Drawer의 Container 정보를 갱신함
	@pre: 갱신할 Container의 정보가 설정되어 있어야 함
	@post: Drawer의 ContainerList에서 해당하는 Container의 정보가 갱신됨.
	@param: ContainerType for update
	*/
	int UpdateContainer(ContainerType& data);

	/*
	@brief: Container의 고유 ID 값 받기
	@pre: ContainerID가 설정되어 있어야함
	@post: none
	@return: ContainerID return
	*/
	int GetContainer(ContainerType& data);

	/*
	@brief: ContainerList에 있는 Container가 모두 display됨
	@pre: none
	@post: ContainerList에 있는 Container의 정보가 화면에 모두 display됨
	*/
	void DisplayAllContainer();

	/*
	@brief: Drawer의 정보를 display
	@pre: none
	@post: 하위 ContainerType에 대한 정보를 제외한 Drawer의 정보 display 
	*/
	void DisplayInfo();

	/*
	@brief: ContainerList 상태 초기화
	@pre: none
	@post: set ContainerList initially
	*/
	void ResetList();

	/*
	@brief: 다음 Container의 정보를 받는다.
	@pre: set List
	@post: Get Next ContainerType and Increase Pointer
	@return: return Pointer of ContainerList
	*/
	int GetNextContainer(ContainerType& data);

	/*
	@brief: ContainerList 비우기
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
