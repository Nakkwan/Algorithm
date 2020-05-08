#include "pch.h"
#include "Employee.h"

int EmpList::Add(Employee& data) {
	data.SetRank(E_List.GetLength());			//등록 순서를 할당
	if (E_List.Add(data)) {						//리스트에 추가
		E_length++;
		return 1;
	}
	return 0;
}

int EmpList::Delete(Employee& data) {			//삭제
	if (E_List.Delete(data)) {
		E_length--;
		return 1;
	}
	return 0;
}

void EmpList::Display() {						//리스트를 출력
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

void EmpList::RearrangeRank() {					//등록 순서를 재조정
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
		if (temp.GetName().find(data.GetName()) != string::npos) {			//이름이 같은지 확인
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
		if (temp.GetSkill() == data.GetSkill()) {				//숙련도가 같은지 확인
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
		if (temp.GetPrefer() == data.GetPrefer()) {				//숙련도가 같은지 확인
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
		if (temp.GetName() == data.GetName()) {			//이름이 같으면
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
					if (temp.GetMoney() == data.GetMoney()) {				//정보가 같은지 확인
						cout << count << ".\n";
						temp.DisplayOnScreen();
						itor.Next();
						count++;
						E_List.Delete(temp);							//삭제
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
					if (temp.GetMoney() == data.GetMoney()) {				//정보가 같은지 확인
						cout << count << ".\n";
						temp.DisplayOnScreen();
						itor.Next();
						count++;
						E_List.Delete(temp);							//삭제
						continue;
					}
				}
			}
			itor.Next();
		}
		return count - 1;
	}
}

int EmpList::SetScore(Employee& data, bool prefer) {					//입력 정보에 따른 점수 설정
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
			//점수 설정
			if (data.GetPrefer() == temp.GetPrefer()) {
				score = (20.0 * abs(data.GetSkill() - temp.GetSkill()) / 4.0) + (20.0 * abs(data.GetAge() - temp.GetAge()) / 2.0)
					+ (30.0 * abs(data.GetMoney() - temp.GetMoney()) / 100000.0) + (30 * temp.GetRank() / E_length);
				scotemp.SetRank(temp.GetRank());
				scotemp.SetScore(score);				//리스트에 추가
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
			//점수 설정
			score = (20.0 * abs(data.GetSkill() - temp.GetSkill()) / 4.0) + (20.0 * abs(data.GetAge() - temp.GetAge()) / 2.0)
				+ (30.0 * abs(data.GetMoney() - temp.GetMoney()) / 100000.0) + (30 * temp.GetRank() / E_length);
			scotemp.SetRank(temp.GetRank());
			scotemp.SetScore(score);				//리스트에 추가
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
		if (count > size) {					//필요한 인원을 다 차출했는지 확인
			break;
		}
		Employee data;
		data.SetRank(temp.GetRank());				//등록 순위
		E_List.Get(data);							//데이터 받아서
		cout << count << ".\n";					
		data.DisplayOnScreen();						//출력
		E_List.Delete(data);						//삭제
		temp = itor.Next();
		count++;
	}
	return count - 1;
}