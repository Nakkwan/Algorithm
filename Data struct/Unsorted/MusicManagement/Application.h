#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"
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
	@brief: add music in list
	@pre: set music
	@post: music is added to list
	*/
	int AddMusic();

	/*
	@brief: delete music in list 
	@pre: set unique label about delete
	@post: music is deleted in list correspond with unique label
	*/
	int DeleteMusic();

	/*
	@brief: replace music in list
	@pre: set music for replace
	@post: music corresponding with set unique label is replaced 
	*/
	int ReplaceMusic();

	/*
	@brief: search music
	@pre: set unique label for search
	@post: display searching music on screen
	*/
	int RetrieveMusic();

	/*
	@brief: display all music in list
	@pre: set list
	@post: display music list in screen 
	*/
	void DisplayAllMusic();

	/*
	@brief: make list empty
	@pre: none
	@post: music list empty
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
	@post: music is added to list and display all music on screen
	@return: return 1 if success to add, otherwise 0
	*/
	int ReadDataFromFile();

	/*
	@brief: write data in music list to file
	@pre: set music list
	@post: data of music list are write to file
	@return: return 1 if success to write, otherwise 0
	*/
	int WriteDataToFile();

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	ArrayList m_List;
	int m_Command;
};


#endif // !APPLICATION_H
