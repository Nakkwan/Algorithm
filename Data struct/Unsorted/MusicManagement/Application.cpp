#include "Application.h"

void Application::Run() {
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�			
			AddMusic();
			break;
		case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����				
			DeleteMusic();
			break;
		case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����		
			ReplaceMusic();
			break;
		case 4:		// �Էµ� ������ ����Ʈ���� ���� ã�Ƽ� ȭ�鿡 ���			
			RetrieveMusic();
			break;
		case 5:		// ����Ʈ�� ����� ��� ���� ȭ�鿡 ���
			DisplayAllMusic();
			break;
		case 6: 		// ����Ʈ�� �Էµ� ��� ���� ����
			MakeEmpty();
			break;
		case 7:		// load list data from a file.
			//ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			//WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	cout << "\t\t<<Music Management>>\n\n";
	cout << "\t1 : Add Music\n";
	cout << "\t2 : Delete Music\n";
	cout << "\t3 : Replace Music\n";
	cout << "\t4 : Retrieve Music\n";
	cout << "\t5 : Display All Music List\n";
	cout << "\t6 : Make Music List Empty\n";
	cout << "\t7 : Read Data from File\n";
	cout << "\t8 : Write Data to File\n";
	cout << "\t0 : Quit\n";
	cout << "\tEnter Command -> ";
	
	cin >> m_Command;

	return m_Command;
}

int Application::AddMusic() {
	if (m_List.IsFull()) {
		cout << "\tList is already full!\n";
		return 0;
	} 
	cout << "\t\t<Music Information>\n";
	ItemType data;
	data.SetRecordFromKB();
	m_List.Add(data);

	cout << "\t\t<Add Success>\n";

	return 1;
}

int Application::DeleteMusic() {
	if (m_List.IsEmpty()) {
		cout << "\tList is empty!\n";
		return 0;
	}

	cout << "\t\t<Enter the label of Music>\n";
	ItemType data;
	data.SetLabelFromKB();
	if (m_List.Delete(data)) {
		cout << "\t\t<Delete Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::ReplaceMusic() {
	cout << "\t\t<Enter the information of Music>\n";
	ItemType data;
	data.SetRecordFromKB();
	if (m_List.Replace(data)) {
		cout << "\t\t<Update Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::RetrieveMusic() {
	cout << "\t\t<Enter the label of Music>\n";
	ItemType data;
	data.SetLabelFromKB();
	if (m_List.Get(data)) {
		data.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

void Application::DisplayAllMusic() {
	ItemType data;
	cout << "\t\t<Music List>\n";
	m_List.ResetList();
	int len = m_List.GetLength();
	int cur_p = m_List.GetNextItem(data);
	while (cur_p < len && cur_p != -1) {
		cout << cur_p + 1 << ".\n";
		data.DisplayRecordOnScreen();
		cur_p = m_List.GetNextItem(data);
	}
}

void Application::MakeEmpty() {
	cout << "\t\t<Make List Empty>\n";
	m_List.MakeEmpty();
}

//int Application::OpenInFile(char* filename) {
//
//}
//
//int Application::OpenOutFile(char* filename) {
//
//}
//
//int Application::ReadDataFromFile() {
//
//}
//
//int Application::WriteDataToFile() {
//
//}