#ifndef __CONTAINERTYPE_H
#define __CONTAINERTYPE_H

#include "SimpleItemType.h"
#include "UnsortedList.h"
#include "Base.h"

class ContainerType : public Base {
private:
	int C_ID;				//container의 ID
	string C_Name;
	string C_Type;			//container의 종류
	int numOfPhoto;
	int numOfitem;
	UnsortedList<string> photoList;			//container의 사진의 경로 List
	UnsortedList<SimpleItemType> ItemList;	//Container가 담고 있는 물건 List
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
	@brief: Container에 담겨있는 물건 개수 받기
	@pre: none
	@post: none
	@return: Container에 담긴 물건의 개수 return
	*/
	int GetNumOfItem() const;

	/*
	@brief: Container의 사진 개수 받기
	@pre: none
	@post: none
	@return: Container를 찍은 사진의 개수 return
	*/
	int GetNumOfPhoto() const;

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
	@brief: Container의 정보 설정
	@pre: none
	@post: container의 ID, 위치, 종류가 설정됨
	@param: 설정할 Container의 ID(int), Location(string), Type(string)
	*/
	void SetContainerRecord(int inID, string inName, string inType);

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
	@brief: Container의 정보를 사용자로부터 입력받음
	@pre: none
	@post: Container의 ID, Location, Type을 사용자로부터 입력받음
	*/
	void SetContainerRecordfromKB();

	/*
	@brief: Container에 물건을 담음
	@pre: 담을 물건의 정보가 설정되어 있어야 함
	@post: Container의 ItemList에 물건이 추가됨.
	@param: 용기에 담을 물건 (SimpleItemType)
	*/
	void AddItem(const SimpleItemType& data);

	/*
	@brief: Container에서 물건을 뺌
	@pre: 뺄 물건의 ID가 설정되어 있어야 함
	@post: Container의 ItemList에서 해당하는 물건이 삭제됨.
	@param: 용기에서 뺄 물건 (SimpleItemType)
	*/
	void DeleteItem(SimpleItemType& data);

	/*
	@brief: Container에 담긴 물건의 정보를 갱신함
	@pre: 갱신할 물건의 정보가 설정되어 있어야 함
	@post: Container의 ItemList에서 해당하는 물건의 정보가 갱신됨.
	@param: 용기에서 갱신할 물건 (SimpleItemType)
	*/
	void UpdateItem(SimpleItemType data);


	/*
	@brief: 용기의 사진이 있는 경로를 추가함
	@pre: 해당 ContainerID가 설정되어 있어야하고 container를 찍은 사진이 있어야함
	@post: Container의 사진을 담은 경로가 PhotoList에 추가됨
	@param: 사진이 있는 경로를 나타내는 string
	*/
	void AddPhoto(string pho);

	/*
	@brief: 용기의 사진이 있는 경로를 삭제함
	@pre: 해당하는 사진의 ContainerID와 경로가 존재해야 함
	@post: Container의 사진을 담은 경로가 PhotoList에서 삭제됨
	@param: 삭제할 사진이 있는 경로를 나타내는 string
	*/
	void DeletePhoto(string pho);

	/*
	@brief: 용기의 사진이 있는 경로를 갱신함
	@pre: 해당하는 사진의 경로와 해당 ContainerID가 존재해야 함
	@post: Container의 사진을 담은 경로가 PhotoList에서 갱신됨
	@param: 갱신할 사진이 있는 경로를 나타내는 string
	*/
	void UpdatePhoto(string pho);

	/*
	@brief: ItemList에 있는 물건이 모두 display됨
	@pre: none
	@post: ItemList에 있는 물건의 정보가 화면에 모두 display됨
	*/
	void DisplayAllItem();

	/*
	@brief: PhotoList에 있는 Container의 사진이 모두 display됨
	@pre: none
	@post: PhotoList에 있는 Container의 사진의 경로가 모두 display됨
	*/
	void DisplayAllPhoto();

	/*
	@brief: Container의 정보와, 담긴 물건, 사진의 경로가 모두 화면에 Display됨
	@pre: none
	@post: Container의 정보와, 담긴 물건, 사진의 경로가 모두 화면에 Display됨
	*/
	void DisplayContainer();

	void MakeConatinerEmpty();

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
		numOfPhoto = data.GetNumOfPhoto();
		numOfitem = data.GetNumOfItem();
		ItemList = data.ItemList;
		photoList = data.photoList;
	}
};


#endif // !__CONTAINERTYPE_H
