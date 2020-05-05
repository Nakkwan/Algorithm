#include "pch.h"
#include "RecentList.h"

RecentList::RecentList() {
	r_length = 0;
}

int RecentList::AddItem(ItemType& data) {
	r_Array.ResetQueue();
	if (r_Array.Get(data)) {						//�̹� Queue�� �ִٸ�
		r_Array.Delete(data);						//�����ϰ�
		r_Array.Enqueue(data);						//�ٽ� �߰�
		r_length = r_Array.GetSize();
	}
	else {
		r_Array.Enqueue(data);						//Queue�� ���� Object��� �߰�
		r_length = r_Array.GetSize();				
	}
	return 1;
}

void RecentList::DisplayItem(int size) {
	int numtemp = - 1;
	if (size >= r_length) {						//����� ������ ���� ������
		size = r_length;
	}
	else {										//�ֱ� List�� �̱� ����
		numtemp = r_length - size;
	}
	ItemType temp;
	r_Array.ResetQueue();
	int r_pnt = r_Array.GetNextItem(temp);
	if (numtemp == -1) {									//��ü �� ���
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ".\n";
			temp.DisplayRecordOnScreen();
			r_pnt = r_Array.GetNextItem(temp);
		}
	}
	else {													//������ŭ ���
		for (int i = 0; i < numtemp; i++) {
			r_pnt = r_Array.GetNextItem(temp);				//���� �ֱ� ��ϵ��� �̱� ����
		}
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ".\n";
			temp.DisplayRecordOnScreen();
			r_pnt = r_Array.GetNextItem(temp);
		}
	}
}

void RecentList::MakeEmpty() {
	r_Array.MakeEmpty();
	r_length = 0;
}