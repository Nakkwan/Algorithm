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

	int RetrieveStudent();

	int DeleteStudent();

	int Replace();
	
private:
	ifstream m_InFile;	
	ofstream m_OutFile;		
	ArrayList m_List;	
	int m_Command;			
};

#endif	// _APPLICATION_H