#include "pch.h"
#include "Application.h"

int Application::GetCommand() {
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "############ 인력 시장 ############\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### Select ######\n";
	cout << "\t1 : 등록순 출력\n";
	cout << "\t2 : 이름으로 검색\n";
	cout << "\t3 : 숙련도로 검색\n";
	cout << "\t4 : 전문분야로 검색\n";
	cout << "\t5 : 이름으로 선별\n";
	cout << "\t6 : 등록순 선별\n";
	cout << "\t7 : 점수순 선별\n";
	cout << "\t8 : 파일로부터 읽기\n";
	cout << "\t9 : 파일에 쓰기\n";
	cout << "\t10 : 구직자 추가\n";
	cout << "\t0 : Quit\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}

void Application::Run() {
	while (1) {
		a_Command = GetCommand();
		switch (a_Command)
		{
		case 1:
			DisplayEmployeeByRank();				//등록순 출력		
			break;
		case 2:
			SearchByName();							//이름으로 검색
			break;
		case 3:
			SearchBySkill();						//숙련도로 검색
			break;
		case 4:
			SearchByPrefer();						//전문 분야로 검색
			break;
		case 5:
			PickByName();							//이름으로 선별
			break;
		case 6:
			PickEmployee();							//등록순 선별
			break;
		case 7:
			PickByScore();							//점수순 선별
			break;
		case 8:
			ReadDataFromFile();						//파일로부터 데이터 읽기
			break;
		case 9:
			WriteDataToFile();						//파일로 데이터 쓰기
			break;
		case 10:
			AddEmployee();							//구직자 추가
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::AddEmployee() {
	Employee data;
	cout << "######## 구인자 추가 ########\n";
	data.SetRecordFromKB();
	Emp_List.Add(data);
}

void Application::DisplayEmployeeByRank() {
	cout << "######## 구인자 목록 ########\n";
	Emp_List.Display();
}

void Application::SearchByName() {
	cout << "####### 이름으로 검색 #######\n";
	Employee data;
	data.SetNameFromKB();
	Emp_List.SearchByName(data);
}

void Application::SearchBySkill() {
	cout << "####### 숙련도로 검색 #######\n";
	Employee data;
	data.SetSkillFromKB();
	Emp_List.SearchBySkill(data);
}

void Application::SearchByPrefer() {
	cout << "###### 전문분야로 검색 ######\n";
	Employee data;
	data.SetPreferFromKB();
	Emp_List.SearchByPrefer(data);
}

void Application::PickByName() {
	cout << "####### 이름으로 선별 #######\n";
	Employee data;
	data.SetNameFromKB();
	if (Emp_List.PickByName(data)) {
		Emp_List.RearrangeRank();
	}
	else {
		cout << "해당하는 구직자가 없습니다.\n";
	}
}

void Application::PickEmployee() {
	cout << "######## 등록순 선별 ########\n";
	int num, from, to;
	string yn;
	bool prefer;
	cout << "희망 인원: ";
	cin >> num;
	Employee data;
	data.SetSkillFromKB();
	cout << "나이\n";
	cout << "최소: ";
	cin >> from;
	cout << "최대: ";
	cin >> to;
	data.SetMoneyFromKB();
	cout << "필수 전문 분야[Y:필요함/N:상관없음]: ";
	cin >> yn;
	while (1) {
		if (yn == "y" || yn == "Y") {
			data.SetPreferFromKB();
			prefer = true;
			break;
		}
		else if (yn == "n" || yn == "N") {
			prefer = false;
			break;
		}
		else {
			cout << "잘못된 입력\n";
		}
	}
	int result;
	result = Emp_List.PickEmployee(data, num, from, to, prefer);
	cout << "\n뽑은 인원: " << result << endl;
	Emp_List.RearrangeRank();				//등록 순위 재조정
}

void Application::PickByScore() {
	cout << "######## 점수로 선별 ########\n";
	int num, result;
	string yn;
	bool prefer;
	cout << "희망 인원: ";
	cin >> num;
	Employee data;
	data.SetSkillFromKB();
	data.SetAgeFromKB();
	data.SetMoneyFromKB();
	cout << "필수 전문 분야[Y:필요함/N:상관없음]: ";
	cin >> yn;
	while (1) {
		if (yn == "y" || yn == "Y") {
			data.SetPreferFromKB();
			prefer = true;
			break;
		}
		else if (yn == "n" || yn == "N") {
			prefer = false;
			break;
		}
		else {
			cout << "잘못된 입력\n";
		}
	}
	Emp_List.SetScore(data, prefer);					//구직자들의 점수 설정
	result = Emp_List.PickByScore(num);			//인원에 맞는 구직자 차출
	cout << "\n뽑은 인원: " << result << endl;
	E_Score.MakeEmpty();						//리스트 비우기
	Emp_List.RearrangeRank();					//등록 순위 재조정
}

int Application::ReadDataFromFile() {
	cout << "######### 파일로부터 읽기 #########\n";
	if (Emp_List.ReadDataFromFile()) {
		Emp_List.Display();
		return 1;
	}
	cout << "\t<Read Failed>\n";
	return 0;
}

int Application::WriteDataToFile() {
	cout << "########### 파일에 쓰기 ###########\n";
	if (Emp_List.WriteDataToFile()) {
		cout << "\t<Write Success>\n";
		return 1;
	}
	cout << "\t<Write Failed>\n";
	return 0;
}