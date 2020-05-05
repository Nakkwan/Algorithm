#ifndef __CONTAINERTYPE_H
#define __CONTAINERTYPE_H

#include "pch.h"

class ContainerType {
private:
	int C_ID;									//container의 ID
	string C_Name;								//Container의 이름
	string C_Type;								//container의 종류
	int numOfitem;								//length of Container List
	string C_Photo;								//container의 사진의 경로
	UnsortedList<SimpleItemType> ItemList;		//Container가 담고 있는 물건 List
public:
	ContainerType();				//생성자
	~ContainerType() {}				//소멸자

	/*
	@brief: Container의 고유 ID 값 받기
	@pre: ContainerID가 설정되어 있어야함
	@post: none
	@return: ContainerID return
	*/
	int GetContainerID() const;

	/*
	@brief: Drawer의 고유 ID 값 받기
	@pre: DrawerID가 설정되어 있어야함
	@post: none
	@return: DrawerID return
	*/
	int GetDrawerID();

	/*
	@brief: Room의 고유 ID 값 받기
	@pre: RoomID가 설정되어 있어야함
	@post: none
	@return: RoomID return
	*/
	int GetRoomID();

	/*
	@brief: Container의 종류 값 받기
	@pre: Container의 종류가 설정되어 있어야함
	@post: none
	@return: Container Type return
	*/
	string GetContainerName() const;

	/*
	@brief: Container의 종류 값 받기
	@pre: Container의 종류가 설정되어 있어야함
	@post: none
	@return: Container Type return
	*/
	string GetContainerType() const;

	/*
	@brief: Container의 사진 경로 받기
	@pre: none
	@post: none
	@return: Photo path of ContainerType return(string)
	*/
	string GetContainerPhoto() const;

	/*
	@brief: Container에 담겨있는 물건 개수 받기
	@pre: none
	@post: none
	@return: Container에 담긴 물건의 개수 return
	*/
	int GetNumOfItem() const;

	/*
	@brief: ContainerID 설정
	@pre: none
	@post: ContainerID 값이 설정됨
	@param: 설정할 ContainerID integer
	*/
	void SetContainerID(int inID);

	/*
	@brief: Container의  이름 설정
	@pre: none
	@post: Container의 이름이 설정됨
	@param: 설정할 Container 이름 string
	*/
	void SetContainerName(string inName);

	/*
	@brief: Container의  종류 설정
	@pre: none
	@post: Container의 종류가 설정됨
	@param: 설정할 Container 종류 string
	*/
	void SetContainerType(string inType);

	/*
	@brief: Container의 사진 경로 설정
	@pre: none
	@post: Container의 사진 경로가 설정됨
	*/
	void SetContainerPhoto(string inPhoto);

	/*
	@brief: Container의 정보 설정
	@pre: none
	@post: container의 ID, 위치, 종류가 설정됨
	@param: 설정할 Container의 ID(int), Location(string), Type(string)
	*/
	void SetContainerRecord(int inID, string inName, string inType, string inPhoto);

	/*
	@brief: Container의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Container의 종류를 사용자로부터 받음
	*/
	void SetContainerIDfromKB();

	/*
	@brief: Container의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Container의 종류를 사용자로부터 받음
	*/
	void SetContainerNamefromKB();

	/*
	@brief: Container의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Container의 종류를 사용자로부터 받음
	*/
	void SetContainerTypefromKB();

	/*
	@brief: Container의 사진 경로를 사용자로부터 입력받음
	@pre: none
	@post: Container의 사진 경로를 사용자로부터 받음
	*/
	void SetContainerPhotofromKB();

	/*
	@brief: Container의 정보를 사용자로부터 입력받음
	@pre: none
	@post: Container의 ID, Location, Type, photo을 사용자로부터 입력받음
	*/
	void SetContainerRecordfromKB();

	/*
	@brief: Container에 물건을 담음
	@pre: 담을 물건의 정보가 설정되어 있어야 함
	@post: Container의 ItemList에 물건이 추가됨.
	@param: 용기에 담을 물건 (SimpleItemType)
	*/
	int AddItem(const SimpleItemType& data);

	/*
	@brief: Container에서 물건을 뺌
	@pre: 뺄 물건의 ID가 설정되어 있어야 함
	@post: Container의 ItemList에서 해당하는 물건이 삭제됨.
	@param: 용기에서 뺄 물건 (SimpleItemType)
	*/
	int DeleteItem(SimpleItemType& data);

	/*
	@brief: Container에 담긴 물건의 정보를 갱신함
	@pre: 갱신할 물건의 정보가 설정되어 있어야 함
	@post: Container의 ItemList에서 해당하는 물건의 정보가 갱신됨.
	@param: 용기에서 갱신할 물건 (SimpleItemType)
	*/
	int UpdateItem(SimpleItemType& data);

	/*
	@brief: ContainerList에 담긴 물건의 정보를 받아옴
	@pre: 받아올 물건의 정보가 설정되어 있어야 함
	@post: Container의 ItemList에서 해당하는 물건의 정보를 reference로 반환.
	@param: 받아올 물건의 ID가 설정된 SimpleItemType
	*/
	int GetItem(SimpleItemType& data);

	/*
	@brief: ItemList에 있는 물건이 모두 display됨
	@pre: none
	@post: ItemList에 있는 물건의 정보가 화면에 모두 display됨
	*/
	void DisplayAllItem();

	/*
	@brief: Container의 정보와, 담긴 물건, 사진의 경로가 모두 화면에 Display됨
	@pre: none
	@post: Container의 정보와, 담긴 물건, 사진의 경로가 모두 화면에 Display됨
	*/
	void DisplayContainer();

	/*
	@brief: ItemList 비우기
	@pre: none
	@post: Make ItemList Empty
	*/
	void MakeConatinerEmpty();

	/*
	@brief: ItemList 초기화
	@pre: none
	@post: Make ItemList initially
	*/
	void ResetList();

	/*
	@brief: 다음 물건 정보 받기
	@pre: st ItemTypeID
	@post: get next item by reference
	*/
	int GetNextItem(SimpleItemType& data);

	/*
	@brief: Container가 같은지 결정
	@pre: ContainerID가 설정이 되어있어야함
	@post: none
	@return: ContainerID가 같으면 1, 다르면 0을 return
	*/
	bool operator==(const ContainerType& data) {
		if (C_ID == data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container 비교
	@pre: 비교할 Container의 ID가 설정되어 있어야 함
	@post: none
	@return: 현재 ContainerID가 더 크면 1, 작으면 0을 return함
	*/
	bool operator>(const ContainerType& data) {
		if (C_ID > data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container 비교
	@pre: 비교할 Container의 ID가 설정되어 있어야 함
	@post: none
	@return: 현재 ContainerID가 더 작으면 1, 크면 0을 return함
	*/
	bool operator<(const ContainerType& data) {
		if (C_ID < data.GetContainerID()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Container의 값을 할당받음
	@pre: 할당할 Container의 정보가 설정되어 있어야함
	@post: parameter로 받은 Container로 현재 Container가 교체됨
	@param: 할당할 Container
	*/
	void operator=(const ContainerType& data) {
		C_ID = data.GetContainerID();
		C_Name = data.GetContainerName();
		C_Type = data.GetContainerType();
		numOfitem = data.GetNumOfItem();
		ItemList = data.ItemList;
		C_Photo = data.GetContainerPhoto();
	}
};


#endif // !__CONTAINERTYPE_H
