#include "pch.h"
#include "RecentList.h"

RecentList::RecentList() {
	r_length = 0;
}

int RecentList::AddItem(ItemType& data) {
	r_Array.Enqueue(data);
	r_length = r_Array.GetSize();
	return 1;
}

void RecentList::DisplayItem(int size) {
	if (size > r_length) {
		size = r_length;
	}
	ItemType temp;
	r_Array.ResetQueue();
	int r_pnt = r_Array.GetNextItem(temp);
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\n";
		temp.DisplayRecordOnScreen();
		r_pnt = r_Array.GetNextItem(temp);
	}
}

void RecentList::MakeEmpty() {
	r_Array.MakeEmpty();
	r_length = 0;
}