#include "ArrayList.h"

ArrayList::ArrayList() {
	m_CurPointer = -1;
	m_length = 0;
}

void ArrayList::Add(ItemType data) {
	if (m_length < MAXSIZE) {
		m_Array[m_length] = data;
		m_length++;
	}
	else {
		std::cout << "Error: List if full\n";
	}
}

void ArrayList::MakeEmpty() {
	m_length = 0;
}

int ArrayList::GetLength() {
	return m_length;
}

int ArrayList::IsFull() {
	if (m_length == MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

void ArrayList::ResetList() {
	m_CurPointer = 0;
}

int ArrayList::Get(ItemType& data) {
	for (int i = 0; i < m_length; i++) {
		if (m_Array[i].CompareByID(data) == EQUAL) {
			data.SetRecord(m_Array[i].GetId(), m_Array[i].GetName(), m_Array[i].GetAddress());
			return 1;
		}
	}
	return 0;
}

void ArrayList::Delete(ItemType data) {
	bool exist = false;
	for (int i = 0; i < m_length; i++) {
		if (m_Array[i].CompareByID(data) == EQUAL) {
			for (int j = i; j < m_length - 1; j++) {
				ItemType temp = m_Array[j];
				m_Array[j] = m_Array[j + 1];
				m_Array[j + 1] = temp;
			}
			m_length--;
			exist = true;
			break;
		}
	}

	if (exist == false) {
		std::cout << "Data is not exist\n";
	}
}

void ArrayList::Replace(ItemType data) {
	for (int i = 0; i < m_length; i++) {
		if (m_Array[i].CompareByID(data) == EQUAL) {
			m_Array[i].SetRecord(data.GetId(), data.GetName(), data.GetAddress());
		}
	}
}