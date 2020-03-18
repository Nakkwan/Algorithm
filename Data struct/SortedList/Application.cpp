#include "Application.h"


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:		// search item
			SearchItembyID();
			break;
		case 5:		// delete item
			DeleteItem();
			break;
		case 6:		// update item
			UpdateItem();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item" << endl;
	cout << "\t   8 : Get from file" << endl;
	cout << "\t   9 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	cout << "\t  << ID must be natural number.>>" << endl;
	item.SetRecordFromKB();
	m_List.Add(item);

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\n\t  << Current list >>" << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

// 찾고 싶은 ID의 데이터를 찾아 화면에 출력
void Application::SearchItembyID()
{
	ItemType data;
	int id;

	// 찾을 ID 입력
	cout << "\n\tEnter the ID that you want to find : ";
	cin >> id;
	data.SetId(id);

	// list에서 ID검색하고 찾은 data를 화면에 출력 없는 경우엔 없다고 표시
	if (m_List.Get(data) == 0)
		cout << "\n\t Unable to locate the ID!!" << endl;
	else {
		cout << "\n\n\t << ID's data >>" << endl;
		data.DisplayRecordOnScreen();
	}
}

// 삭제하고 싶은 ID의 데이터를 찾아서 삭제
void Application::DeleteItem()
{
	ItemType data;
	int id;

	// 삭제할 데이터의 ID 입력
	cout << "\n\tEnter the ID that you want to delete : ";
	cin >> id;
	data.SetId(id);
	if (m_List.Get(data) == 0) {
		cout << "\n\t Unable to locate ID!!" << endl;
		return;
	}

	// list에서 ID검색 후 그 ID의 data 삭제
	m_List.Delete(data);
}

// 바꾸고 싶은 ID의 데이터를 업데이트
void Application::UpdateItem()
{
	ItemType data;
	int id;

	// 업데이트할 데이터의 ID 입력
	cout << "\n\tEnter the ID that you want to update : ";
	cin >> id;
	data.SetId(id);
	if (m_List.Get(data) == 0) {
		cout << "\n\t Unable to locate ID!!" << endl;
		return;
	}

	// 그 ID의 나머지 데이터 입력
	cout << "\t Enter new data.\n\n";
	data.SetNameFromKB();
	data.SetAddressFromKB();

	// 데이터 업데이트
	m_List.Replace(data);
}