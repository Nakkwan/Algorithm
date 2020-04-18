#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum RelationType{ LESS, GREATER, EQUAL };

class ItemType {
public:
	ItemType() {			//constructor
		O_Name = "";
		O_BuyDate = -1;
		O_Label = -1;
		O_Type = -1;
		O_Volume = -1;
		O_Total++;
	}
	~ItemType() {
		O_Total--;
	}			//destructor

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
	string GetBuyDate() const;

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
	int GetType() const;

	/*
	@brief: get number of object 
	@pre: set volume
	@post: none
	@return: volume
	*/
	int GetVolume() const;

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
	void SetBuyDate(string inDate);

	/*
	@brief: set unique label
	@pre: none
	@post: assign unique label
	@param: label
	*/
	void SetLabel(int inLabel);

	/*
	@brief: set type
	@pre: none
	@post: assign type of object
	@param: type
	*/
	void SetType(int inType);

	/*
	@brief: set number of object
	@pre: none
	@post: assign number of object
	@param: object number
	*/
	void SetVolume(int inVolume);

	/*
	@brief: set elememt of ItemType member value
	@pre: none
	@post: assign name, buydate, label, type, volume
	@param: _inName name, _inBuyDate BuyDate, _inLabel label, _inType Type, _inVolume volume
	*/
	void SetRecord(string inName, string inBuyDate, int inLabel, int inType, int inVolume);

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

	/*
	@brief: set label receive input from keyboard
	@pre: none
	@post: assign label from the keyboard
	*/
	void SetLabelFromKB();

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

	/* 
	@brief: set member value of ItemType receive input from keyboard
	@pre: none
	@post: assign member value from the keyboard
	*/
	void SetRecordFromKB();

	/*
	@brief: Read data from file
	@pre: have a file containing data
	@post: object set data from file
	@param: input file object
	@return: 0 read fail, 1 success
	*/
	int ReadDataFromFile(std::ifstream& fin);

	/*
	@brief: Write data from file
	@pre: set member value 
	@post: file include data
	@param: output file object
	@return: 0 write fail, 1 success
	*/
	int WriteDataToFile(std::ofstream& fout);

	/*
	@brief: Get number of total number of different object
	@pre: set Total number of object
	@post: none
	@return: get number of object
	*/
	int GetTotalObjectNum();

	/*
	@brief: Compare data by unique label
	@pre: set label of two object
	@post: none
	@param: data for comparing
	@return: return EQUAL if two label is same
			 return LESS if parameter label is bigger
			 return GREATER if parameter label is smaller
	*/
	RelationType CompareByLabel(const ItemType& data);

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
		O_BuyDate = data.GetBuyDate();
		O_Label = data.GetLabel();
		O_Type = data.GetType();
		O_Volume = data.GetVolume();
	}

private:
	string O_Name; 
	int O_Label;
	string O_BuyDate;
	int O_Type;
	int O_Volume;
	static int O_Total;
};

#endif
