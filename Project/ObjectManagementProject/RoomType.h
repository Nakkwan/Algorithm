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
	void AddDrawer(const DrawerType& data);

	/*
	@brief: Room에서 Drawer를 뺌
	@pre: 뺄 Drawer의 ID가 설정되어 있어야 함
	@post: Room의 DrawerList에서 해당하는 Drawer가 삭제됨.
	@param: DrawerType for delete
	*/
	void DeleteDrawer(DrawerType& data);

	/*
	@brief: Room의 Drawer 정보를 갱신함
	@pre: 갱신할 Drawer의 정보가 설정되어 있어야 함
	@post: Room의 DrawerList에서 해당하는 Drawer의 정보가 갱신됨.
	@param: DrawerType for update
	*/
	void UpdateDrawer(DrawerType& data);

	/*
	@brief: DrawerList에 있는 Drawer가 모두 display됨
	@pre: none
	@post: DrawerList에 있는 Drawer의 정보가 화면에 모두 display됨
	*/
	void DiplayAllDrawer();

	/*
	@brief: Room의 정보를 모두 display
	@pre: none
	@post: none
	*/
	void DisplayInfo();
};


#endif // !__ROOMTYPE_H
