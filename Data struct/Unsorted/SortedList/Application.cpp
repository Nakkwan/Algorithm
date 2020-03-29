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
		case 5:		// search item
			SearchItembyName();
			break;
		case 6:		// delete item
			DeleteItem();
			break;
		case 7:		// update item
			UpdateItem();
			break;
		case 8:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 9:		// save list data into a file.
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
	cin >> m_Command;
	cout << endl;

	return m_Command;
}


// Add new record into list.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	cout << "\t  << ID must be natural number.>>" << endl;
	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\n\t  << Current list >>" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length /*&& curIndex != -1*/)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
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

// ã�� ���� ID�� �����͸� ã�� ȭ�鿡 ���
void Application::SearchItembyID()
{
	ItemType data;
	int id;

	// ã�� ID �Է�
	cout << "\n\tEnter the ID that you want to find\n";
	data.SetIdFromKB();

	// list���� ID�˻��ϰ� ã�� data�� ȭ�鿡 ��� ���� ��쿣 ���ٰ� ǥ��
	if (m_List.Get(data) == 0)
		cout << "\n\t Unable to locate the ID!!" << endl;
	else {
		cout << "\n\n\t << ID's data >>" << endl;
		data.DisplayRecordOnScreen();
	}
}

// ã�� ���� Name�� �����͸� ã�� ȭ�鿡 ���
void Application::SearchItembyName()
{
	cout << "\n\tEnter the name that you want to find\n";
	ItemType dest = RetreiveRecordByMemberName();
	SearchListByMemberName(dest);
}

ItemType Application::RetreiveRecordByMemberName() {
	ItemType indata;
	indata.SetNameFromKB();
	return indata;
}

void Application::SearchListByMemberName(ItemType& inData) {
	ItemType temp;
	m_List.ResetList();
	int pointer = m_List.GetNextItem(temp);
	while (pointer < m_List.GetLength()) {
		if (temp.GetName().find(inData.GetName()) != std::string::npos) {
			temp.DisplayRecordOnScreen();
		}
		pointer = m_List.GetNextItem(temp);
	}
}

// �����ϰ� ���� ID�� �����͸� ã�Ƽ� ����
void Application::DeleteItem()
{
	ItemType data;
	int id;

	// ������ �������� ID �Է�
	cout << "\n\tEnter the ID that you want to delete : ";
	cin >> id;
	data.SetId(id);
	if (m_List.Get(data) == 0) {
		cout << "\n\t Unable to locate ID!!" << endl;
		return;
	}

	// list���� ID�˻� �� �� ID�� data ����
	m_List.Delete(data);
}

// �ٲٰ� ���� ID�� �����͸� ������Ʈ
void Application::UpdateItem()
{
	ItemType data;
	int id;

	// ������Ʈ�� �������� ID �Է�
	cout << "\n\tEnter the ID that you want to update : ";
	cin >> id;
	data.SetId(id);
	if (m_List.Get(data) == 0) {
		cout << "\n\t Unable to locate ID!!" << endl;
		return;
	}

	// �� ID�� ������ ������ �Է�
	cout << "\t Enter new data.\n\n";
	data.SetNameFromKB();
	data.SetAddressFromKB();

	// ������ ������Ʈ
	m_List.Replace(data);
}