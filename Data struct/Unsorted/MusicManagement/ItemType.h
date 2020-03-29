#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum RelationType{ LESS, GREATER, EQUAL };

class ItemType {
public:
	ItemType() {			//constructor
		M_Name = "";
		M_Writer = "";
		M_Singer = "";
		single_label = -1;
		genre = -1;
	}
	~ItemType() {}			//destructor

	/*
	@brief: get music name
	@pre: set music name
	@post: none
	@return: music name
	*/
	string GetName() const;

	/*
	@brief: get music writer
	@pre: set writer
	@post: none
	@return: writer
	*/
	string GetWriter() const;

	/*
	@brief: get singer 
	@pre: set signer
	@post: none
	@return: signer
	*/
	string GetSinger() const;

	/*
	@brief: get unique label
	@pre: set unique label
	@post: none
	@return: label
	*/
	int GetLabel() const;

	/*
	@brief: get music genre
	@pre: set genre
	@post: none
	@return: genre
	*/
	int GetGenre() const;

	/*
	@brief: set music name
	@pre: none
	@post: assign music name
	@param: music name
	*/
	void SetName(string inName);

	/*
	@brief: set writer
	@pre: none
	@post: assign writer
	@param: writer
	*/
	void SetWriter(string inWriter);

	/*
	@brief: set singer
	@pre: none
	@post: assign singer
	@param: singer
	*/
	void SetSinger(string inSinger);

	/*
	@brief: set unique label
	@pre: none
	@post: assign unique label
	@param: label
	*/
	void SetLabel(int inLabel);

	/*
	@brief: set music genre
	@pre: none
	@post: assign genre
	@param: genre
	*/
	void SetGenre(int inGenre);

	/*
	@brief: set elememt of ItemType member value
	@pre: none
	@post: assign name, writer, singer, label, genre
	@param: _inName name, _inWriter writer, _inSinger singer, _inLabel label, _inGenre genre 
	*/
	void SetRecord(string inName, string inWriter, string inSinger, int inLabel, int inGenre);

	/*
	@brief: display name of ItemType on screen
	@pre: set name
	@post: display name
	*/
	void DisplayNameOnScreen();

	/*
	@brief: display writer of ItemType on screen
	@pre: set writer
	@post: display writer
	*/
	void DisplayWriterOnScreen();

	/*
	@brief: display singer of ItemType on screen
	@pre: set singer 
	@post: display singer 
	*/
	void DisplaySingerOnScreen();

	/*
	@brief: display label of ItemType on screen
	@pre: set label
	@post: display label
	*/
	void DisplayLabelOnScreen();

	/* 
	@brief: display genre of ItemType on screen
	@pre: set genre
	@post: display genre
	*/
	void DisplayGenreOnScreen();

	/*
	@brief: display member value of ItemType on screen
	@pre: set name, writer, singer, label, genre
	@post: display member value of ItemType
	*/
	void DisplayRecordOnScreen();

	/*
	@brief: set name of music receive input from keyboard
	@pre: none
	@post: assign name from the keyboard
	*/
	void SetNameFromKB();

	/*
	@brief: set writer receive input from keyboard
	@pre: none
	@post: assign writer from the keyboard
	*/
	void SetWriterFromKB();

	/*
	@brief: set singer receive input from keyboard
	@pre: none
	@post: assign singer from the keyboard
	*/
	void SetSingerFromKB();

	/*
	@brief: set label receive input from keyboard
	@pre: none
	@post: assign label from the keyboard
	*/
	void SetLabelFromKB();

	/*
	@brief: set genre receive input from keyboard
	@pre: none
	@post: assign genre from the keyboard
	*/
	void SetGenreFromKB();

	/* 
	@brief: set member value of ItemType receive input from keyboard
	@pre: none
	@post: assign member value from the keyboard
	*/
	void SetRecordFromKB();

	/*
	@brief: Read data from file
	@pre: have a file containing data
	@post: object set data from file
	@param: input file object
	@return: 0 read fail, 1 success
	*/
	int ReadDataFromFile(std::ifstream& fin);

	/*
	@brief: Write data from file
	@pre: set member value 
	@post: file include data
	@param: output file object
	@return: 0 write fail, 1 success
	*/
	int WriteDataToFile(std::ofstream& fout);

	/*
	@brief: Compare data by unique label
	@pre: set label of two object
	@post: none
	@param: data for comparing
	@return: return EQUAL if two label is same
			 return LESS if parameter label is bigger
			 return GREATER if parameter label is smaller
	*/
	RelationType CompareByLabel(const ItemType& data);

	/*
	@brief: Decide two ItemType is same
	@pre: set unique label of two object
	@post: none
	@param: ItemType to compare
	@return: if same, return 1 if differ, return 0
	*/
	bool operator==(const ItemType& data) {			//제너릭하게 프로그램을 구성하기 위해서 RelationType 대신 연산자 오버로딩
		if (single_label = data.GetLabel()) {
			return true;
		}
		else {
			return false;
		}
	}


	/*
	@brief: assign data
	@pre: set data to be changed
	@post: member value is replaced by parameter
	*/
	void operator=(const ItemType& data) {
		M_Name = data.GetName();
		M_Writer = data.GetWriter();
		M_Singer = data.GetSinger();
		single_label = data.GetLabel();
		genre = data.GetGenre();
	}

private:
	string M_Name; 
	string M_Writer;
	string M_Singer;
	int single_label;
	int genre;
};

#endif
