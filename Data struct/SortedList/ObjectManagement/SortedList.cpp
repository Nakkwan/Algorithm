#include "SortedList.h"

SortedList::SortedList() {
	m_CurPointer = -1;
	m_length = 0;
}

int SortedList::Add(const ItemType& data) {
	if (m_length == 0) {
		m_Array[0] = data;
		m_length++;
		return 1;
	}
	else if (m_length == MAXSIZE) {
		cout << "Array is pull/n";
		return 0;
	}
	else {
		ItemType temp;
		bool complete = false;
		ResetList();
		GetNextItem(temp);
		while (m_CurPointer < m_length) {
			if (temp < data) {				//���������̱� ������ ���� ��Һ��� ���� ���� ũ�ٸ� ���ʿ� ��ġ
				GetNextItem(temp);
				continue;
			}
			else if (temp > data) {			//���� ���� �� ū���� ó�� ���� ������ item�� ��ġ�� ���̴�.
				for (int j = m_length; j > m_CurPointer; j--) {
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[m_CurPointer] = data;
				m_length++;
				complete = true;
				break;
			}
			else {							//���� ���� ���� ���� ���⶧���� add�� return 0�� ����
				return 0;
			}
		}
		if (complete == false) {			//���� ���� Ŀ�� ���� �ڿ� ��ġ�ؾ� �� ��
			m_length++;
			m_Array[m_CurPointer] = data;
		}
		ResetList();
		return 1;
	}
}

void SortedList::MakeEmpty() {
	m_length = 0;
}

int SortedList::GetLength() {
	return m_length;
}

bool SortedList::IsFull() {
	if (m_length == MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

bool SortedList::IsEmpty() {
	if (m_length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int SortedList::GetNextItem(ItemType& data) {		//���� �����͸� ��ȯ�ϰ�, ���۷����� �����͸� ������
	m_CurPointer++;
	if (m_CurPointer == m_length) {
		m_CurPointer = -1;
		return m_CurPointer;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

void SortedList::ResetList() {
	m_CurPointer = -1;
}

int SortedList::Get(ItemType& data) {
	if (m_length == 0) {
		return 0;
	}
	else {
		ResetList();
		int left = 0, right = m_length;
		m_CurPointer = (left + right) / 2;
		while (left == m_CurPointer) {
			if (m_Array[m_CurPointer] > data) {
				right = m_CurPointer;
			}
			else if (m_Array[m_CurPointer] < data) {
				left = m_CurPointer;
			}
			else {
				data.SetRecordByItem(m_Array[m_CurPointer]);
				return 1;
			}
			m_CurPointer = (left + right) / 2;
		}
	}
	return 0;
}


int SortedList::Delete(ItemType data) {
	if (m_length == 0) {
		return 0;
	}
	else {
		ResetList();
		int left = 0, right = m_length;
		m_CurPointer = (left + right) / 2;
		while (left == m_CurPointer) {
			if (m_Array[m_CurPointer] > data) {
				right = m_CurPointer;
			}
			else if (m_Array[m_CurPointer] < data) {
				left = m_CurPointer;
			}
			else {
				for (int j = m_CurPointer; j < m_length - 1; j++) {
					m_Array[j] = m_Array[j + 1];				//���������ͱ��� �迭�� �Ѵܰ辿 ������ ���
				}
				m_length--;
				return 1;
			}
			m_CurPointer = (left + right) / 2;
		}
	}
	return 0;
}

int SortedList::Replace(ItemType data) {
	if (m_length == 0) {
		return 0;
	}
	else {
		ResetList();
		int left = 0, right = m_length;
		m_CurPointer = (left + right) / 2;
		while (left == m_CurPointer) {
			if (m_Array[m_CurPointer] > data) {
				right = m_CurPointer;
			}
			else if (m_Array[m_CurPointer] < data) {
				left = m_CurPointer;
			}
			else {
				m_Array[m_CurPointer] = data;
				return 1;
			}
			m_CurPointer = (left + right) / 2;
		}
	}
	return 0;
}