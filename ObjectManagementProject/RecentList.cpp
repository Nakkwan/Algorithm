#include "pch.h"
#include "RecentList.h"

RecentList::RecentList() {
	r_length = 0;
}

int RecentList::AddItem(ItemType& data) {
	r_Array.ResetQueue();
	if (r_Array.Get(data)) {
		r_Array.Delete(data);
		r_Array.Enqueue(data);
		r_length = r_Array.GetSize();
	}
	else {
		r_Array.Enqueue(data);
		r_length = r_Array.GetSize();
	}
	return 1;
}

void RecentList::DisplayItem(int size) {
	int numtemp = - 1;
	if (size >= r_length) {
		size = r_length;
	}
	else {
		numtemp = r_length - size;
	}
	ItemType temp;
	r_Array.ResetQueue();
	int r_pnt = r_Array.GetNextItem(temp);
	if (numtemp == -1) {
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ".\n";
			temp.DisplayRecordOnScreen();
			r_pnt = r_Array.GetNextItem(temp);
		}
	}
	else {
		for (int i = 0; i < numtemp; i++) {
			r_pnt = r_Array.GetNextItem(temp);
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