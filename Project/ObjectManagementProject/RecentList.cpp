#include "pch.h"
#include "RecentList.h"

RecentList::RecentList() {
	r_length = 0;
}

int RecentList::AddItem(ItemType& data) {
	r_Array.ResetQueue();
	if (r_Array.Get(data)) {						//이미 Queue에 있다면
		r_Array.Delete(data);						//삭제하고
		r_Array.Enqueue(data);						//다시 추가
		r_length = r_Array.GetSize();
	}
	else {
		r_Array.Enqueue(data);						//Queue에 없던 Object라면 추가
		r_length = r_Array.GetSize();				
	}
	return 1;
}

void RecentList::DisplayItem(int size) {
	int numtemp = - 1;
	if (size >= r_length) {						//출력한 물건의 범위 재조정
		size = r_length;
	}
	else {										//최근 List를 뽑기 위해
		numtemp = r_length - size;
	}
	ItemType temp;
	r_Array.ResetQueue();
	int r_pnt = r_Array.GetNextItem(temp);
	if (numtemp == -1) {									//전체 다 출력
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ".\n";
			temp.DisplayRecordOnScreen();
			r_pnt = r_Array.GetNextItem(temp);
		}
	}
	else {													//개수만큼 출력
		for (int i = 0; i < numtemp; i++) {
			r_pnt = r_Array.GetNextItem(temp);				//제일 최근 목록들을 뽑기 위함
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