#pragma once

#include "pch.h"

//보관 장소를 전체적으로 나타내는 Class
class RoomList : public Base {
private:
	UnsortedList<RoomType> R_List;
	int R_length;
public:
	RoomList();
	~RoomList(){}

	/*
	@brief: 방을 추가함
	@pre: Set Room value
	@post: RoomList에 방이 추가됨
	@return: 방이 추가되면 1, 아니면 0을 반환함
	*/
	int RoomAdd(RoomType& data);

	/*
	@brief: 방의 정보를 수정함
	@pre: Set Room value for update
	@post: RoomList에서 해당 방의 정보가 수정됨
	@return: 방 정보가 수정되면 1, 아니면 0을 반환함
	*/
	int RoomUpdate(RoomType& data);

	/*
	@brief: 방의 정보를 받음
	@pre: Set RoomID for get RoomType
	@post: 해당하는 방의 정보가 reference로 반환됨
	@return: 방의 정보를 받으면 1, 아니면 0을 반환함
	*/
	int RoomGet(RoomType& data);

	/*
	@brief: 모든 방의 정보를 출력함
	@pre: none
	@post: none
	@return: 방의 정보가 출력되면 1, 출력될 방이 없으면 0을 반환함
	*/
	int DisplayAllRoomInfo();


	/*
	@brief: 수납장을 추가함
	@pre: Set Drawer value
	@post: 해당하는 Room의 DrawerList에 수납장이 추가됨
	@return: 수납장이 추가되면 1, 아니면 0을 반환함
	*/
	int DrawerAdd(DrawerType& data);

	/*
	@brief: 수납장을 삭제함
	@pre: Set DrawerID for delete
	@post: 해당하는 Room의 DrawerList의 수납장이 삭제됨
	@return: 수납장이 삭제되면 1, 아니면 0을 반환함
	*/
	int DrawerDelete(DrawerType& data);

	/*
	@brief: 수납장의 정보를 수정함
	@pre: Set Drawer value for update
	@post: 해당하는 수납장의 정보가 수정됨
	@return: 수납장의 정보가 수정되면 1, 아니면 0을 반환함
	*/
	int DrawerUpdate(DrawerType& data);

	/*
	@brief: 수납장과 해당되는 방의 정보를 받음
	@pre: Set RoomID about Drawer, and DrawerID for Get
	@post: 해당하는 수납장과 방의 정보가 reference로 반환됨
	@return: 정보를 받으면 1, 아니면 0을 반환함
	*/
	int DrawerGet(RoomType& rodata, DrawerType& data);

	/*
	@brief: 모든 수납장의 정보를 출력함
	@pre: none
	@post: none
	@return: 수납장의 정보가 출력되면 1, 출력될 수납장이 없으면 0을 반환함
	*/
	int DisplayAllDrawerInfo();


	/*
	@brief: 수납장 안의 상자을 추가함
	@pre: Set Container value for add
	@post: 해당하는 Drawer의 ContainerList에 Container가 추가됨
	@return: Container가 추가되면 1, 아니면 0을 반환함
	*/
	int ContainerAdd(ContainerType& data);

	/*
	@brief: Container를 삭제함
	@pre: Set ContainerID for delete
	@post: 해당하는 Container가 삭제됨
	@return: Container가 삭제되면 1, 아니면 0을 반환함
	*/
	int ContainerDelete(ContainerType& data);

	/*
	@brief: Container의 정보를 수정함
	@pre: Set Container value for update
	@post: 해당하는 Container의 정보가 수정됨
	@return: Container의 정보가 수정되면 1, 아니면 0을 반환함
	*/
	int ContainerUpdate(ContainerType& data);

	/*
	@brief: Container와 해당되는 수납장, 방의 정보를 받음
	@pre: Set RoomID, DrawerID about Container, and ContainerID for Get
	@post: 해당하는 Container, 수납장, 방의 정보가 reference로 반환됨
	@return: 정보를 받으면 1, 아니면 0을 반환함
	*/
	int ContainerGet(RoomType& rodata, DrawerType& drdata, ContainerType& data);

	/*
	@brief: 모든 Container의 정보를 출력함
	@pre: none
	@post: none
	@return: Container의 정보가 출력되면 1, 출력될 Container가 없으면 0을 반환함
	*/
	int DisplayAllContainerInfo();


	/*
	@brief: 물건을 추가함
	@pre: Set Object value for add
	@post: 설정된 보관 공간에 물건의 정보가 추가됨
	@return: 물건이 추가되면 1, 아니면 0을 반환함
	*/
	int ObjectAdd(SimpleItemType& data);

	/*
	@brief: 물건을 삭제함
	@pre: Set ObjectID for delete
	@post: 보관 장소에서 물건이 삭제됨
	@return: 물건이 삭제되면 1, 아니면 0을 반환함
	*/
	int ObjectDelete(SimpleItemType& data);

	/*
	@brief: 물건을 정보를 수정함
	@pre: Set Object value for add
	@post: 해당하는 물건의 정보가 수정됨
	@return: 물건의 정보가 수정되면 1, 아니면 0을 반환함
	*/
	int ObjectUpdate(SimpleItemType& data);

	/*
	@brief: 물건의 정보와 해당되는 Container, 수납장, 방의 정보를 받음
	@pre: Set RoomID, DrawerID, ContainerID about Object, and ObjectID for Get
	@post: 해당하는 물건, Container, 수납장, 방의 정보가 reference로 반환됨
	@return: 정보를 받으면 1, 아니면 0을 반환함
	*/
	int ObjectGet(RoomType& rodata, DrawerType& drdata, ContainerType& codata, SimpleItemType& data);

	/*
	@brief: 모든 물건의 정보를 출력함
	@pre: none
	@post: none
	@return: 물건의 정보가 출력되면 1, 출력될 물건이 없으면 0을 반환함
	*/
	int DisplayAllObjectInfo();

	/*
	@brief: RoomList의 상태를 초기화함
	@pre: none
	@post: initialize List
	*/
	void ResetList();
};