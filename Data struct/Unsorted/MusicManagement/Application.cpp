#include "Application.h"

void Application::Run() {
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가			
			AddMusic();
			break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제				
			DeleteMusic();
			break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신		
			ReplaceMusic();
			break;
		case 4:		// 입력된 정보로 리스트에서 곡을 찾아서 화면에 출력			
			RetrieveMusic();
			break;
		case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			break;
		case 6: 		// 리스트에 입력된 모든 곡을 삭제
			MakeEmpty();
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
	if (m_List.IsFull()) {			//배열이 꽉 차있는지 확인
		cout << "\tList is already full!\n";
		return 0;
	} 
	cout << "\t\t<Music Information>\n";
	ItemType data;
	data.SetRecordFromKB();
	if (m_List.Add(data)) {			//데이터 추가
		cout << "\t\t<Add Success>\n";
	}
	return 1;
}

int Application::DeleteMusic() {
	if (m_List.IsEmpty()) {			//배열에 item이 있는지 확인
		cout << "\tList is empty!\n";
		return 0;
	}

	cout << "\t\t<Enter the label of Music>\n";
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

int Application::ReplaceMusic() {
	cout << "\t\t<Enter the information of Music>\n";
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

int Application::RetrieveMusic() {
	cout << "\t\t<Enter the label of Music>\n";
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

void Application::DisplayAllMusic() {
	ItemType data;
	cout << "\t\t<Music List>\n";
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

	DisplayAllMusic();

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