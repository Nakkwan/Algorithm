#include "ItemType.h"

string ItemType::GetTitle() {
	return mail_title;
}

string ItemType::GetSender() {
	return mail_sender_address;
}

string ItemType::GetLabel() {
	return mail_label;
}

char* ItemType::GetTime() {
	return mail_gettime;
}

char* ItemType::GetContent() {
	return mail_content;
}

int ItemType::GetContentLength() {
	return content_length;
}

void ItemType::SetTitle(string inTitle) {
	mail_title = inTitle;
}

void ItemType::SetSender(string inSender) {
	mail_sender_address = inSender;
}

void ItemType::SetLabel(string inLabel) {
	mail_label = inLabel;
}

void ItemType::SetTime(char* time) {
	for (int i = 0; i < 16; i++) {
		mail_gettime[i] = *time;
		time++;
	}
}

void ItemType::SetContent(char* content, int N) {
	for (int i = 0; i < N; i++) {
		mail_content[i] = *content;
		content++;
	}
}

void ItemType::SetMailinfo(string inTitle, string inSender, string inLabel, char* inTime, char* inContent) {
	SetTitle(inTitle);
	SetSender(inSender);
	SetLabel(inLabel);
	SetTime(inTime);
	SetContent(inContent, content_length);
}

void ItemType::SetMailinfoByItem(ItemType data) {
	SetTitle(data.GetTitle());
	SetSender(data.GetSender());
	SetLabel(data.GetLabel());
	SetTime(data.GetTime());
	SetContent(data.GetContent(), content_length);
}

void ItemType::DisplayTitleOnScreen() {
	cout << "\tTitle:" << GetTitle() << '\n';
}

void ItemType::DisplaySenderOnScreen() {
	cout << "\tSender: " << GetSender() << '\n';
}

void ItemType::DisplaylabelOnScreen() {
	cout << "\tLabel: " << GetLabel() << '\n';
}

void ItemType::DisplaytimeOnScreen() {
	cout << "\tTime: ";
	char* temp = GetTime();
	for (int i = 0; i < 16; i++) {
		cout << *(temp + i);
	}
	cout << '\n';
}
void ItemType::DisplayContentOnScreen() {
	cout << "\tContent: ";
	char* temp = GetContent();
	int count = 0;
	do {
		cout << *(temp + count);
		count++;
	} while (count < content_length);
}
void ItemType::DisplayRecordOnScreen() {
	DisplayTitleOnScreen();
	DisplaySenderOnScreen();
	DisplaylabelOnScreen();
	DisplaytimeOnScreen();
	DisplayContentOnScreen();
	cout << "\n";
}

void ItemType::SetTitleFromKB() {
	cin >> mail_title;
}
void ItemType::SetSenderFromKB() {
	cin >> mail_sender_address;
}
void ItemType::SetLabelFromKB() {
	cin >> mail_label;
}
void ItemType::SetContentFromKB() {
	string temp;
	getline(cin, temp);
	if (temp.length() >= 256) {
		content_length = 256;
	}
	else {
		content_length = temp.length();
	}
	for (int i = 0; i < content_length; i++) {
		mail_content[i] = temp.at(i);
	}
}

void ItemType::SetTimeFromKB() {
	char temp = '1';
	int count = 0;
	do {
		temp = getchar();
		if (temp != '\n') {
			mail_gettime[count] = temp;
			count++;
		}
	} while (count < 16 && temp != '\n');
	while (getchar() != '\n');
}

CompareTime ItemType::ComparedByTime(ItemType data) {
	int count = 0;
	char* para = data.GetTime();
	char* loc = this->GetTime();
	for (int i = 0; i < 16; i++) {
		if (*(para + count) > *(loc + count)) {
			return BEFORE;
		}
		else if (*(para + count) < *(loc + count)) {
			return LATER;
		}
		else {
			continue;
		}
	}
	return EQUAL;
}

//int ItemType::ReadDataFromFile(std::ifstream& fin) {
//
//}
//
//int ItemType::WriteDataToFile(std::ofstream& fout) {
//
//}