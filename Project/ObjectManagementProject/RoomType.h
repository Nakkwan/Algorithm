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
	@brief: Room의 고유 ID 값 받기
	@pre: RoomID가 설정되어 있어야함
	@post: none
	@return: RoomID return
	*/
	int GetRoomID() const;

	/*
	@brief: Room의 종류 값 받기
	@pre: Room의 종류가 설정되어 있어야함
	@post: none
	@return: Room Type return
	*/
	string GetRoomName() const;

	/*
	@brief: Room에 있는 Drawer 개수 받기
	@pre: none
	@post: none
	@return: Room의 Drawer의 개수 return
	*/
	int GetNumOfDrawer() const;

	/*
	@brief: RoomID 설정
	@pre: none
	@post: RoomID 값이 설정됨
	@param: 설정할 RoomID integer
	*/
	void SetRoomID(int inID);

	/*
	@brief: Room의  종류 설정
	@pre: none
	@post: Room의 종류가 설정됨
	@param: 설정할 Room 종류 string
	*/
	void SetRoomName(string inType);

	/*
	@brief: Room의 정보 설정
	@pre: none
	@post: Room의 ID, 종류가 설정됨
	@param: 설정할 Room의 ID(int), Type(string)
	*/
	void SetRoomRecord(int inID, string inType);


	/*
	@brief: RoomID를 사용자로부터 입력받음
	@pre: none
	@post: RoomID가 사용자로부터 입력받은 값으로 설정됨 (1~9)
	*/
	void SetRoomIDfromKB();

	/*
	@brief: Room의 종류를 사용자로부터 입력받음
	@pre: none
	@post: Room의 종류를 사용자로부터 받음
	*/
	void SetRoomNamefromKB();


	/*
	@brief: Room에 Drawer를 추가
	@pre: Drawer 정보가 설정되어 있어야 함
	@post: Room의 DrawerList에 Drawer가 추가됨.
	@param: DrawerType for add
	*/
	int AddDrawer(DrawerType& data);

	/*
	@brief: Room에서 Drawer를 뺌
	@pre: 뺄 Drawer의 ID가 설정되어 있어야 함
	@post: Room의 DrawerList에서 해당하는 Drawer가 삭제됨.
	@param: DrawerType for delete
	*/
	int DeleteDrawer(DrawerType& data);

	/*
	@brief: Room의 Drawer 정보를 갱신함
	@pre: 갱신할 Drawer의 정보가 설정되어 있어야 함
	@post: Room의 DrawerList에서 해당하는 Drawer의 정보가 갱신됨.
	@param: DrawerType for update
	*/
	int UpdateDrawer(DrawerType& data);

	/*
	 @brief: Drawer 정보 받기
	 @pre: Drawer exist. Set drawerID to get
	 @post: Get DrawerType by reference
	 */
	int GetDrawer(DrawerType& data);

	/*
	@brief: DrawerList에 있는 Drawer가 모두 display됨
	@pre: none
	@post: DrawerList에 있는 Drawer의 정보가 화면에 모두 display됨
	*/
	void DisplayAllDrawer();

	/*
	@brief: Room의 정보를 display
	@pre: none
	@post: 하위 DrawerType에 대한 정보를 제외한 Room의 정보 display
	*/
	void DisplayInfo();

	 /*
	 @brief: DrawerList 상태 초기화
	 @pre: none
	 @post: set DrawerList initially
	 */
	void ResetList();

	/*
	@brief: DrawerList 비우기
	@pre: none
	@post: Make DrawerList Empty
	*/
	void MakeEmpty();

	/*
	@brief: 다음 Drawer의 정보를 받는다.
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
