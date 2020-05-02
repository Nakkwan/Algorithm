#include "pch.h"
#include "RoomList.h"

RoomList::RoomList() {
	R_length = 0;
}

int RoomList::RoomAdd(RoomType& data) {
	if (R_List.Add(data)) {
		R_length++;
		return 1;
	}
	return 0;
}

int RoomList::RoomDelete(RoomType& data) {
	if (R_List.Delete(data)) {
		R_length--;
		return 1;
	}
	return 0;
}

int RoomList::RoomUpdate(RoomType& data) {
	if (R_List.Replace(data)) {
		return 1;
	}
	return 0;
}

int RoomList::RoomGet(RoomType& data) {
	if (R_List.Get(data)) {
		return 1;
	}
	return 0;
}

int RoomList::DisplayAllRoomInfo() {
	RoomType temp;
	int count = 1;
	int r_pointer = R_List.GetNextItem(temp);
	while (r_pointer != -1) {
		cout << count << ".\n";
		temp.DisplayInfo();
		r_pointer = R_List.GetNextItem(temp);
		count++;
	}
	if (count == 1) {
		return 0;
	}
	cout << setfill('#') << setw(30) << "\n\n";
	return 1;
}


int RoomList::DrawerAdd(DrawerType& data) {
	RoomType roTemp;
	roTemp.SetRoomID(data.GetRoomID());
	if (R_List.Get(roTemp)) {
		roTemp.AddDrawer(data);
		R_List.Replace(roTemp);
		return 1;
	}
	else {
		cout << "\t\t*There is no corresponding Room\n\t\t*Enter the Room Information\n";
		cout << "RoomID: " << roTemp.GetRoomID() << endl;
		roTemp.SetRoomNamefromKB();
		roTemp.AddDrawer(data);
		if (R_List.Add(roTemp)) {
			R_length++;
			return 1;
		}
		return 0;
	}
}

int RoomList::DrawerDelete(DrawerType& data) {
	RoomType roTemp;
	roTemp.SetRoomID(data.GetRoomID());
	if (R_List.Get(roTemp)) {
		if (roTemp.DeleteDrawer(data)) {
			R_List.Replace(roTemp);
			return 1;
		}
		return 0;
	}
	else {
		return 0;
	}
}

int RoomList::DrawerUpdate(DrawerType& data) {
	RoomType roTemp;
	roTemp.SetRoomID(data.GetRoomID());
	if (R_List.Get(roTemp)) {
		if (roTemp.UpdateDrawer(data)) {
			R_List.Replace(roTemp);
			return 1;
		}
		return 0;
	}
	else {
		return 0;
	}
}

int RoomList::DrawerGet(RoomType& rodata, DrawerType& data) {
	if (R_List.Get(rodata)) {
		if (rodata.GetDrawer(data)) {
			return 1;
		}
		return 0;
	}
	else {
		return 0;
	}
}

int RoomList::DisplayAllDrawerInfo() {
	if (R_List.IsEmpty()) {
		return 0;
	}
	int count1 = 1;
	int count2 = 1;
	RoomType roTemp;
	DrawerType draTemp;
	int r_pointer = R_List.GetNextItem(roTemp);
	while (r_pointer != -1) {
		cout << count1 << ".\n";
		roTemp.DisplayInfo();
		int d_pointer = roTemp.GetNextDrawer(draTemp);
		cout << "###### Drawer Information ######\n\n";
		while (d_pointer != -1) {
			cout << count2 << ".\n";
			draTemp.DisplayInfo();
			d_pointer = roTemp.GetNextDrawer(draTemp);
			count2++;
		}

		r_pointer = R_List.GetNextItem(roTemp);
		count1++;
		count2 = 1;
		cout << setfill('#') << setw(30) << "\n\n";
	}
	return 1;
}

int RoomList::ContainerAdd(ContainerType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			draTemp.AddContainer(data);
			roTemp.UpdateDrawer(draTemp);
			R_List.Replace(roTemp);
			return 1;
		}
		cout << "\t\t*There is no corresponding Drawer\n\t\t*Enter the Drawer Information\n";
		cout << "DrawerID: " << draTemp.GetDrawerID() << endl;
		draTemp.SetDrawerNamefromKB();
		draTemp.SetDrawerTypefromKB();
		draTemp.AddContainer(data);
		if (roTemp.AddDrawer(draTemp)) {
			R_List.Replace(roTemp);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		cout << "\t\t*There is no corresponding Room\n\t\t*Enter the Room Information\n";
		cout << "RoomID: " << roTemp.GetRoomID() << endl;
		roTemp.SetRoomNamefromKB();
		cout << "\t\t*There is no corresponding Drawer\n\t\t*Enter the Drawer Information\n";
		cout << "DrawerID: " << draTemp.GetDrawerID() << endl;
		draTemp.SetDrawerNamefromKB();
		draTemp.SetDrawerTypefromKB();
		draTemp.AddContainer(data);
		roTemp.AddDrawer(draTemp);
		if (R_List.Add(roTemp)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int RoomList::ContainerDelete(ContainerType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			if (draTemp.DeleteContainer(data)) {
				roTemp.UpdateDrawer(draTemp);
				R_List.Replace(roTemp);
				return 1;
			}
		}
	}
	else {
		return 0;
	}
	return 0;
}

int RoomList::ContainerUpdate(ContainerType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			if (draTemp.UpdateContainer(data)) {
				roTemp.UpdateDrawer(draTemp);
				R_List.Replace(roTemp);
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}

int RoomList::ContainerGet(RoomType& rodata, DrawerType& drdata, ContainerType& data) {
	if (R_List.Get(rodata)) {
		if (rodata.GetDrawer(drdata)) {
			if (drdata.GetContainer(data)) {
				return 1;
			}
		}
	}
	return 0;
}


int RoomList::DisplayAllContainerInfo() {
	if (R_List.IsEmpty()) {
		return 0;
	}
	int count1 = 1;
	int count2 = 1;
	int count3 = 1;
	RoomType roTemp;
	DrawerType draTemp;
	ContainerType conTemp;
	int r_pointer = R_List.GetNextItem(roTemp);
	while (r_pointer != -1) {
		cout << count1 << ".\n";
		roTemp.DisplayInfo();
		int d_pointer = roTemp.GetNextDrawer(draTemp);
		cout << "###### Drawer Information ######\n\n";
		while (d_pointer != -1) {
			cout << count2 << ".\n";
			draTemp.DisplayInfo();
			int c_pointer = draTemp.GetNextContainer(conTemp);
			cout << "#### Container Information ####\n\n";
			while (c_pointer != -1) {
				cout << count3 << ".\n";
				conTemp.DisplayContainer();
				c_pointer = draTemp.GetNextContainer(conTemp);
				count3++;
			}
			d_pointer = roTemp.GetNextDrawer(draTemp);
			count2++;
			count3 = 1;
		}

		r_pointer = R_List.GetNextItem(roTemp);
		count1++;
		count2 = 1;
		cout << setfill('#') << setw(30) << "\n\n";
	}
	return 1;
}

int RoomList::ObjectAdd(SimpleItemType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	ContainerType conTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	conTemp.SetContainerID(data.GetContainerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			if (draTemp.GetContainer(conTemp)) {
				conTemp.AddItem(data);
				draTemp.UpdateContainer(conTemp);
				roTemp.UpdateDrawer(draTemp);
				R_List.Replace(roTemp);
				return 1;
			}
			cout << "\t\t*There is no corresponding Container\n\t\t*Enter the Container Information\n";
			cout << "ContainerID: " << conTemp.GetContainerID() << endl;
			conTemp.SetContainerNamefromKB();
			conTemp.SetContainerTypefromKB();
			conTemp.SetContainerPhotofromKB();
			conTemp.AddItem(data);
			if (draTemp.AddContainer(conTemp)) {
				roTemp.UpdateDrawer(draTemp);
				R_List.Replace(roTemp);
				return 1;
			}
			else {
				return 0;
			}
		}
		cout << "\t\t*There is no corresponding Drawer\n\t\t*Enter the Drawer Information\n";
		cout << "DrawerID: " << draTemp.GetDrawerID() << endl;
		draTemp.SetDrawerNamefromKB();
		draTemp.SetDrawerTypefromKB();
		cout << "\t\t*There is no corresponding Container\n\t\t*Enter the Container Information\n";
		cout << "ContainerID: " << conTemp.GetContainerID() << endl;
		conTemp.SetContainerNamefromKB();
		conTemp.SetContainerTypefromKB();
		conTemp.SetContainerPhotofromKB();
		conTemp.AddItem(data);
		draTemp.AddContainer(conTemp);
		if (roTemp.AddDrawer(draTemp)) {
			R_List.Replace(roTemp);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		cout << "\t\t*There is no corresponding Room\n\t\t*Enter the Room Information\n";
		cout << "RoomID: " << roTemp.GetRoomID() << endl;
		roTemp.SetRoomNamefromKB();
		cout << "\t\t*There is no corresponding Drawer\n\t\t*Enter the Drawer Information\n";
		cout << "DrawerID: " << draTemp.GetDrawerID() << endl;
		draTemp.SetDrawerNamefromKB();
		draTemp.SetDrawerTypefromKB();
		cout << "\t\t*There is no corresponding Container\n\t\t*Enter the Container Information\n";
		cout << "ContainerID: " << conTemp.GetContainerID() << endl;
		conTemp.SetContainerNamefromKB();
		conTemp.SetContainerTypefromKB();
		conTemp.SetContainerPhotofromKB();
		conTemp.AddItem(data);
		draTemp.AddContainer(conTemp);
		roTemp.AddDrawer(draTemp);
		if (R_List.Add(roTemp)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int RoomList::ObjectDelete(SimpleItemType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	ContainerType conTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	conTemp.SetContainerID(data.GetContainerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			if (draTemp.GetContainer(conTemp)) {
				if (conTemp.DeleteItem(data)) {
					draTemp.UpdateContainer(conTemp);
					roTemp.UpdateDrawer(draTemp);
					R_List.Replace(roTemp);
					return 1;
				}
			}
		}
	}
	else {
		return 0;
	}
	return 0;
}

int RoomList::ObjectUpdate(SimpleItemType& data) {
	RoomType roTemp;
	DrawerType draTemp;
	ContainerType conTemp;
	roTemp.SetRoomID(data.GetRoomID());
	draTemp.SetDrawerID(data.GetDrawerID());
	if (R_List.Get(roTemp)) {
		if (roTemp.GetDrawer(draTemp)) {
			if (draTemp.GetContainer(conTemp)) {
				if (conTemp.UpdateItem(data)) {
					draTemp.UpdateContainer(conTemp);
					roTemp.UpdateDrawer(draTemp);
					R_List.Replace(roTemp);
					return 1;
				}
			}
		}
	}
	return 0;
}

int RoomList::ObjectGet(RoomType& rodata, DrawerType& drdata, ContainerType& codata, SimpleItemType& data) {
	if (R_List.Get(rodata)) {
		if (rodata.GetDrawer(drdata)) {
			if (drdata.GetContainer(codata)) {
				if (codata.GetItem(data)) {

					return 1;
				}
			}
		}
	}
	return 0;
}

int RoomList::DisplayAllObjectInfo() {
	if (R_List.IsEmpty()) {
		return 0;
	}
	int count1 = 1;
	int count2 = 1;
	int count3 = 1;
	RoomType roTemp;
	DrawerType draTemp;
	ContainerType conTemp;
	int r_pointer = R_List.GetNextItem(roTemp);
	while (r_pointer != -1) {
		cout << count1 << ".\n";
		roTemp.DisplayInfo();
		int d_pointer = roTemp.GetNextDrawer(draTemp);
		cout << "###### Drawer Information ######\n\n";
		while (d_pointer != -1) {
			cout << count2 << ".\n";
			draTemp.DisplayInfo();
			int c_pointer = draTemp.GetNextContainer(conTemp);
			cout << "#### Container Information ####\n\n";
			while (c_pointer != -1) {
				cout << count3 << ".\n";
				conTemp.DisplayContainer();
				cout << "## Item Information ##\n\n";
				conTemp.DisplayAllItem();
				c_pointer = draTemp.GetNextContainer(conTemp);
				count3++;
			}
			d_pointer = roTemp.GetNextDrawer(draTemp);
			count2++;
			count3 = 1;
		}

		r_pointer = R_List.GetNextItem(roTemp);
		count1++;
		count2 = 1;
		cout << setfill('#') << setw(25) << '\n';
		cout << setfill('#') << setw(25) << "\n\n";
	}
	return 1;
}