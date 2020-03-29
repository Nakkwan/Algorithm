#include "ArrayList.h"

ArrayList::ArrayList() {
	m_CurPointer = -1;
	m_length = 0;
}

int ArrayList::Add(ItemType data) {
	if (!IsFull()) {		//배열이 꽉 차있지 않은지 확인
		if (Get(data)) {	//이미 고유 라벨이 존재하는지 확인, 있다면 추가 하지 않음
			return 0;
		}
		m_Array[m_length] = data;
		m_length++;
		return 1;
	}
	else {
		cout << "Error: List if full\n";
		return 0;
	}
}

void ArrayList::MakeEmpty() {
	m_length = 0;
}

int ArrayList::GetLength() {
	return m_length;
}

bool ArrayList::IsFull() {
	if (m_length == MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

bool ArrayList::IsEmpty() {
	if (m_length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int ArrayList::GetNextItem(ItemType& data) {		//현재 포인터를 반환하고, 레퍼런스로 데이터를 돌려줌
	m_CurPointer++;
	if (m_CurPointer == m_length) {
		m_CurPointer = -1;
		return m_CurPointer;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

void ArrayList::ResetList() {
	m_CurPointer = -1;
}

int ArrayList::Get(ItemType& data) {
	ItemType temp;
	ResetList();
	GetNextItem(temp);
	while (m_CurPointer != -1) {	//배열 전체 탐색
		if (temp == data) {
			data = temp;			//데이터 반환
			return 1;
		}
		GetNextItem(temp);
	}
	return 0;
}

int ArrayList::Delete(ItemType data) {
	ItemType temp;
	ResetList();
	GetNextItem(temp);
	while (m_CurPointer != -1) {
		if (temp == data) {
			for (int j = m_CurPointer; j < m_length - 1; j++) {		
				m_Array[j] = m_Array[j + 1];				//현재포인터까지 배열을 한단계씩 앞으로 당김
			}
			m_length--;
			return 1;
		}
		GetNextItem(temp);
	}
	return 0;
}

int ArrayList::Replace(ItemType data) {
	ItemType temp;
	ResetList();
	GetNextItem(temp);
	while (m_CurPointer != -1) {
		if (temp == data) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
	}
	return 0;
}