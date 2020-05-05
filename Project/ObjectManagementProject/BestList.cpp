#include "pch.h"
#include "BestList.h"

BestList::BestList() {
	B_length = 0;
}

bool BestList::CompareSearchNum(const ItemType& data) {				//Stack의 마지막 Object와 검색 횟수 비교
	ItemType temp;
	B_Array.GetTop(temp);
	if (temp.GetSearchNum() >= data.GetSearchNum()) {
		return true;
	}
	return false;
}

int BestList::AddItem(ItemType& data) {
	if (!B_Array.IsFull()) {							//리스트가 이미 꽉찼는지 확인
		if (B_Array.Replace(data)) {					//리스트가 꽉차지 않았고, 이미 List에 물건이 존재한다면,
			RearrangeStack();							//리스트 내 물건 목록 조정
			return 1;
		}
		else {											//리스트가 꽉차지 않았고, 물건이 존재하지 않는다면
			B_Array.Push(data);							//물건 추가
			B_length++;
			return 1;
		}
	}
														//리스트가 꽉참
	if (CompareSearchNum(data)) {						//Stack의 top이 더 검색횟수가 많다면 종료
		return 0;										
	}
	if (B_Array.Replace(data)) {						//리스트에 이미 있다면
		RearrangeStack();								//리스트 내 물건 목록 조정
		return 1;
	}
	ItemType temp;										//리스트가 꽉차고, 물건이 없고, top보다 검색횟수가 많다면
	B_Array.Pop(temp);									//top 삭제
	B_Array.Push(data);									//추가
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
			if (num > temp.GetSearchNum()) {						//검색 횟수 비교
				continue;
			}
			else {													//검색횟수가 더 많아서 순서를 바꿔야함
				ItemType temp3;										
				B_Array.GetbyIndex(temp2, pnt - 1);
				temp3.SetRecordByItem(temp2);
				B_Array.ReplacebyIndex(temp, pnt - 1);				//순서 교체
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