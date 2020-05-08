#include "pch.h"
#include "Application.h"

int Application::GetCommand() {
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "############ �η� ���� ############\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### Select ######\n";
	cout << "\t1 : ��ϼ� ���\n";
	cout << "\t2 : �̸����� �˻�\n";
	cout << "\t3 : ���õ��� �˻�\n";
	cout << "\t4 : �����о߷� �˻�\n";
	cout << "\t5 : �̸����� ����\n";
	cout << "\t6 : ��ϼ� ����\n";
	cout << "\t7 : ������ ����\n";
	cout << "\t8 : ���Ϸκ��� �б�\n";
	cout << "\t9 : ���Ͽ� ����\n";
	cout << "\t10 : ������ �߰�\n";
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
			DisplayEmployeeByRank();				//��ϼ� ���		
			break;
		case 2:
			SearchByName();							//�̸����� �˻�
			break;
		case 3:
			SearchBySkill();						//���õ��� �˻�
			break;
		case 4:
			SearchByPrefer();						//���� �о߷� �˻�
			break;
		case 5:
			PickByName();							//�̸����� ����
			break;
		case 6:
			PickEmployee();							//��ϼ� ����
			break;
		case 7:
			PickByScore();							//������ ����
			break;
		case 8:
			ReadDataFromFile();						//���Ϸκ��� ������ �б�
			break;
		case 9:
			WriteDataToFile();						//���Ϸ� ������ ����
			break;
		case 10:
			AddEmployee();							//������ �߰�
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
	cout << "######## ������ �߰� ########\n";
	data.SetRecordFromKB();
	Emp_List.Add(data);
}

void Application::DisplayEmployeeByRank() {
	cout << "######## ������ ��� ########\n";
	Emp_List.Display();
}

void Application::SearchByName() {
	cout << "####### �̸����� �˻� #######\n";
	Employee data;
	data.SetNameFromKB();
	Emp_List.SearchByName(data);
}

void Application::SearchBySkill() {
	cout << "####### ���õ��� �˻� #######\n";
	Employee data;
	data.SetSkillFromKB();
	Emp_List.SearchBySkill(data);
}

void Application::SearchByPrefer() {
	cout << "###### �����о߷� �˻� ######\n";
	Employee data;
	data.SetPreferFromKB();
	Emp_List.SearchByPrefer(data);
}

void Application::PickByName() {
	cout << "####### �̸����� ���� #######\n";
	Employee data;
	data.SetNameFromKB();
	if (Emp_List.PickByName(data)) {
		Emp_List.RearrangeRank();
	}
	else {
		cout << "�ش��ϴ� �����ڰ� �����ϴ�.\n";
	}
}

void Application::PickEmployee() {
	cout << "######## ��ϼ� ���� ########\n";
	int num, from, to;
	string yn;
	bool prefer;
	cout << "��� �ο�: ";
	cin >> num;
	Employee data;
	data.SetSkillFromKB();
	cout << "����\n";
	cout << "�ּ�: ";
	cin >> from;
	cout << "�ִ�: ";
	cin >> to;
	data.SetMoneyFromKB();
	cout << "�ʼ� ���� �о�[Y:�ʿ���/N:�������]: ";
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
			cout << "�߸��� �Է�\n";
		}
	}
	int result;
	result = Emp_List.PickEmployee(data, num, from, to, prefer);
	cout << "\n���� �ο�: " << result << endl;
	Emp_List.RearrangeRank();				//��� ���� ������
}

void Application::PickByScore() {
	cout << "######## ������ ���� ########\n";
	int num, result;
	string yn;
	bool prefer;
	cout << "��� �ο�: ";
	cin >> num;
	Employee data;
	data.SetSkillFromKB();
	data.SetAgeFromKB();
	data.SetMoneyFromKB();
	cout << "�ʼ� ���� �о�[Y:�ʿ���/N:�������]: ";
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
			cout << "�߸��� �Է�\n";
		}
	}
	Emp_List.SetScore(data, prefer);					//�����ڵ��� ���� ����
	result = Emp_List.PickByScore(num);			//�ο��� �´� ������ ����
	cout << "\n���� �ο�: " << result << endl;
	E_Score.MakeEmpty();						//����Ʈ ����
	Emp_List.RearrangeRank();					//��� ���� ������
}

int Application::ReadDataFromFile() {
	cout << "######### ���Ϸκ��� �б� #########\n";
	if (Emp_List.ReadDataFromFile()) {
		Emp_List.Display();
		return 1;
	}
	cout << "\t<Read Failed>\n";
	return 0;
}

int Application::WriteDataToFile() {
	cout << "########### ���Ͽ� ���� ###########\n";
	if (Emp_List.WriteDataToFile()) {
		cout << "\t<Write Success>\n";
		return 1;
	}
	cout << "\t<Write Failed>\n";
	return 0;
}