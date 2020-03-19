#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ItemType {
public:
	/*
	Constructure
	*/
	ItemType() {// default constructor
		mail_title = "";
		mail_sender_address = "";
		label = "";
	}
	/*
	Destructure
	*/
	~ItemType() {} 
	/*
	pre: setTitle
	post: return title of mail
	*/
	string GetTitle();

	/*
	pre: setSender
	post: return Sender of mail
	*/
	string GetSender(); 

	/*
	pre: setLabel
	post: return Label of mail
	*/
	string GetLabel(); 

	/*
	pre: assign string of title
	post: set Title
	*/
	void SetTitle(string inTitle); 

	/*
	pre: assign string od Sender
	post: set Sender
	*/
	void SetSender(string inSender); 

	/*
	pre: Assign string of label
	post: Set Label
	*/
	void SetLabel(string inLabel);

	/*
	pre: get time from system
	post: Set time
	*/
	void SetTime();

	/*
	pre: assign string of title, sender, label and content from Keyboard
	post: set mail variables
	*/
	void SetMail(string inTitle, string inSender, string inLabel); 

	/*
	pre: title is already set
	post: display title on console
	*/
	void DisplayTitleOnScreen(); 

	/*
	pre: Sender is already set
	post: display Sender on console
	*/
	void DisplaySenderOnScreen(); 

	/*
	pre: Content is already set
	post: display Conetnt on console
	*/
	void DisplayContentOnScreen();

	/*
	pre: mail is already set
	post: display information about mail on console
	*/
	void DisplayRecordOnScreen(); 

	/*
	pre: get title form keyboard
	post: set title
	*/
	void SetTitleFromKB();

	/*
	pre: get sender form keyboard
	post: set sender
	*/
	void SetSenderFromKB(); 

	/*
	pre: get label form keyboard
	post: set label
	*/
	void SetLabelFromKB(); 

	/*
	pre: get content form keyboard
	post: set content
	*/
	void SetContentFromKB(); 

	/*
	pre: get time form keyboard
	post: set time
	*/
	void SetTimeFromKB();

	/*
	pre: Assign file
	post: Read data about mail information from file
	*/
	int ReadDataFromFile(std::ifstream& fin);

	/*
	pre: Assign file
	post: Write data about mail information to file
	*/
	int WriteDataToFile(std::ofstream& fout); 

private:
	string mail_title; // 메일 제목
	string mail_sender_address;		// 보내는 사람 메일 주소
	string label;		// label 명
	char mail_content[256];
	char mail_gettime[16];
};

#endif
