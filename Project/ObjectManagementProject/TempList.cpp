#include "pch.h"
#include "TempList.h"

int TempList::Enqueue(const ItemType& data) {
	if (tItemList.Enqueue(data))
	{
		numOfItems++;
		return 1;
	}
	return 0;
}

int TempList::Dequeue(ItemType& data) {
	if (tItemList.Dequeue(data))
	{
		numOfItems--;
		return 1;
	}
	return 0;
}

int TempList::Replace(const ItemType& data) {
	if (tItemList.Replace(data)) {
		return 1;
	}
	return 0;
}

int TempList::getNumofItem() {
	return numOfItems;
}

void TempList::MakeEmpty() {
	tItemList.MakeEmpty();
	numOfItems = 0;
}

bool TempList::IsFull() {
	if (numOfItems == MAXTEMP) {
		return true;
	}
	else {
		return false;
	}
}

bool TempList::IsEmpty() {
	if (numOfItems == 0) {
		return true;
	}
	else {
		return false;
	}
}

void TempList::DisplayAllItem() {
	ItemType temp;
	LinkedQueueIterator<ItemType> itor(tItemList);
	itor.Next();
	int count = 1;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		cout << count << ".\n";				//가독성을 위해 번호 부여
		temp.DisplayLabelOnScreen();
		temp.DisplayNameOnScreen();
		temp.DisplayTypeOnScreen();
		temp.DisplayDateOnScreen();
		temp.DisplayVolumeOnScreen();
		temp = itor.Next();
		count++;
	}
}

int TempList::Get(ItemType& data) {
	if (tItemList.Get(data)) {
		return 1;
	}
	else {
		return 0;
	}
}

int TempList::Delete(ItemType& data) {
	if (tItemList.Delete(data)) {
		numOfItems--;
		return 1;
	}
	else {
		return 0;
	}
}

//int TempList::AllocateItem(ItemType& data) {
//	if (tItemList.Get(data)) {
//		do {
//			cout << "### Allocate Location of Object ###\n";
//			data.SetRoomIDFromKB();
//			data.SetDrawerIDFromKB();
//			data.SetContainerIDFromKB();
//			cout << "Set New Object ID\n";
//			data.SetLabelFromKB();
//		} while (Master_List.GetObject(data));
//		if (Master_List.AddObject(data)) {
//			tItemList.Delete(data);
//			return 1;
//		}
//	}
//	return 0;
//}