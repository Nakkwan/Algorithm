#pragma once
#include "Base.h"
#include <fstream>
using namespace std;

class Application : public Base {
private:
	ifstream a_inFile;
	ofstream a_outFile;
	int a_Command;
public:
	Application();						//������
	~Application() {}					//�Ҹ���


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
	void RunMaster();

	/*
	@brief: RoomList program driver
	@pre: program start
	@post: none
	*/
	void RunRoom();

	/*
	@brief: TempList program driver
	@pre: program start
	@post: none
	*/
	void RunTemp();

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
	@brief: Display command on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetMasterCommand();

	/*
	@brief: Display command on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetContainerCommand();

	/*
	@brief: Display command on screen and get a input from keyboard.
	@pre: none
	@post: none
	@return: command
	*/
	int GetTempCommand();


	/*
	@brief: MasterList�� ���� �߰�
	@pre: List�� �� ������ �ʾƾ� �Ѵ�.
	@post: MasterList�� ������ �߰��ϰ� �ش��ϴ� container�� ������
	*/
	int MasterAddObject();				//MasterList ����

	/*
	@brief: MasterList���� ���� ����
	@pre: ������ ������ ID�� List�� �־�� �Ѵ�.
	@post: MasterList�� ������ �����ϰ� �ش��ϴ� container�� ������
	*/
	int MasterDeleteObject();

	/*
	@brief: MasterList�� ���� ��ü
	@pre: none
	@post: MasterList�� ������ ��ü�ϰ� �ش��ϴ� container�� ������
	*/
	int MasterReplaceObject();

	/*
	@brief: MasterList���� ID�� ���� ã��
	@pre: none
	@post: MasterList���� �ش��ϴ� ������ ������ ȭ�鿡 display
	*/
	int MasterRetrieveObject();


	/*
	@brief: MasterList���� �̸����� ���� ã��
	@pre: none
	@post: MasterList���� �ش��ϴ� ������ ������ ȭ�鿡 display
	*/
	int MasterRetrieveObjectByName();


	/*
	@brief: MasterList���� �뵵�� ���� ã��
	@pre: none
	@post: MasterList���� �ش��ϴ� ������ ������ ȭ�鿡 display
	*/
	int MasterRetrieveObjectByUsage();

	/*
	@brief: MasterList ����
	@pre: none
	@post: MasterList�� �����
	*/
	void MasterMakeListEmpty();

	/*
	@brief: ������ ���ǵ��� ���� display
	@pre: none
	@post: MasterList�� �ִ� ���ǵ��� ������ ��� display��
	*/
	void DisplayAllObject();


	/*
	@brief:	Open a file by file descriptor as an input file.
	@pre: a file for reading is exist.
	@post: open the file for reading.
	@param:	filename to open for reading.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* filename);

	/*
	@brief:	Open a file by file descriptor as an output file.
	@pre: list should be initialized.
	@post: open the file for writing.
	@param: filename to open for writing.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* filename);

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
	@brief: Delete Room
	@pre: Size of RoomList is bigger than 1
	@post: Delete Room from List
	*/
	void RoomDelete();

	/*
	@brief: update Room info
	@pre: set Room
	@post: update information of the Room
	*/
	void RoomReplace();

	/*
	@brief: �ش� ���� ã�´�
	@pre: Size of RoomList is bigger than 1
	@post: Display information of Room
	*/
	void RoomSearch();

	/*
	@brief: Display information of Room
	@pre: none
	@post: Display information of Room
	*/
	void RoomInfo();

	/*
	@brief: ���� ������ �����Ѵ�.
	@pre: set Room
	@post: �ش� �濡 ���� ������ �����Ѵ�. 
	*/
	void RoomSet();

	/*
	@brief: �濡 �ִ� ��� ������ ������ ����Ѵ�.
	@pre: none
	@post: �濡 �ִ� ��� ������ ������ ����Ѵ�.
	*/
	void DisplayAllRoomItem();

	/*
	@brief: ������ �߰�
	@pre: none
	@post: RoomClass�� ������ List�� �������� �߰��ȴ�. 
	*/
	void DrawerAdd();

	/*
	@brief: �ش� �������� �����Ѵ�.
	@pre: ������ �������� �����ؾ���
	@post: List���� �������� �����ȴ�.
	*/
	void DrawerDelete();

	/*
	@brief: �������� ������ �����Ѵ�.
	@pre: ������ ������ �������� �����ؾ���
	@post: �ش� �������� ������ ���ŵȴ�.
	*/
	void DrawerReplace();

	/*
	@brief: ������ �˻�
	@pre: �˻��� �������� �����ؾ���
	@post: �ش� �����忡 ���� ������ ��µ�
	*/
	void DrawerSearch();

	/*
	@brief: �������� �� ������ �����Ѵ�. 
	@pre: none
	@post: Container ���� �Լ� ȣ���� ���� command�Լ� ȣ��
	*/
	void DrawerSet();

	/*
	@brief: �����忡 �ִ� ��� ������ ������ ����Ѵ�.
	@pre: none
	@post: none
	*/
	void DisplayAllDrawerItem();

	/*
	@brief: �������� ������ �߰��Ѵ�.
	@pre: set drawer
	@post: add container
	*/
	void ContainerAdd();

	/*
	@brief: �ش� ������ �����Ѵ�.
	@pre: ������ ������ �����ؾ���
	@post: List���� ������ �����ȴ�.
	*/
	void ContainerDelete();

	/*
	@brief: ������ ������ �����Ѵ�.
	@pre: ������ ������ ������ �����ؾ���
	@post: �ش� ������ ������ ���ŵȴ�.
	*/
	void ContainerReplace();

	/*
	@brief: ���� �˻�
	@pre: �˻��� ������ �����ؾ���
	@post: �ش� ������ ���� ������ ��µ�
	*/
	void ContainerSearch();

	/*
	@brief: ������ �� ������ �����Ѵ�.
	@pre: none
	@post: Item�� photo ���� �Լ� ȣ���� ���� command�Լ� ȣ��
	*/
	void ContainerSet();

	/*
	@brief: ������ �ִ� ��� ������ ������ ����Ѵ�.
	@pre: none
	@post: none
	*/
	void DisplayAllContainerItem();

	/*
	@brief: ������ ������ ��θ� ����Ѵ�.
	@pre: none
	@post: none
	*/
	void DisplayAllContainerPhoto();

	/*
	@brief: ������ ������ ������ �߰��Ѵ�.
	@pre: set container
	@post: add Item at ItemList
	*/
	void ContainerAddItem();

	/*
	@brief: ������ �����Ǿ� �ִ� ������ �����Ѵ�.
	@pre: �ش� ������ �����ؾ� �Ѵ�.
	@post: delete item from ItemList
	*/
	void ContainerDeleteItem();

	/*
	@brief: ������ �����Ǿ� �ִ� ������ ������ �����Ѵ�.
	@pre: �ش� ������ �����ؾ� �Ѵ�.
	@post: update item of ItemList
	*/
	void ContainerReplaceItem();

	/*
	@brief: �����忡�� ������ ID�� �˻��Ѵ�.
	@pre: ������ �ش� ������ �����ؾ� �Ѵ�.
	@post: �ش� ������ ������ ȭ�鿡 ����Ѵ�. 
	*/
	void ContainerRetrieveItem();

	/*
	@brief: ������ ������ ��� ��θ� �߰��Ѵ�.
	@pre: none
	@post: PhotoList�� ������ ��ΰ� �߰��ȴ�.
	*/
	void ContainerAddPhoto();

	/*
	@brief: ���� ������ ��θ� �����Ѵ�.
	@pre: none
	@post: PhotoList�� �ִ� �ش� ���� ��ΰ� �����ȴ�.
	*/
	void ContainerDeletePhoto();

	/*
	@brief: TempList�� ������ ������ ��ġ�� ��õ, ���� �� TempList���� ����
	@pre: none
	@post: TempList���� �ش� ������ �����ǰ�, MasterList�� �߰��ȴ�.
	*/
	int AllocateObject();

	/*
	@brief: TempList�� �����߰�
	@pre: none
	@post: TempList�� ���� �߰�
	*/
	int TempAddObject();			//TempList ���� ����

	/*
	@brief: ������ ID�� �޾�, TempList���� ���� ����
	@pre: none
	@post: TempList���� �ش��ϴ� ���� ����
	*/
	int TempDeleteObject();

	/*
	@brief: ������ ID�� �޾�, TempList���� ������ ���� ��ü
	@pre: none
	@post: TempList���� �ش��ϴ� ���� ���� ��ü
	*/
	int TempReplaceObject();

	/*
	@brief: ������ ID�� �޾�, TempList���� ������ ���� ã��
	@pre: none
	@post: TempList���� �ش��ϴ� ������ ã��, ������ ȭ�鿡 display
	*/
	int TempRetrieveObject();

	/*
	@brief: TempList�� �ִ� ������ ������ ��� display
	@pre: none
	@post: TempList�� �ִ� ������ ������ ��� display
	*/
	void DisplayAllTemp();
};