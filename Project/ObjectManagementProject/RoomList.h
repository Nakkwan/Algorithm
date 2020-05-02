#pragma once

#include "pch.h"

class RoomList : public Base {
private:
	UnsortedList<RoomType> R_List;
	int R_length;
public:
	RoomList();
	~RoomList(){}

	//About Room
	int RoomAdd(RoomType& data);
	int RoomDelete(RoomType& data);
	int RoomUpdate(RoomType& data);
	int RoomGet(RoomType& data);
	int DisplayAllRoomInfo();

	int DrawerAdd(DrawerType& data);
	int DrawerDelete(DrawerType& data);
	int DrawerUpdate(DrawerType& data);
	int DrawerGet(RoomType& rodata, DrawerType& data);
	int DisplayAllDrawerInfo();

	int ContainerAdd(ContainerType& data);
	int ContainerDelete(ContainerType& data);
	int ContainerUpdate(ContainerType& data);
	int ContainerGet(RoomType& rodata, DrawerType& drdata, ContainerType& data);
	int DisplayAllContainerInfo();

	int ObjectAdd(SimpleItemType& data);
	int ObjectDelete(SimpleItemType& data);
	int ObjectUpdate(SimpleItemType& data);
	int ObjectGet(RoomType& rodata, DrawerType& drdata, ContainerType& codata, SimpleItemType& data);
	int DisplayAllObjectInfo();
};