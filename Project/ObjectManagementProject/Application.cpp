#include "pch.h"
#include "Application.h"


void Application::Run(){
	while (1) {
		a_Command = GetCommand();
		switch (a_Command)
		{
		case 1:
			MasterAddObject();						//물건 추가
			break;
		case 2:
			MasterDeleteObject();					//물건 삭제
			break;
		case 3:
			MasterUpdateObject();					//물건 수정
			break;
		case 4:
			RunDisplay();							//출력 관련 함수
			break;
		case 5:
			RunSearching();							//검색 관련 함수
			break;
		case 6:
			RunSetting();							//보관 환경 관련 함수
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
	cout << "\t###### 물건 추가 ######\n";
	cout << "\t###### 물건 정보 ######\n";
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
	cout << "\t###### 물건 삭제 ######\n";
	cout << "\t###### 물건  ID  ######\n";
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
	cout << "\t###### 물건 갱신 ######\n";
	cout << "\t###### 물건 정보 ######\n";
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
		DisplayAllObject();						//모든 물건 출력
		break;
	case 2:					
		DisplayAllRoomItem();					//모든 방 정보 출력
		break;
	case 3:		
		DisplayAllDrawerItem();					//모든 Drawer정보 출력
		break;
	case 4:		
		DisplayAllContainerItem();				//모든 Container정보 출력
		break;
	case 5:		
		DisplayBestList();						//가장 많이 검색된 물건 리스트 출력
		break;
	case 6:		
		DisplayRecentList();					//최근 검색 List 출력
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
		MasterRetrieveObject();					//물건을 ID로 검색
		break;
	case 2:
		MasterRetrieveObjectByName();			//물건을 이름으로 검색
		break;
	case 3:
		MasterRetrieveObjectByUsage();			//물건을 용도로 검색
		break;
	case 4:
		MasterRetrieveObjectByBuyDate();		//물건을 구매 시기로 검색
		break;
	case 5:
		RoomSearch();							//방 검색
		break;
	case 6:
		DrawerSearch();							//Drawer검색
		break;
	case 7:
		ContainerSearch();						//Container검색
		break;
	case 8:
		TempRetrieveObject();					//아직 보관되지 않은 물건 List 검색
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
		RoomSet();					//방 설정관련
		break;
	case 2:
		DrawerSet();				//Drawer 설정 관련
		break;
	case 3:
		ContainerSet();				//Container 설정 관련
		break;
	case 4:
		TempSet();					//TempList설정 관련
		break;
	case 5:
		WriteDataToFile();			//파일로 데이터 내보내기
		break;
	case 6:
		ReadDataFromFile();			//파일로부터 데이터 읽기
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
	cout << "\t1 : 물건 추가\n";
	cout << "\t2 : 물건 삭제\n";
	cout << "\t3 : 물건 갱신\n";
	cout << "\t4 : 정보 출력 기능\n";
	cout << "\t5 : 정보 찾기 기능\n";
	cout << "\t6 : 보관 장소 설정 기능\n";
	cout << "\t0 : Quit\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetDisplayCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 정보 출력 ######\n";
	cout << "\t1 : 모든 물건 출력\n";
	cout << "\t2 : 방 정보 출력\n";
	cout << "\t3 : 수납장 정보 출력\n";
	cout << "\t4 : 상자 정보 출력\n";
	cout << "\t5 : 가장 많이 검색한 물건 출력\n";
	cout << "\t6 : 최근에 검색한 물건 출력\n";
	cout << "\t7 : 보관 안된 물건 출력\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetSearchingCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 물건 찾기 ######\n";
	cout << "\t1 : ID로 물건 찾기\n";
	cout << "\t2 : 이름으로 물건 찾기\n";
	cout << "\t3 : 용도로 물건 찾기\n";
	cout << "\t4 : 구매 년도로 물건 찾기\n";
	cout << "\t5 : 방 찾기\n";
	cout << "\t6 : 수납장 찾기\n";
	cout << "\t7 : 상자 찾기\n";
	cout << "\t8 : 보관되지 않은 물건 찾기\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetSettingCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 장소 설정 ######\n";
	cout << "\t1 : 방 설정\n";
	cout << "\t2 : 수납장 설정\n";
	cout << "\t3 : 상자 설정\n";
	cout << "\t4 : 보관되지 않은 물건 설정\n";
	cout << "\t5 : 파일에 물건 정보 쓰기\n";
	cout << "\t6 : 파일로부터 물건 정보 받아오기\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetRoomCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t######  방 설정  ######\n";
	cout << "\t1 : 방 추가\n";
	cout << "\t2 : 방 정보 갱신\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetDrawerCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 수납장 설정 ######\n";
	cout << "\t1 : 수납장 추가\n";
	cout << "\t2 : 수납장 삭제\n";
	cout << "\t3 : 수납장 정보 갱신\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetContainerCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 상자 설정 ######\n";
	cout << "\t1 : 상자 추가\n";
	cout << "\t2 : 상자 삭제\n";
	cout << "\t3 : 상자 정보 갱신\n";
	cout << "\t4 : 상자 사진 추가\n";
	cout << "\t5 : 상자 사진 삭제\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetItemCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t######  물건 설정  ######\n";
	cout << "\t2 : 물건 삭제\n";
	cout << "\t3 : 물건 정보 갱신\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}
int Application::GetTempCommand(){
	cout << '\n' << setfill('#') << setw(36) << '\n';
	cout << "######## Object Management ########\n";
	cout << setfill('#') << setw(37) << "\n\n";
	cout << "\t###### 보관 설정 ######\n";
	cout << "\t1 : 보관 장소에 물건 추가\n";
	cout << "\t2 : 물건 추가\n";
	cout << "\t3 : 물건 삭제\n";
	cout << "\t4 : 물건 갱신\n";
	cout << "\t0 : 돌아가기\n";
	cout << "\tEnter Command -> ";

	cin >> a_Command;

	return a_Command;
}


void Application::DisplayAllObject(){

	cout << "\t###### 물건 목록 ######\n\n";
	Master_List.DisplayAllObject();
}
void Application::DisplayAllRoomItem(){
	cout << "\t######  방 목록  ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllRoomInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayAllDrawerItem(){
	cout << "\t###### 수납장 목록 ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllDrawerInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayAllContainerItem(){
	cout << "\t###### 상자 목록 ######\n\n";
	Room_List.ResetList();
	if (!Room_List.DisplayAllContainerInfo()) {
		cout << "###### List is Empty ######\n";
		cout << setfill('#') << setw(37) << "\n\n";
	}
}
void Application::DisplayBestList(){
	cout << "\t###### 물건 목록 ######\n\n";
	Best_List.DisplayAllItem();
}
void Application::DisplayRecentList(){
	cout << "\t## 최근 검색 물건 목록 ##\n\n";
	cout << "최근 검색 물건 개수: ";
	int num;
	cin >> num;
	Recent_List.DisplayItem(num);
	cout << setfill('#') << setw(37) << "\n\n";

}
void Application::DisplayAllTemp(){
	cout << "####  보관되지 않은 물건  ####\n";
	Temp_List.DisplayAllItem();
}


int Application::MasterRetrieveObject(){
	cout << "\t###### 물건 검색 ######\n\n";
	ItemType data;
	cout << "(R: RoomID, SS: StorageID, CC: ContainerID, LL: Unique Label(10~99))\n";
	cout << "Label(RSSCCLL): ";
	int label;
	cin >> label;
	data.SetLabel(label);
	if (Master_List.GetObject(data)) {
		cout << setfill('#') << setw(37) << "\n\n";
		Recent_List.AddItem(data);								//검색에 성공하면, 최근 검색 리스트에 추가
		return 1;
	}
	cout << "\t\t<No such Object found>\n";
	return 0;
}
int Application::MasterRetrieveObjectByName(){
	cout << "\t###### 물건 검색 ######\n\n";
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
	cout << "\t###### 물건 검색 ######\n\n";
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
	cout << "\t###### 물건 검색 ######\n\n";
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
	cout << "\t######  방 검색  ######\n\n";
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
	cout << "\t##### 서랍장 검색 #####\n\n";
	DrawerType data;
	RoomType rodata;
	data.SetDrawerIDfromKB();
	rodata.SetRoomID(data.GetRoomID());
	if (Room_List.DrawerGet(rodata, data)) {					//해당 Drawer의 Room drawer정보, 포함한 Container, Object를 Display
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
	cout << "\t###### 상자 검색 ######\n\n";
	ContainerType data;
	DrawerType drdata;
	RoomType rodata;
	data.SetContainerIDfromKB();
	rodata.SetRoomID(data.GetRoomID());
	drdata.SetDrawerID(data.GetDrawerID());
	Room_List.ResetList();
	if (Room_List.ContainerGet(rodata, drdata, data)) {		//해당 Drawer의 Room, drawer, Container정보, 포함한 Object를 Display
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
	cout << "\t###### 물건 검색 ######\n\n";
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
	cout << "\t######  방 추가  ######\n\n";
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
	cout << "\t######  방 갱신  ######\n\n";
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
	cout << "\t######수납장 추가######\n\n";
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
	cout << "\t###### 수납장 삭제 ######\n\n";
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
	cout << "\t###### 수납장 갱신 ######\n\n";
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
			data.SetRoomIDFromKB();								//보관할 장소 설정
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