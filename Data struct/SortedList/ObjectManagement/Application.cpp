#include "Application.h"

void Application::Run() {
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 물건의 정보를 입력 받아 리스트에 추가			
			AddObject();
			break;
		case 2:		// 물건의 고유번호를 입력 받아 리스트에서 삭제				
			DeleteObject();
			break;
		case 3:		// 물건 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신		
			ReplaceObject();
			break;
		case 4:		// 라벨로 리스트에서 물건을 찾아서 화면에 출력			
			RetrieveObject();
			break;
		case 5:		// 물건의 이름으로 리스트에서 물건을 찾아서 화면에 출력			
			RetrieveObjectByName();
			break;
		case 6:		// 물건의 종류로 리스트에서 곡을 찾아서 화면에 출력			
			RetrieveObjectByType();
			break;
		case 7:		// 리스트에 저장된 모든 물건을 화면에 출력
			DisplayAllObject();
			break;
		case 8: 		// 리스트에 입력된 모든 물건을 삭제
			MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
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

int Application::GetCommand() {
	cout << "\t\t<<Object Management>>\n\n";
	cout << "\t1 : Add Object\n";
	cout << "\t2 : Delete Object\n";
	cout << "\t3 : Replace Object\n";
	cout << "\t4 : Retrieve Object\n";
	cout << "\t5 : Retrieve Object by Name\n";
	cout << "\t6 : Retrieve Object by Type\n";
	cout << "\t7 : Display All Object List\n";
	cout << "\t8 : Make Object List Empty\n";
	cout << "\t9 : Read Data from File\n";
	cout << "\t10 : Write Data to File\n";
	cout << "\t0 : Quit\n";
	cout << "\tEnter Command -> ";

	cin >> m_Command;

	return m_Command;
}

int Application::AddObject() {
	if (m_List.IsFull()) {			//배열이 꽉 차있는지 확인
		cout << "\tList is already full!\n";
		return 0;
	}
	cout << "\t\t<Object Information>\n";
	ItemType data;
	data.SetRecordFromKB();
	if (m_List.Add(data)) {			//데이터 추가
		cout << "\t\t<Add Success>\n";
	}
	return 1;
}

int Application::DeleteObject() {
	if (m_List.IsEmpty()) {			//배열에 item이 있는지 확인
		cout << "\tList is empty!\n";
		return 0;
	}

	cout << "\t\t<Enter the label of Object>\n";
	ItemType data;
	data.SetLabelFromKB();
	if (m_List.Delete(data)) {		//데이터 삭제, 성공여부 확인
		cout << "\t\t<Delete Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::ReplaceObject() {
	cout << "\t\t<Enter the information of Object>\n";
	ItemType data;
	data.SetRecordFromKB();
	if (m_List.Replace(data)) {			//데이터 교체, 성공여부 확인
		cout << "\t\t<Update Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::RetrieveObject() {
	cout << "\t\t<Enter the label of Object>\n";
	ItemType data;
	data.SetLabelFromKB();
	if (m_List.Get(data)) {				//데이터가 있다면 출력
		data.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::RetrieveObjectByType() {
	cout << "\t\t<Enter the Type of Object>\n";
	int count = 0;
	ItemType data;
	ItemType element;
	data.SetTypeFromKB();
	m_List.ResetList();
	int pointer = m_List.GetNextItem(element);
	int len = m_List.GetLength();

	while (pointer < len && pointer != -1) {
		if (element.GetType() == data.GetType()) {
			count++;
			cout << count << ".\n";
			element.DisplayRecordOnScreen();
		}
		pointer = m_List.GetNextItem(element);
	}
	if (count != 0) {
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

int Application::RetrieveObjectByName() {
	cout << "\t\t<Enter the Name of Object>\n";
	int count = 0;
	ItemType data;
	ItemType element;
	data.SetNameFromKB();
	m_List.ResetList();
	int pointer = m_List.GetNextItem(element);
	int len = m_List.GetLength();

	while (pointer < len && pointer != -1) {
		if (element.GetName().find(data.GetName()) != string::npos) {			//검색할 내용을 포함했다면
			count++;
			cout << count << ".\n";
			element.DisplayRecordOnScreen();					//출력
		}
		pointer = m_List.GetNextItem(element);
	}
	if (count != 0) {
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

void Application::DisplayAllObject() {
	ItemType data;
	cout << "\t\t<Object List>\n";
	m_List.ResetList();
	int len = m_List.GetLength();
	int cur_p = m_List.GetNextItem(data);
	while (cur_p < len && cur_p != -1) {		//처음부터 끝까지 데이터 출력
		cout << cur_p + 1 << ".\n";
		data.DisplayRecordOnScreen();
		cur_p = m_List.GetNextItem(data);
	}
}

void Application::MakeEmpty() {
	cout << "\t\t<Make List Empty>\n";
	m_List.MakeEmpty();
}

int Application::OpenInFile(char* filename) {		//읽을 파일이 열리는지 확인
	m_InFile.open(filename);

	if (m_InFile.is_open())
		return 1;
	else
		return 0;
}

int Application::OpenOutFile(char* filename) {		//쓸 파일이 열리는지 확인
	m_OutFile.open(filename);

	if (m_OutFile.is_open())
		return 1;
	else
		return 0;
}

int Application::ReadDataFromFile() {
	char filename[FILENAMESIZE];
	ItemType data;
	cout << "\t\t<Read data from file>\n";
	cout << "\tEnter the filename for reading data: ";
	cin >> filename;

	if (OpenInFile(filename)) {
		while (!m_InFile.eof()) {				//파일이 끝나기 전까지 데이터 읽기
			data.ReadDataFromFile(m_InFile);
			m_List.Add(data);
		}
	}
	else {
		cout << "\tError: Uncorrect file name\n";
		return 0;
	}

	DisplayAllObject();

	m_InFile.close();

	return 1;
}

int Application::WriteDataToFile() {
	char filename[FILENAMESIZE];
	ItemType data;
	cout << "\t\t<Write data ro file>\n";
	cout << "\tEnter the filename for writing data: ";
	cin >> filename;

	if (OpenOutFile(filename)) {
		m_List.ResetList();
		int curPointer = m_List.GetNextItem(data);					// 리스트의 포인터와 해당 데이터 받기
		int List_len = m_List.GetLength();							//리스트 길이
		while (curPointer != -1 && curPointer < List_len) {			//파일이 끝나기 전까지 데이터 쓰기
			data.WriteDataToFile(m_OutFile);
			curPointer = m_List.GetNextItem(data);
		}
	}
	else {
		cout << "\tError: Uncorrect file name\n";
		return 0;
	}

	m_OutFile.close();

	return 1;
}