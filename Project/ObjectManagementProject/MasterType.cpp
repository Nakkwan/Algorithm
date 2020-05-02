#include "pch.h"
#include "MasterType.h"

MasterType::MasterType() {
	M_length = 0;
}

int MasterType::AddObject(ItemType& data) {
	if (M_List.Get(data)) {
		cout << "Error: Object is already exist. Check ID\n";
		return 0;
	}
	if(M_List.Add(data)) {
		return 1;
		M_length++;
		
	}
	cout << "Error: Storage is already full\n";
	return 0;
}

int MasterType::DeleteObject(ItemType& data) {
	if (!M_List.Get(data)) {
		cout << "Error: No such Object found\n";
		return 0;
	}
	if (M_List.Delete(data)) {
		M_length--;
		return 1;
	}
	
	cout << "Error: Delete Fail\n";
	return 0;
}

int MasterType::UpdateObject(const ItemType& data) {
	if (M_List.IsEmpty()) {
		cout << "Error: No such Object found\n";
		return 0;
	}
	if (M_List.Replace(data)) {
		return 1;
	}
	cout << "Error: Update Fail\n";
	return 0;
}

int MasterType::ReplaceObject(const ItemType& data) {
	if (M_List.IsEmpty()) {
		cout << "Error: No such Object found\n";
		return 0;
	}
	if (M_List.Replace(data)) {
		return 1;
	}
	cout << "Error: Update Fail\n";
	return 0;
}

int MasterType::GetObject(ItemType& data) {
	if (M_List.Get(data)) {
		data.DisplayRecordOnScreen();		//출력
		data.AddSearchNum();
		ReplaceObject(data);
		return 1;
	}
	return 0;
}

int MasterType::GetObjectByName(ItemType& data) {
	int count = 1;
	ItemType temp;
	DoublyIterator<ItemType> itor(M_List);
	while (itor.NextNotNull()) {				//리스트가 끝날 때까지
		temp = itor.Next();
		if (temp.GetName().find(data.GetType())) {				//용도가 같다면
			cout << count << ".\n";
			temp.DisplayRecordOnScreen();		//출력
			temp.AddSearchNum();
			ReplaceObject(temp);
			count++;
		}
	}
	if (count == 1) {
		return 0;
	}
	return 1;
}

int MasterType::GetObjectByUsage(ItemType& data) {
	int count = 1;
	ItemType temp;
	DoublyIterator<ItemType> itor(M_List);
	while (itor.NextNotNull()) {				//리스트가 끝날 때까지
		temp = itor.Next();
		if (temp.GetType() == data.GetType()) {				//용도가 같다면
			cout << count << ".\n";
			temp.DisplayRecordOnScreen();		//출력
			temp.AddSearchNum();
			ReplaceObject(temp);
			count++;
		}
	}
	if (count == 1) {
		return 0;
	}
	return 1;
}

int MasterType::GetObjectByBuydate(int start, int finish) {
	int count = 1;
	ItemType data;
	DoublyIterator<ItemType> itor(M_List);
	while (itor.NextNotNull()) {
		data = itor.Next();
		if (data.GetBuyDate() >= start && data.GetBuyDate() <= finish) {		//찾으려는 년도라면
			cout << count << ".\n";
			data.DisplayRecordOnScreen();							//출력
			data.AddSearchNum();
			ReplaceObject(data);
			count++;
			cout << "\n";
		}
	}
	if (count == 1) {
		return 0;
	}
	return 1;
}

int MasterType::DisplayAllObject() {
	ItemType data;
	int count = 1;
	DoublyIterator<ItemType> itor(M_List);
	data = itor.Next();
	while (itor.NextNotNull()) {		//처음부터 끝까지 데이터 출력
		cout << count << ".\n";
		data.DisplayRecordOnScreen();
		data = itor.Next();
		count++;
	}
	if (count == 1) {
		return 0;
	}
	return 1;
}

int MasterType::OpenInFile(char* filename) {
	a_inFile.open(filename);

	if (a_inFile.is_open())
		return 1;
	else
		return 0;
}

int MasterType::OpenOutFile(char* filename) {
	a_outFile.open(filename);

	if (a_outFile.is_open())
		return 1;
	else
		return 0;
}

int MasterType::ReadDataFromFile() {
	char filename[FILENAMESIZE];
	ItemType data;
	cout << "##### Read data from file #####\n";
	cout << "Enter the filename for reading data: ";
	cin >> filename;

	if (OpenInFile(filename)) {
		while (!a_inFile.eof()) {				//파일이 끝나기 전까지 데이터 읽기
			data.ReadDataFromFile(a_inFile);
			AddObject(data);

		}
	}
	else {
		cout << "Error: Uncorrect file name\n";
		return 0;
	}
	return 1;
}

int MasterType::WriteDataToFile() {
	char filename[FILENAMESIZE];
	ItemType data;
	cout << "##### Write data ro file #####\n";
	cout << "Enter the filename for writing data: ";
	cin >> filename;

	if (OpenOutFile(filename)) {
		int count = 1;
		DoublyIterator<ItemType> itor(M_List);				//MasterList의 itorater 생성
		data = itor.Next();
		while (itor.NextNotNull()) {							//아직 데이터가 남아있다면
			data.WriteDataToFile(a_outFile);					//데이터 쓰기
			data = itor.Next();
		}
	}
	else {
		cout << "Error: Uncorrect file name\n";
		return 0;
	}

	a_outFile.close();

	return 1;
}