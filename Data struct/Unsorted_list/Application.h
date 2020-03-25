#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	Application()
	{
		m_Command = 0;
	}
	
	~Application()	{}

	void Run();

	int GetCommand();

	int AddItem();

	void DisplayAllItem();

	int OpenInFile(char *fileName);

	int OpenOutFile(char *fileName);

	int ReadDataFromFile();

	int WriteDataToFile();
	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H