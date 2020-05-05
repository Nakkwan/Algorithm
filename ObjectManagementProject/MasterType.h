#pragma once
#include "pch.h"

class MasterType : public Base {
private:
	DoublySortedLinkedList<ItemType> M_List;
	int M_length;
	ifstream a_inFile;
	ofstream a_outFile;
public:
	MasterType();
	~MasterType(){}

	int AddObject(ItemType& data);
	int DeleteObject(ItemType& data);
	int UpdateObject(const ItemType& data);
	int ReplaceObject(const ItemType& data);
	int GetObject(ItemType& data);
	int GetObjectByName(ItemType& data);
	int GetObjectByUsage(ItemType& data);
	int GetObjectByBuydate(int start, int finish);

	int DisplayAllObject();

	int OpenInFile(char* filename);

	int OpenOutFile(char* filename);

	int ReadDataFromFile();

	int WriteDataToFile();
};