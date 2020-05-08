#include "pch.h"
#include "Employee.h"

int EmpList::Add(Employee& data) {
	data.SetRank(E_List.GetLength());			//��� ������ �Ҵ�
	if (E_List.Add(data)) {						//����Ʈ�� �߰�
		E_length++;
		return 1;
	}
	return 0;
}

int EmpList::Delete(Employee& data) {			//����
	if (E_List.Delete(data)) {
		E_length--;
		return 1;
	}
	return 0;
}

void EmpList::Display() {						//����Ʈ�� ���
	UnsortedIterator<Employee> itor(E_List);
	Employee temp = itor.Next();
	int count = 1;
	while (itor.NextNotNull()) {
		cout << count << ".\n";
		temp.DisplayOnScreen();
		cout << "\n";
		temp = itor.Next();
		count++;
	}
}

void EmpList::RearrangeRank() {					//��� ������ ������
	UnsortedIterator<Employee> itor(E_List);
	Employee temp = itor.Next();
	int count = 0;
	while (itor.NextNotNull()) {
		temp.SetRank(count);
		E_List.ReplaceByIndex(temp, count);
		count++;
		temp = itor.Next();
	}
}

int EmpList::OpenInFile(char* filename) {
	E_inFile.open(filename);

	if (E_inFile.is_open())
		return 1;
	else
		return 0;
}

int EmpList::OpenOutFile(char* filename) {
	E_outFile.open(filename);

	if (E_outFile.is_open())
		return 1;
	else
		return 0;
}

int EmpList::ReadDataFromFile() {
	char filename[FILENAMESIZE];
	Employee data;
	cout << "####### Read data from file #######\n";
	cout << "Filename for reading data: ";
	cin >> filename;

	if (OpenInFile(filename)) {
		while (!E_inFile.eof()) {				
			data.ReadDataFromFile(E_inFile);
			Add(data);
		}
	}
	else {
		cout << "Error: Uncorrect file name\n";
		return 0;
	}

	E_inFile.close();

	return 1;
}

int EmpList::WriteDataToFile() {
	char filename[FILENAMESIZE];
	Employee data;
	cout << "####### Write data ro file ########\n";
	cout << "Filename for writing data: ";
	cin >> filename;

	if (OpenOutFile(filename)) {
		int count = 1;
		UnsortedIterator<Employee> itor(E_List);				
		data = itor.Next();
		while (itor.NextNotNull()) {							
			data.WriteDataToFile(E_outFile);					
			data = itor.Next();
		}
	}
	else {
		cout << "Error: Uncorrect file name\n";
		return 0;
	}

	E_outFile.close();

	return 1;
}

int EmpList::SearchByName(Employee& data) {
	UnsortedIterator<Employee> itor(E_List);
	Employee temp;
	int count = 1;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		if (temp.GetName().find(data.GetName()) != string::npos) {			//�̸��� ������ Ȯ��
			cout << count << ".\n";	
			temp.DisplayOnScreen();
			count++;		
		}
		temp = itor.Next();
	}
	if (count != 1) {
		return 1;
	}
	return 0;
}

int EmpList::SearchBySkill(Employee& data) {
	UnsortedIterator<Employee> itor(E_List);
	Employee temp;
	int count = 1;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		if (temp.GetSkill() == data.GetSkill()) {				//���õ��� ������ Ȯ��
			cout << count << ".\n";
			temp.DisplayOnScreen();
			count++;
		}
		temp = itor.Next();
	}
	if (count != 1) {
		return 1;
	}
	return 0;
}

int EmpList::SearchByPrefer(Employee& data) {
	UnsortedIterator<Employee> itor(E_List);
	Employee temp;
	int count = 1;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		if (temp.GetPrefer() == data.GetPrefer()) {				//���õ��� ������ Ȯ��
			cout << count << ".\n";
			temp.DisplayOnScreen();
			count++;
		}
		temp = itor.Next();
	}
	if (count != 1) {
		return 1;
	}
	return 0;
}

int EmpList::PickByName(Employee& data) {
	UnsortedIterator<Employee> itor(E_List);
	Employee temp;
	int count = 1;
	itor.Next();
	while (itor.NextNotNull()) {
		temp = itor.GetCurrentNode().value;
		if (temp.GetName() == data.GetName()) {			//�̸��� ������
			cout << count << ".\n";
			temp.DisplayOnScreen();
			itor.Next();
			count++;
			E_List.Delete(temp);					
			return 1;

		}
		itor.Next();
	}
	return 0;
}

int EmpList::PickEmployee(Employee& data, int size, int from, int to, bool prefer) {
	UnsortedIterator<Employee> itor(E_List);
	Employee temp;
	int count = 1;
	if (prefer == true) {
		itor.Next();
		while (itor.NextNotNull()) {
			if (count > size) {
				break;
			}
			temp = itor.GetCurrentNode().value;
			if (temp.GetPrefer() != data.GetPrefer()) {
				itor.Next();
				continue;
			}
			if (temp.GetSkill() == data.GetSkill()) {
				if (temp.GetAge() >= from && temp.GetAge() <= to) {
					if (temp.GetMoney() == data.GetMoney()) {				//������ ������ Ȯ��
						cout << count << ".\n";
						temp.DisplayOnScreen();
						itor.Next();
						count++;
						E_List.Delete(temp);							//����
						continue;
					}
				}
			}
			itor.Next();
		}
		return count - 1;
	}
	else {
		itor.Next();
		while (itor.NextNotNull()) {
			if (count > size) {
				break;
			}
			temp = itor.GetCurrentNode().value;
			if (temp.GetSkill() == data.GetSkill()) {
				if (temp.GetAge() >= from && temp.GetAge() <= to) {
					if (temp.GetMoney() == data.GetMoney()) {				//������ ������ Ȯ��
						cout << count << ".\n";
						temp.DisplayOnScreen();
						itor.Next();
						count++;
						E_List.Delete(temp);							//����
						continue;
					}
				}
			}
			itor.Next();
		}
		return count - 1;
	}
}

int EmpList::SetScore(Employee& data, bool prefer) {					//�Է� ������ ���� ���� ����
	UnsortedIterator<Employee> itor(E_List);
	if (E_List.IsEmpty()) {
		return 0;
	}
	Employee temp;
	int score = 0;
	if (prefer) {
		temp = itor.Next();
		while (itor.NextNotNull()) {
			EmpScore scotemp;
			//���� ����
			if (data.GetPrefer() == temp.GetPrefer()) {
				score = (20.0 * abs(data.GetSkill() - temp.GetSkill()) / 4.0) + (20.0 * abs(data.GetAge() - temp.GetAge()) / 2.0)
					+ (30.0 * abs(data.GetMoney() - temp.GetMoney()) / 100000.0) + (30 * temp.GetRank() / E_length);
				scotemp.SetRank(temp.GetRank());
				scotemp.SetScore(score);				//����Ʈ�� �߰�
				E_Score.Add(scotemp);
			}
			score = 0;
			temp = itor.Next();
		}
		return 1;
	}
	else {
		temp = itor.Next();
		while (itor.NextNotNull()) {
			EmpScore scotemp;
			//���� ����
			score = (20.0 * abs(data.GetSkill() - temp.GetSkill()) / 4.0) + (20.0 * abs(data.GetAge() - temp.GetAge()) / 2.0)
				+ (30.0 * abs(data.GetMoney() - temp.GetMoney()) / 100000.0) + (30 * temp.GetRank() / E_length);
			scotemp.SetRank(temp.GetRank());
			scotemp.SetScore(score);				//����Ʈ�� �߰�
			E_Score.Add(scotemp);
			score = 0;
			temp = itor.Next();
		}
		return 1;
	}
}

int EmpList::PickByScore(int size) {
	SortedIterator<EmpScore> itor(E_Score);
	EmpScore temp;
	int count = 1;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		if (count > size) {					//�ʿ��� �ο��� �� �����ߴ��� Ȯ��
			break;
		}
		Employee data;
		data.SetRank(temp.GetRank());				//��� ����
		E_List.Get(data);							//������ �޾Ƽ�
		cout << count << ".\n";					
		data.DisplayOnScreen();						//���
		E_List.Delete(data);						//����
		temp = itor.Next();
		count++;
	}
	return count - 1;
}