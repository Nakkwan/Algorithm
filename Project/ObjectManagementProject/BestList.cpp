#include "pch.h"
#include "BestList.h"

BestList::BestList() {
	B_length = 0;
}

bool BestList::CompareSearchNum(const ItemType& data) {				//Stack�� ������ Object�� �˻� Ƚ�� ��
	ItemType temp;
	B_Array.GetTop(temp);
	if (temp.GetSearchNum() >= data.GetSearchNum()) {
		return true;
	}
	return false;
}

int BestList::AddItem(ItemType& data) {
	if (!B_Array.IsFull()) {							//����Ʈ�� �̹� ��á���� Ȯ��
		if (B_Array.Replace(data)) {					//����Ʈ�� ������ �ʾҰ�, �̹� List�� ������ �����Ѵٸ�,
			RearrangeStack();							//����Ʈ �� ���� ��� ����
			return 1;
		}
		else {											//����Ʈ�� ������ �ʾҰ�, ������ �������� �ʴ´ٸ�
			B_Array.Push(data);							//���� �߰�
			B_length++;
			return 1;
		}
	}
														//����Ʈ�� ����
	if (CompareSearchNum(data)) {						//Stack�� top�� �� �˻�Ƚ���� ���ٸ� ����
		return 0;										
	}
	if (B_Array.Replace(data)) {						//����Ʈ�� �̹� �ִٸ�
		RearrangeStack();								//����Ʈ �� ���� ��� ����
		return 1;
	}
	ItemType temp;										//����Ʈ�� ������, ������ ����, top���� �˻�Ƚ���� ���ٸ�
	B_Array.Pop(temp);									//top ����
	B_Array.Push(data);									//�߰�
	return 1;
}

void BestList::RearrangeStack() {
	ItemType temp;
	ItemType temp2;
	B_Array.ResetStack();
	int pnt = B_Array.GetNextItem(temp);
	int num;
	while (pnt != -1) {
		num = temp.GetSearchNum(); 
		pnt = B_Array.GetNextItem(temp);								
		if (pnt != -1) {
			if (num > temp.GetSearchNum()) {						//�˻� Ƚ�� ��
				continue;
			}
			else {													//�˻�Ƚ���� �� ���Ƽ� ������ �ٲ����
				ItemType temp3;										
				B_Array.GetbyIndex(temp2, pnt - 1);
				temp3.SetRecordByItem(temp2);
				B_Array.ReplacebyIndex(temp, pnt - 1);				//���� ��ü
				B_Array.ReplacebyIndex(temp3, pnt);
				break;
			}
		}
	}
}

void BestList::DisplayAllItem() {
	ItemType temp;
	B_Array.ResetStack();
	int pnt = B_Array.GetNextItem(temp);
	while (pnt != -1) {
		cout << pnt + 1 << ".\n";
		temp.DisplayRecordOnScreen();
		pnt = B_Array.GetNextItem(temp);
	}
}

//void BestList::MakeEmpty() {
//	
//}