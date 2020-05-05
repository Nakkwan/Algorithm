#include "pch.h"
#include "Application.h"


void Application::Run(){
	while (1) {
		a_Command = GetCommand();
		switch (a_Command)
		{
		case 1:
			MasterAddObject();						//���� �߰�
			break;
		case 2:
			MasterDeleteObject();					//���� ����
			break;
		case 3:
			MasterUpdateObject();					//���� ����
			break;
		case 4:
			RunDisplay();							//��� ���� �Լ�
			break;
		case 5:
			RunSearching();							//�˻� ���� �Լ�
			break;
		case 6:
			RunSetting();							//���� ȯ�� ���� �Լ�
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::MasterAddObject() {
	ItemType data;
	cout << "\t###### ���� �߰� ######\n";
	cout << "\t###### ���� ���� ######\n";
	data.SetRecordFromKB();
	SimpleItemType simTemp;
	simTemp.SetRecordByItemType(data);
	if (Room_List.ObjectAdd(simTemp)) {
		if (Master_List.AddObject(data)) {
			cout << "\t\t<Add Success>\n";
			return 1;
		}
	}
	return 0;
}
int Application::MasterDeleteObject() {
	ItemType data;
	cout << "\t###### ���� ���� ######\n";
	cout << "\t###### ����  ID  ######\n";
	cout << "(R: RoomID, SS: StorageID, CC: ContainerID, LL: Unique Label(10~99))\n";
	cout << "Label(RSSCCLL): ";
	int label;
	cin >> label;
	data.SetLabel(label);
	SimpleItemType simTemp;
	simTemp.SetRecordByItemType(data);
	if (Room_List.ObjectDelete(simTemp)) {
		if (Master_List.DeleteObject(data)) {
			cout << "\t\t<Delete Success>\n";
			return 1;
		}
	}
	return 0;
}
int Application::MasterUpdateObject() {
	ItemType data;
	int lab;
	cout << "\t###### ���� ���� ######\n";
	cout << "\t###### ���� ���� ######\n";
	cout << "(R: RoomID, SS: StorageID, CC: ContainerID, LL: Unique Label(10~99))\n";
	cout << "Label(RSSCCLL): ";
	cin >> lab;
	data.SetLabel(lab);
	data.SetNameFromKB();
	data.SetTypeFromKB();
	data.SetDateFromKB();
	data.SetVolumeFromKB();
	data.SetPictureFromKB();
	data.SetRoomID();
	data.SetDrawerID();
	data.SetContainerID();
	if (Master_List.UpdateObject(data)) {
		SimpleItemType simTemp;
		simTemp.SetRecordByItemType(data);
		if (Room_List.ObjectUpdate(simTemp)) {
			cout << "\t\t<Update Success>\n";
			return 1;
		}
	}
	return 0;
}

void Application::RunDisplay(){
	a_Command = GetDisplayCommand();

	switch (a_Command)
	{
	case 1:				
		DisplayAllObject();						//��� ���� ���
		break;
	case 2:					
		DisplayAllRoomItem();					//��� �� ���� ���
		break;
	case 3:		
		DisplayAllDrawerItem();					//��� Drawer���� ���
		break;
	case 4:		
		DisplayAllContainerItem();				//��� Container���� ���
		break;
	case 5:		
		DisplayBestList();						//���� ���� �˻��� ���� ����Ʈ ���
		break;
	case 6:		
		DisplayRecentList();					//�ֱ� �˻� List ���
		break;
	case 7:
		DisplayAllTemp();
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::RunSearching(){
	a_Command = GetSearchingCommand();

	switch (a_Command)
	{
	case 1:
		MasterRetrieveObject();					//������ ID�� �˻�
		break;
	case 2:
		MasterRetrieveObjectByName();			//������ �̸����� �˻�
		break;
	case 3:
		MasterRetrieveObjectByUsage();			//������ �뵵�� �˻�
		break;
	case 4:
		MasterRetrieveObjectByBuyDate();		//������ ���� �ñ�� �˻�
		break;
	case 5:
		RoomSearch();							//�� �˻�
		break;
	case 6:
		DrawerSearch();							//Drawer�˻�
		break;
	case 7:
		ContainerSearch();						//Container�˻�
		break;
	case 8:
		TempRetrieveObject();					//���� �������� ���� ���� List �˻�
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::RunSetting(){
	a_Command = GetSettingCommand();

	switch (a_Command)
	{
	case 1:
		RoomSet();					//�� ��������
		break;
	case 2:
		DrawerSet();				//Drawer ���� ����
		break;
	case 3:
		ContainerSet();				//Container ���� ����
		break;
	case 4:
		TempSet();					//TempList���� ����
		break;
	case 5:
		WriteDataToFile();			//���Ϸ� ������ ��������
		break;
	case 6:
		ReadDataFromFile();			//���Ϸκ��� ������ �б�
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::RoomSet() {
	a_Command = GetRoomCommand();

	switch (a_Command)
	{
	case 1:
		RoomAdd();
		break;
	case 2:
		RoomUpdate();
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::DrawerSet() {
	a_Command = GetDrawerCommand();

	switch (a_Command)
	{
	case 1:
		DrawerAdd();
		break;
	case 2:
		DrawerDelete();
		break;
	case 3:
		DrawerUpdate();
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::ContainerSet() {
	a_Command = GetContainerCommand();

	switch (a_Command)
	{
	case 1:
		ContainerAdd();
		break;
	case 2:
		ContainerDelete();
		break;
	case 3:
		ContainerUpdate();
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::TempSet() {
	a_Command = GetTempCommand();

	switch (a_Command)
	{
	case 1:
		AllocateObject();
		break;
	case 2:
		TempAddObject();
		break;
	case 3:
		TempDeleteObject();
		break;
	case 4:
		TempUpdateObject();
		break;
	case 0:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

int Application::GetCommand(){
	cout << '\n' <<setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### Select ######\n";
	cout << "\t1 : ���� �߰�\n";
	cout << "\t2 : ���� ����\n";
	cout << "\t3 : ���� ����\n";
	cout << "\t4 : ���� ��� ���\n";
	cout << "\t5 : ���� ã�� ���\n";
	cout << "\t6 : ���� ��� ���� ���\n";
	cout << "\t0 : Quit\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetDisplayCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ���� ��� ######\n";
	cout << "\t1 : ��� ���� ���\n";
	cout << "\t2 : �� ���� ���\n";
	cout << "\t3 : ������ ���� ���\n";
	cout << "\t4 : ���� ���� ���\n";
	cout << "\t5 : ���� ���� �˻��� ���� ���\n";
	cout << "\t6 : �ֱٿ� �˻��� ���� ���\n";
	cout << "\t7 : ���� �ȵ� ���� ���\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetSearchingCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ���� ã�� ######\n";
	cout << "\t1 : ID�� ���� ã��\n";
	cout << "\t2 : �̸����� ���� ã��\n";
	cout << "\t3 : �뵵�� ���� ã��\n";
	cout << "\t4 : ���� �⵵�� ���� ã��\n";
	cout << "\t5 : �� ã��\n";
	cout << "\t6 : ������ ã��\n";
	cout << "\t7 : ���� ã��\n";
	cout << "\t8 : �������� ���� ���� ã��\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetSettingCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ��� ���� ######\n";
	cout << "\t1 : �� ����\n";
	cout << "\t2 : ������ ����\n";
	cout << "\t3 : ���� ����\n";
	cout << "\t4 : �������� ���� ���� ����\n";
	cout << "\t5 : ���Ͽ� ���� ���� ����\n";
	cout << "\t6 : ���Ϸκ��� ���� ���� �޾ƿ���\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetRoomCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t######  �� ����  ######\n";
	cout << "\t1 : �� �߰�\n";
	cout << "\t2 : �� ���� ����\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetDrawerCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ������ ���� ######\n";
	cout << "\t1 : ������ �߰�\n";
	cout << "\t2 : ������ ����\n";
	cout << "\t3 : ������ ���� ����\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetContainerCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ���� ���� ######\n";
	cout << "\t1 : ���� �߰�\n";
	cout << "\t2 : ���� ����\n";
	cout << "\t3 : ���� ���� ����\n";
	cout << "\t4 : ���� ���� �߰�\n";
	cout << "\t5 : ���� ���� ����\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetItemCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t######  ���� ����  ######\n";
	cout << "\t2 : ���� ����\n";
	cout << "\t3 : ���� ���� ����\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetTempCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### ���� ���� ######\n";
	cout << "\t1 : ���� ��ҿ� ���� �߰�\n";
	cout << "\t2 : ���� �߰�\n";
	cout << "\t3 : ���� ����\n";
	cout << "\t4 : ���� ����\n";
	cout << "\t0 : ���ư���\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}


void Application::DisplayAllObject(){

	cout << "\t###### ���� ��� ######\n\n";
	Master_List.DisplayAllObject();
}
void Application::DisplayAllRoomItem(){
	cout << "\t######  �� ���  ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllRoomInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayAllDrawerItem(){
	cout << "\t###### ������ ��� ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllDrawerInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayAllContainerItem(){
	cout << "\t###### ���� ��� ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllContainerInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayBestList(){
	cout << "\t###### ���� ��� ######\n\n";
	Best_List.DisplayAllItem();
}
void Application::DisplayRecentList(){
	cout << "\t## �ֱ� �˻� ���� ��� ##\n\n";
	cout << "�ֱ� �˻� ���� ����: ";
	int num;
	cin >> num;
	Recent_List.DisplayItem(num);
	cout << setfill('#') << setw(37) << "\n\n";

}
void Application::DisplayAllTemp(){
	cout << "####  �������� ���� ����  ####\n";
	Temp_List.DisplayAllItem();
}


int Application::MasterRetrieveObject(){
	cout << "\t###### ���� �˻� ######\n\n";
	ItemType data;
	cout << "(R: RoomID, SS: StorageID, CC: ContainerID, LL: Unique Label(10~99))\n";
	cout << "Label(RSSCCLL): ";
	int label;
	cin >> label;
	data.SetLabel(label);
	if (Master_List.GetObject(data)) {
		cout << setfill('#') << setw(37) << "\n\n";
		Recent_List.AddItem(data);								//�˻��� �����ϸ�, �ֱ� �˻� ����Ʈ�� �߰�
		return 1;
	}
	cout << "\t\t<No such Object found>\n";
	return 0;
}
int Application::MasterRetrieveObjectByName(){
	cout << "\t###### ���� �˻� ######\n\n";
	ItemType data;
	data.SetNameFromKB();
	if (Master_List.GetObjectByName(data)) {	
		cout << setfill('#') << setw(37) << "\n\n";
		return 1;
	}
	cout << "\t\t<No such Object found>\n";
	return 0;
}
int Application::MasterRetrieveObjectByUsage(){
	cout << "\t###### ���� �˻� ######\n\n";
	ItemType data;
	data.SetTypeFromKB();
	if (Master_List.GetObjectByUsage(data)) {
		cout << setfill('#') << setw(37) << "\n\n";
	return 1;
	}
	cout << "\t\t<No such Object found>\n";
	return 0;
}
int Application::MasterRetrieveObjectByBuyDate(){
	cout << "\t###### ���� �˻� ######\n\n";
	int start, finish;
	cout << "From: ";
	cin >> start;
	cout << "To: ";
	cin >> finish;
	if (Master_List.GetObjectByBuydate(start, finish)) {
		cout << setfill('#') << setw(37) << "\n\n";
		return 1;
	}
	cout << "\t\t<No such Object found>\n";
	return 0;
}
int Application::RoomSearch(){
	cout << "\t######  �� �˻�  ######\n\n";
	RoomType data;
	data.SetRoomIDfromKB();
	if (Room_List.RoomGet(data)) {
		data.DisplayInfo();
		data.DisplayAllDrawer();
		cout << setfill('#') << setw(37) << "\n\n";
	return 1;
	}
	
	cout << "\t\t<No such Room found>\n";
	return 0;
}
int Application::DrawerSearch(){
	cout << "\t##### ������ �˻� #####\n\n";
	DrawerType data;
	RoomType rodata;
	data.SetDrawerIDfromKB();
	rodata.SetRoomID(data.GetRoomID());
	if (Room_List.DrawerGet(rodata, data)) {					//�ش� Drawer�� Room drawer����, ������ Container, Object�� Display
		rodata.DisplayInfo();
		cout << "\t######   Drawer   ######\n\n";
		data.DisplayInfo();
		cout << "\t###### Container  ######\n\n";
		data.DisplayAllContainer();
		cout << setfill('#') << setw(37) << "\n\n";
		return 1;
	}
	cout << "\t\t<No such Room found>\n";
	return 0;
}
int Application::ContainerSearch(){
	cout << "\t###### ���� �˻� ######\n\n";
	ContainerType data;
	DrawerType drdata;
	RoomType rodata;
	data.SetContainerIDfromKB();
	rodata.SetRoomID(data.GetRoomID());
	drdata.SetDrawerID(data.GetDrawerID());
	Room_List.ResetList();
	if (Room_List.ContainerGet(rodata, drdata, data)) {		//�ش� Drawer�� Room, drawer, Container����, ������ Object�� Display
		rodata.DisplayInfo();
		cout << "\t######   Drawer   ######\n\n";
		drdata.DisplayInfo();
		cout << "\t######  Container ######\n\n";
		data.DisplayContainer();
		cout << "\t######   Object   ######\n\n";
		data.DisplayAllItem();
		cout << setfill('#') << setw(37) << "\n\n";
		return 1;
	}
	cout << "\t\t<No such Room found>\n";
	return 0;
}
int Application::TempRetrieveObject(){
	cout << "\t###### ���� �˻� ######\n\n";
	ItemType data;
	data.SetTempLabelFromKB();
	if (Temp_List.Get(data)) {
		data.DisplayLabelOnScreen();
		data.DisplayNameOnScreen();
		data.DisplayTypeOnScreen();
		data.DisplayDateOnScreen();
		data.DisplayVolumeOnScreen();
	}
	return 0;
}


void Application::RoomAdd(){
	cout << "\t######  �� �߰�  ######\n\n";
	RoomType data;
	data.SetRoomIDfromKB();
	data.SetRoomNamefromKB();
	if (Room_List.RoomAdd(data)) {
		cout << "\t\t<Add Success>\n";
	}
	else {
		cout << "\t\t<Add Failed>\n";
	}
}

void Application::RoomUpdate(){
	cout << "\t######  �� ����  ######\n\n";
	RoomType data;
	data.SetRoomIDfromKB();
	data.SetRoomNamefromKB();
	if (Room_List.RoomUpdate(data)) {
		cout << "\t\t<Update Success>\n";
	}
	else {
		cout << "\t\t<Update Failed>\n";
	}
}

void Application::DrawerAdd(){
	cout << "\t######������ �߰�######\n\n";
	DrawerType data;
	data.SetDrawerIDfromKB();
	data.SetDrawerNamefromKB();
	data.SetDrawerTypefromKB();
	if (Room_List.DrawerAdd(data)) {
		cout << "\t\t<Add Success>\n";
	}
	else {
		cout << "\t\t<Add Failed>\n";
	}
}
void Application::DrawerDelete(){
	cout << "\t###### ������ ���� ######\n\n";
	DrawerType data;
	data.SetDrawerIDfromKB();
	if (Room_List.DrawerDelete(data)) {
		cout << "\t\t<Delete Success>\n";
	}
	else {
		cout << "\t\t<Delete Failed>\n";
	}
}
void Application::DrawerUpdate(){
	cout << "\t###### ������ ���� ######\n\n";
	DrawerType data;
	data.SetDrawerIDfromKB();
	Room_List.ResetList();
	if (Room_List.DrawerUpdate(data)) {
		cout << "\t\t<Update Success>\n";
	}
	else {
		cout << "\t\t<Update Failed>\n";
	}
}

void Application::ContainerAdd(){
	ContainerType data;
	data.SetContainerRecordfromKB();
	if (Room_List.ContainerAdd(data)) {
		cout << "\t\t<Add Success>\n";
	}
	else {
		cout << "\t\t<Add Failed>\n";
	}
}
void Application::ContainerDelete(){
	ContainerType data;
	data.SetContainerIDfromKB();
	if (Room_List.ContainerDelete(data)) {
		cout << "\t\t<Delete Success>\n";
	}
	else {
		cout << "\t\t<Delete Failed>\n";
	}
}
void Application::ContainerUpdate(){
	ContainerType data;
	data.SetContainerRecordfromKB();
	if (Room_List.ContainerAdd(data)) {
		cout << "\t\t<Update Success>\n";
	}
	else {
		cout << "\t\t<Update Failed>\n";
	}
}

int Application::AllocateObject(){
	ItemType data;
	data.SetTempfromKB();
	if (Temp_List.Get(data)) {
		do {
			cout << "### Allocate Location of Object ###\n";
			data.SetRoomIDFromKB();								//������ ��� ����
			data.SetDrawerIDFromKB();
			data.SetContainerIDFromKB();
			cout << "Set New Object ID\n";
			data.SetLabelFromKB();
		} while (Master_List.GetObject(data));
		if (Master_List.AddObject(data)) {
			Temp_List.Delete(data);
			cout << "\t\t<Allocate Success>\n";
			return 1;
		}
	}
	else {
		cout << "\t\t<No such Room found>\n";
		return 0;
	}
	cout << "\t\t<Allocate Failed>\n";
	return 0;
}
int Application::TempAddObject(){
	ItemType data;
	data.SetTempfromKB();
	if (Temp_List.Enqueue(data)) {
		cout << "\t\t<Add Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<Add Failed>\n";
	}
	return 0;
}
int Application::TempDeleteObject(){
	ItemType data;
	data.SetTempLabelFromKB();
	if (Temp_List.Delete(data)) {
		cout << "\t\t<Delete Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<Delete Failed>\n";
	}
	return 0;
}
int Application::TempUpdateObject(){
	ItemType data;
	data.SetTempfromKB();
	if (Temp_List.Replace(data)) {
		cout << "\t\t<Update Success>\n";
		return 1;
	}
	else {
		cout << "\t\t<Update Failed>\n";
	}
	return 0;
}

int Application::ReadDataFromFile(){
	if (Master_List.ReadDataFromFile()) {
		DisplayAllObject();
		return 1;
	}
	cout << "\t\t<Read Failed>\n";
	return 0;
}
int Application::WriteDataToFile(){
	if (Master_List.WriteDataToFile()) {
		cout << "\t\t<Write Success>\n";
		return 1;
	}
	cout << "\t\t<Write Failed>\n";
	return 0;
}