#pragma once
#include "pch.h"


class Application : public Base {
private:
	int a_Command;
	ifstream a_inFile;
	ofstream a_outFile;
public:
	Application() {
		a_Command = -1;
	}									//생성자
	~Application() {}					//소멸자


	/*
	@brief: program driver
	@pre: program start
	@post: program finish
	*/
	void Run();

	/*
	@brief: MasterList program driver
	@pre: program start
	@post: none
	*/
	void RunDisplay();

	/*
	@brief: RoomList program driver
	@pre: program start
	@post: none
	*/
	void RunSetting();

	/*
	@brief: TempList program driver
	@pre: program start
	@post: none
	*/
	void RunSearching();

	/*
	@brief: Display List of Recent Search
	@pre: set List and search more than one time
	@post: Display List of Recent Search
	*/
	void DisplayRecentList();

	/*
	@brief: Display List of most Search object List
	@pre: set List and search more than one time
	@post: Display List of most Search object List
	*/
	void DisplayBestList();

	/*
	@brief: Display command on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetCommand();

	/*
	@brief: Display command about display on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetDisplayCommand();

	/*
	@brief: Display command about enviroment setting on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetSettingCommand();

	/*
	@brief: Display command about searching on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetSearchingCommand();

	/*
	@brief: Display command about room setting on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetRoomCommand();

	/*
	@brief: Display command about drawer setting on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetDrawerCommand();

	/*
	@brief: Display command about container setting on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetContainerCommand();

	/*
	@brief: Display command about Object on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetItemCommand();

	/*
	@brief: Display command about temporary object on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetTempCommand();

	/*
	@brief: MasterList에 물건 추가
	@pre: List가 꽉 차있지 않아야 한다.
	@post: MasterList에 물건을 추가하고 해당하는 container를 갱신함
	*/
	int MasterAddObject();				//MasterList 설정

	/*
	@brief: MasterList에서 물건 삭제
	@pre: 삭제할 물건의 ID가 List에 있어야 한다.
	@post: MasterList에 물건을 삭제하고 해당하는 container를 갱신함
	*/
	int MasterDeleteObject();

	/*
	@brief: MasterList에 물건 교체
	@pre: none
	@post: MasterList에 물건을 교체하고 해당하는 container를 갱신함
	*/
	int MasterUpdateObject();

	/*
	@brief: MasterList에서 ID로 물건 찾기
	@pre: none
	@post: MasterList에서 해당하는 물건의 정보를 화면에 display
	*/
	int MasterRetrieveObject();


	/*
	@brief: MasterList에서 이름으로 물건 찾기
	@pre: none
	@post: MasterList에서 해당하는 물건의 정보를 화면에 display
	*/
	int MasterRetrieveObjectByName();


	/*
	@brief: MasterList에서 용도로 물건 찾기
	@pre: none
	@post: MasterList에서 해당하는 물건의 정보를 화면에 display
	*/
	int MasterRetrieveObjectByUsage();

	/*
	@brief:
	@pre:
	@post:
	*/
	int MasterRetrieveObjectByBuyDate();

	/*
	@brief: 정리한 물건들을 전부 display
	@pre: none
	@post: MasterList에 있는 물건들의 정보를 모두 display함
	*/
	void DisplayAllObject();

	/*
	@brief:	Open a file as a read mode, read all data on the file, and set list by the data.
	@pre: The file is not opened.
	@post: list holds all records from the file.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/*
	@brief:Open a file as a write mode, and write all data into the file,
	@pre: The file is not opened.
	@post: the list is stored in the output file.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/*
	@brief: Add Room
	@pre: none
	@post: add room at List of Room
	*/
	void RoomAdd();

	/*
	@brief: update Room info
	@pre: set Room
	@post: update information of the Room
	*/
	void RoomUpdate();

	void RoomDelete();

	/*
	@brief: 해당 방을 찾는다
	@pre: Size of RoomList is bigger than 1
	@post: Display information of Room
	*/
	int RoomSearch();

	/*
	@brief: 방의 정보를 설정한다.
	@pre: set Room
	@post: 해당 방에 대한 내용을 설정한다. 
	*/
	void RoomSet();

	/*
	@brief: 방에 있는 모든 물건의 정보를 출력한다.
	@pre: none
	@post: 방에 있는 모든 물건의 정보를 출력한다.
	*/
	void DisplayAllRoomItem();

	/*
	@brief: 서랍장 추가
	@pre: none
	@post: RoomClass의 서랍장 List에 서랍장이 추가된다. 
	*/
	void DrawerAdd();

	/*
	@brief: 해당 서랍장을 삭제한다.
	@pre: 삭제할 서랍장이 존재해야함
	@post: List에서 서랍장이 삭제된다.
	*/
	void DrawerDelete();

	/*
	@brief: 서랍장의 정보를 갱신한다.
	@pre: 정보를 갱신할 서랍장이 존재해야함
	@post: 해당 서랍장의 정보가 갱신된다.
	*/
	void DrawerUpdate();

	/*
	@brief: 서랍장 검색
	@pre: 검색할 서랍장이 존재해야함
	@post: 해당 서랍장에 대한 정보가 출력됨
	*/
	int DrawerSearch();


	/*
	@brief: 서랍장의 상세 정보를 설정한다. 
	@pre: none
	@post: Container 관련 함수 호출을 위한 command함수 호출
	*/
	void DrawerSet();

	/*
	@brief: 서랍장에 있는 모든 물건의 정보를 출력한다.
	@pre: none
	@post: none
	*/
	void DisplayAllDrawerItem();

	/*
	@brief: 서랍장의 층수를 추가한다.
	@pre: set drawer
	@post: add container
	*/
	void ContainerAdd();

	/*
	@brief: 해당 서랍을 삭제한다.
	@pre: 삭제할 서랍이 존재해야함
	@post: List에서 서랍이 삭제된다.
	*/
	void ContainerDelete();

	/*
	@brief: 서랍의 정보를 갱신한다.
	@pre: 정보를 갱신할 서랍이 존재해야함
	@post: 해당 서랍의 정보가 갱신된다.
	*/
	void ContainerUpdate();

	/*
	@brief: 서랍 검색
	@pre: 검색할 서랍이 존재해야함
	@post: 해당 서랍에 대한 정보가 출력됨
	*/
	int ContainerSearch();

	/*
	@brief: 서랍의 상세 정보를 설정한다.
	@pre: none
	@post: Item과 photo 관련 함수 호출을 위한 command함수 호출
	*/
	void ContainerSet();

	/*
	@brief: 서랍에 있는 모든 물건의 정보를 출력한다.
	@pre: none
	@post: none
	*/
	void DisplayAllContainerItem();

	/*
	@brief: temporary List의 상세 정보를 설정한다.
	@pre: none
	@post: TempList 관련 함수 호출을 위한 command함수 호출
	*/
	void TempSet();

	/*
	@brief: TempList의 물건을 보관할 위치를 추천, 보관 후 TempList에서 삭제
	@pre: none
	@post: TempList에서 해당 물건이 삭제되고, MasterList에 추가된다.
	*/
	int AllocateObject();

	/*
	@brief: TempList에 물건추가
	@pre: none
	@post: TempList에 물건 추가
	*/
	int TempAddObject();			//TempList 관련 설정

	/*
	@brief: 물건의 ID를 받아, TempList에서 물건 삭제
	@pre: none
	@post: TempList에서 해당하는 물건 삭제
	*/
	int TempDeleteObject();

	/*
	@brief: 물건의 ID를 받아, TempList에서 물건의 정보 교체
	@pre: none
	@post: TempList에서 해당하는 물건 정보 교체
	*/
	int TempUpdateObject();

	/*
	@brief: 물건의 ID를 받아, TempList에서 물건의 정보 찾기
	@pre: none
	@post: TempList에서 해당하는 물건을 찾아, 정보를 화면에 display
	*/
	int TempRetrieveObject();

	/*
	@brief: TempList에 있는 물건의 정보를 모두 display
	@pre: none
	@post: TempList에 있는 물건의 정보를 모두 display
	*/
	void DisplayAllTemp();
};