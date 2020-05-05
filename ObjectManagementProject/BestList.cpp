#include "pch.h"
#include "BestList.h"

BestList::BestList() {
	B_length = 0;
}

bool BestList::CompareSearchNum(const ItemType& data) {
	ItemType temp;
	B_Array.GetTop(temp);
	if (temp.GetSearchNum() >= data.GetSearchNum()) {
		return true;
	}
	return false;
}

int BestList::AddItem(ItemType& data) {
	if (!B_Array.IsFull()) {
		if (B_Array.Replace(data)) {
			RearrangeStack();
			return 1;
		}
		else {
			B_Array.Push(data);
			B_length++;
			return 1;
		}
	}
	if (CompareSearchNum(data)) {
		return 0;
	}
	ItemType temp;
	B_Array.Pop(temp);
	B_Array.Push(data);
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
			if (num > temp.GetSearchNum()) {
				continue;
			}
			else {
				ItemType temp3;
				B_Array.GetbyIndex(temp2, pnt - 1);
				temp3.SetRecordByItem(temp2);
				B_Array.ReplacebyIndex(temp, pnt - 1);
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