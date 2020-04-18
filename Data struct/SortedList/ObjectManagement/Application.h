#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "SortedList.h"
using namespace std;

#define FILENAMESIZE 1024


/**
*	application class for item management simply.
*/
class Application
{
public:
	Application()			//constructor
	{
		m_Command = 0;
	}

	~Application() {}		//destructor

	/*
	@brief: Run application
	@pre: set program
	@post: run program
	*/
	void Run();

	/*
	@brief: get command from keyboard
	@pre: none
	@post: get command
	*/
	int GetCommand();

	/*
	@brief: add object in list
	@pre: set object
	@post: object is added to list
	*/
	int AddObject();

	/*
	@brief: delete object in list
	@pre: set object about delete
	@post: object is deleted in list correspond with set object
	*/
	int DeleteObject();

	/*
	@brief: replace object in list
	@pre: set object for replace
	@post: object corresponding with set object is replaced
	*/
	int ReplaceObject();

	/*
	@brief: search object by unique label
	@pre: set unique label for search
	@post: display searching object on screen
	*/
	int RetrieveObject();

	/*
	@brief: Search for object of the applicable type
	@pre: set type for searching
	@post: display searching object on screen
	*/
	int RetrieveObjectByType();

	/*
	@brief: Search objects by allowing duplicate names
	@pre: set name for searching
	@post: display searching object on screen
	*/
	int RetrieveObjectByName();

	/*
	@brief: display all object in list
	@pre: set list
	@post: display object list in screen
	*/
	void DisplayAllObject();

	/*
	@brief: make list empty
	@pre: none
	@post: object list empty
	*/
	void MakeEmpty();

	/*
	@brief: confirm if file is opened
	@pre: set filename
	@post: file open for read
	@return: return 1 if file open, otherwise 0
	*/
	int OpenInFile(char* fileName);

	/*
	@brief: confirm if file is opened
	@pre: set filename
	@post: file open for write
	@return: return 1 if file open, otherwise 0
	*/
	int OpenOutFile(char* fileName);

	/*
	@brief: read data from file and add to list
	@pre: set file for reading
	@post: object is added to list and display all object on screen
	@return: return 1 if success to add, otherwise 0
	*/
	int ReadDataFromFile();

	/*
	@brief: write data in object list to file
	@pre: set object list
	@post: data of object list are write to file
	@return: return 1 if success to write, otherwise 0
	*/
	int WriteDataToFile();

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList m_List;
	int m_Command;
};


#endif // !APPLICATION_H
