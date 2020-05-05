#ifndef __ITEMTYPE_H
#define __ITEMTYPE_H
#include "pch.h"


class ItemType{
public:
	ItemType() {			//constructor
		O_Name = "";
		O_BuyDate = -1;
		O_Label = -1;
		O_Type = "";
		O_Volume = -1;
		O_SearchNum = -1;
		O_RoomID = -1;
		O_DrawerID = -1;
		O_ContainerID = -1;
		O_Picture = "None";
	}
	~ItemType() {}	//destructor

	/*
	@brief: get object name
	@pre: set object name
	@post: none
	@return: object name
	*/
	string GetName() const;

	/*
	@brief: get object writer
	@pre: set buy date
	@post: none
	@return: buy date
	*/
	int GetBuyDate() const;

	/*
	@brief: get unique label
	@pre: set unique label
	@post: none
	@return: unique label
	*/
	int GetLabel() const;

	/*
	@brief: get type of object
	@pre: set type
	@post: none
	@return: type
	*/
	string GetType() const;

	/*
	@brief: get number of object
	@pre: set volume
	@post: none
	@return: volume
	*/
	int GetVolume() const;

	/*
	@brief: get ID of Container
	@pre: set containerID
	@post: none
	@return: containerID
	*/
	int GetContainerID() const;

	/*
	@brief: get ID of Drawer
	@pre: set drawerID
	@post: none
	@return: drawerID
	*/
	int GetDrawerID() const;

	/*
	@brief: get ID of Room
	@pre: set roomID
	@post: none
	@return: roomID
	*/
	int GetRoomID() const;

	/*
	@brief: get picture name(path) of object
	@pre: set picture name(path)
	@post: none
	@return: picture name(path)
	*/
	string GetPicture() const;

	/*
	@brief: set object name
	@pre: none
	@post: assign object name
	@param: object name
	*/
	void SetName(string inName);

	/*
	@brief: set buy date of object
	@pre: none
	@post: assign buy date
	@param: buy date
	*/
	void SetBuyDate(int inDate);

	/*
	@brief: set unique label
	@pre: none
	@post: assign unique label
	@param: label
	*/
	void SetLabel(int inLabel);

	void SetContainerID();
	
	void SetDrawerID();

	void SetRoomID();

	/*
	@brief: set type
	@pre: none
	@post: assign type of object
	@param: type
	*/
	void SetType(string inType);

	/*
	@brief: set number of object
	@pre: none
	@post: assign number of object
	@param: object number
	*/
	void SetVolume(int inVolume);

	/*
	@brief: set picture name(path) of object
	@pre: none
	@post: assign picture name(path) of object
	@param: picture name(path) of object
	*/
	void SetPicture(string inPic);

	/*
	@brief: set elememt of ItemType member value
	@pre: none
	@post: assign name, buydate, label, type, volume
	@param: _inName name, _inBuyDate BuyDate, _inLabel label, _inType Type, _inVolume volume
	*/
	void SetRecord(string inName, int inDate, string inType, int inLabel, int inVolume);

	/*
	@brief: set elememt of ItemType member value
	@pre: none
	@post: assign ItemType
	@param: ItemType for assign member value
	*/
	void SetRecordByItem(const ItemType& data);

	/*
	@brief: display name of ItemType on screen
	@pre: set name
	@post: display name
	*/
	void DisplayNameOnScreen();

	/*
	@brief: display buy date of ItemType on screen
	@pre: set buy date
	@post: display buy date
	*/
	void DisplayDateOnScreen();

	/*
	@brief: display label of ItemType on screen
	@pre: set label
	@post: display label
	*/
	void DisplayLabelOnScreen();

	/*
	@brief: display type of ItemType on screen
	@pre: set type
	@post: display type
	*/
	void DisplayTypeOnScreen();

	/*
	@brief: display volume of ItemType on screen
	@pre: set volume
	@post: display volume
	*/
	void DisplayVolumeOnScreen();

	/*
	@brief: display ContainerID of ItemType on screen
	@pre: set ContainerID
	@post: display ContainerID
	*/
	void DisplayContainerIDOnScreen();

	/*
	@brief: display DrawerID of ItemType on screen
	@pre: set DrawerID
	@post: display DrawerID
	*/
	void DisplayDrawerIDOnScreen();

	/*
	@brief: display RoomID of ItemType on screen
	@pre: set RoomID
	@post: display RoomIDs
	*/
	void DisplayRoomIDOnScreen();	

	/*
	@brief: display picture name(path) of ItemType on screen
	@pre: set picture
	@post: display picture
	*/
	void DisplayPictureOnScreen();

	/*
	@brief: display member value of ItemType on screen
	@pre: set name, buydate, label, type, volume
	@post: display member value of ItemType
	*/
	void DisplayRecordOnScreen();

	/*
	@brief: set name of object receive input from keyboard
	@pre: none
	@post: assign name from the keyboard
	*/
	void SetNameFromKB();

	/*
	@brief: set buy date receive input from keyboard
	@pre: none
	@post: assign buy date from the keyboard
	*/
	void SetDateFromKB();

	bool CheckDate(int year, int month, int day);

	/*
	@brief: set label receive input from keyboard
	@pre: none
	@post: assign label from the keyboard. 입력받는 label은 containerID와 고유 ID(10~99)의 합이어야함
	*/
	void SetLabelFromKB();

	/*
	@brief: set temporary label receive input from keyboard
	@pre: none
	@post: assign temporary label from the keyboard. 아직 위치가 설정되지 않았기에, containerID를 포함하지않는 (10~99)사이의 값
	*/
	void SetTempLabelFromKB();

	void DisplayTypeList();	

	/*
	@brief: set type receive input from keyboard
	@pre: none
	@post: assign type from the keyboard
	*/
	void SetTypeFromKB();

	/*
	@brief: set number of object receive input from keyboard
	@pre: none
	@post: assign volume from the keyboard
	*/
	void SetVolumeFromKB();

	void SetContainerIDFromKB();

	void SetDrawerIDFromKB();

	void SetRoomIDFromKB();

	/*
	@brief: Set Picture name(path) of object
	@pre: none
	@post: set picture name of object picture from keyboard
	*/
	void SetPictureFromKB();

	/*
	@brief: set member value of ItemType receive input from keyboard
	@pre: none
	@post: assign member value from the keyboard
	*/
	void SetRecordFromKB();

	/*
	@brief: set ItemType member value before lacate the item
	@pre: none
	@post: assign member value except containerID
	@param: ItemType for assign member value except containerID
	*/
	void SetTempfromKB();

	/*
	@brief: Read data from file
	@pre: have a file containing data
	@post: object set data from file
	@param: input file object
	@return: 0 read fail, 1 success
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	@brief: Write data from file
	@pre: set member value
	@post: file include data
	@param: output file object
	@return: 0 write fail, 1 success
	*/
	int WriteDataToFile(ofstream& fout);

	/*
	@brief: 검색횟수를 늘린다.
	@pre: none
	@post: increase O_SearchNum
	*/
	void AddSearchNum() {
		O_SearchNum++;
	}

	/*
	@brief: get searchNum
	@pre: none
	@post: none
	@return: return O_searchNum
	*/
	int GetSearchNum() const {
		return O_SearchNum;
	}

	/*
	@brief: Decide two ItemType is same
	@pre: set unique label of two object
	@post: none
	@param: ItemType to compare
	@return: if same, return 1 if differ, return 0
	*/
	bool operator==(const ItemType& data) {			//제너릭하게 프로그램을 구성하기 위해서 RelationType 대신 연산자 오버로딩
		if (this->O_Label == data.GetLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Decide if current itemtype is bigger
	@pre: set unique label of two object
	@post: none
	@param: ItemType for compare
	@return: if bigger, return 1 if smaller, return 0
	*/
	bool operator>(const ItemType& data) {
		if (this->O_Label > data.GetLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	@brief: Decide if current itemtype is smaller
	@pre: set unique label of two object
	@post: none
	@param: ItemType for compare
	@return: if smaller, return 1 if bigger, return 0
	*/
	bool operator<(const ItemType& data) {
		if (this->O_Label < data.GetLabel()) {
			return true;
		}
		else {
			return false;
		}
	}


	/*
	@brief: assign data
	@pre: set data to be changed
	@post: member value is replaced by parameter
	*/
	void operator=(const ItemType& data) {
		O_Name = data.GetName();
		O_Label = data.GetLabel();
		O_RoomID = data.GetRoomID();
		O_DrawerID = data.GetDrawerID();
		O_ContainerID = data.GetContainerID();
		O_Type = data.GetType();
		O_BuyDate = data.GetBuyDate();
		O_Volume = data.GetVolume();
		O_Picture = data.GetPicture();
		O_SearchNum = data.GetSearchNum();
	}

private:
	string O_Name;
	int O_Label;
	int O_BuyDate;
	string O_Type;
	string O_Picture;
	int O_Volume;
	int O_SearchNum;
	int O_RoomID;
	int O_DrawerID;
	int O_ContainerID;
	static SingleLinkedList<string> O_TypeList;
};

#endif
