#include "SortedListType.h"

void SortedListType::MakeEmpty() {
	m_length = 0;
}

int SortedListType::GetLength() {
	return m_length;
}

int SortedListType::IsFull() {
	if (m_length == MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

void SortedListType::ResetList() {
	m_CurPointer = 0;
}

int SortedListType::GetNextItem(ItemType& data) {
	m_CurPointer++;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

int SortedListType::Add(ItemType data) {
	if (m_length == 0) {
		m_Array[0] = data;
		m_length++;
		return 1;
	}
	else if (m_length == MAXSIZE) {
		cerr << "Array is pull/n";
		return 0;
	}
	else {
		ItemType temp;
		bool complete = false;
		ResetList();
		GetNextItem(temp);
		while (m_CurPointer < m_length) {
			if (temp.CompareByID(data) == LESS) {
				GetNextItem(temp);
				continue;
			}
			else if (temp.CompareByID(data) == GREATER) {
				for (int j = m_length; j > m_CurPointer; j--) {
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[m_CurPointer] = data;
				m_length++;
				complete = true;
				break;
			}
		}
		if (complete == false) {
			m_length++;
			m_Array[m_CurPointer] = data;
		}
		ResetList();
		return 1;
	}
}

int SortedListType::Delete(ItemType target) {
	if (Get(target)) {
		for (int i = m_CurPointer; i < m_length - 1; i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_length--;
	}
	else {
		return 0;
	}
	return 1;
}

int SortedListType::Replace(ItemType target) {
	ItemType dummy = target;
	if (Get(dummy)) {
		m_Array[m_CurPointer] = target;
	}
	else {
		return 0;
	}
	return 1;
}

int SortedListType::Get(ItemType& target) {
	ItemType data;
	ResetList();
	GetNextItem(data);
	while (m_CurPointer < m_length) {
		switch (data.CompareByID(target)) {
		case 0:
			target.SetRecord(data.GetId(), data.GetName(), data.GetAddress());
			return 1;
		case 1:
			return 0;
		default:
			GetNextItem(data);
			break;
		}
	}
	return 0;
}

int SortedListType::GetByBinarySearch(ItemType& data){
	if (m_length == 0) {
		return 0;
	}
	else {
		int left = 0, right = m_length;
		int mid = (left + right) / 2;
		while (left == mid) {
			if (m_Array[mid].CompareByID(data) == GREATER) {
				right = mid;
			}
			else if (m_Array[mid].CompareByID(data) == LESS) {
				left = mid;
			}
			else {
				data.SetRecord(m_Array[mid].GetId(), m_Array[mid].GetName(), m_Array[mid].GetAddress());
				return 1;
			}
			mid = (left + right) / 2;
		}
	}
	return 0;
}