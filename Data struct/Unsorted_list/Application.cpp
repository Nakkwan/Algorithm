#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		
			AddItem();
			break;
		case 2:	
			DisplayAllItem();
			break;
		case 3:		
			m_List.MakeEmpty();
			break;
		case 4:		
			ReadDataFromFile();
			break;
		case 5:	
			WriteDataToFile();
			break;
		case 6:
			RetrieveStudent();
			break;
		case 7:
			DeleteStudent();
			break;
		case 8:
			Replace();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Get from file" << endl; 
	cout << "\t   5 : Put to file " << endl; 
	cout << "\t   6 : Retrieve data by ID " << endl; 
	cout << "\t   7 : Delete data by ID " << endl; 
	cout << "\t   8 : Replace data by ID" << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


int Application::AddItem()
{
	if(m_List.IsFull())
	{
		cout << "List is full!" << endl;
		return 0;
	}

	ItemType item;

	cout << "\t  << Enter the information >>" << endl;
	item.SetRecordFromKB();
	m_List.Add(item);

	DisplayAllItem();

	return 1;
}

void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\n\t  << Current list >>" << endl;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}

int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	
	
	if(!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	

	if(!m_OutFile)	return 0;
	else	return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if(!OpenInFile(filename))
		return 0;

	while(!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	

	DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile()
{
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if(!OpenOutFile(filename))
		return 0;

	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();

	return 1;
}

int Application::RetrieveStudent() {
	ItemType getItem;
	cout << "\t  << Enter ID of student >>" << endl;
	getItem.SetIdFromKB();
	if (m_List.Get(getItem)) {
		cout << "\t\t<Information about " << getItem.GetId() << ">\n";
		getItem.DisplayRecordOnScreen();
		return 1;
	}
	cout << "\t\t<No such information found>\n";
	return 0;
}

int Application::DeleteStudent() {
	ItemType getItem;
	cout << "\t  << Enter ID of student >>" << endl;
	getItem.SetIdFromKB();
	if (m_List.Delete(getItem)) {
		cout << "\t\t<Delete Success>\n";
		return 1;
	}
	cout << "\t\t<No such information found>\n";
	return 0;
}

int Application::Replace() {
	ItemType getItem;
	cout << "\t  << Enter ID of student >>" << endl;
	getItem.SetRecordFromKB();
	if (m_List.Replace(getItem)) {
		cout << "\t\t<Replace Success>\n";
		return 1;
	}
	cout << "\t\t<No such information found>\n";
	return 0;
}