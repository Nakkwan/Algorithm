#include "ArrayList.h"

ArrayList::ArrayList() {
	m_CurPointer = -1;
	m_length = 0;
}

int ArrayList::Add(ItemType data) {
	if (!IsFull()) {
		m_Array[m_length] = data;
		m_length++;
		return 1;
	}
	else {
		std::cout << "Error: List if full\n";
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

int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_length) {
		return -1;
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
	while (m_CurPointer != -1) {
		if (temp == data) {
			data = temp;
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
				m_Array[j] = m_Array[j + 1];
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