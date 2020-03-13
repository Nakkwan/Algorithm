#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>

enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType(); 
	~ItemType(); 
	int GetId(); 
	std::string GetName();
	std::string GetAddress(); 
	void SetId(int inId); 
	void SetName(std::string inName); 
	void SetAddress(std::string inAddress); 
	void SetRecord(int inId, std::string inName, std::string inAddress); 
	void DisplayIdOnScreen();
	void DisplayNameOnScreen(); 
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen(); 
	void SetIdFromKB(); 
	void SetNameFromKB(); 
	void SetAddressFromKB(); 
	void SetRecordFromKB(); 
	int ReadDataFromFile(std::ifstream& fin); 
	int WriteDataToFile(std::ofstream& fout); 
	RelationType CompareByID(ItemType data);

private:
	int m_Id;
	std::string m_sName; 
	std::string m_sAddress;


};

#endif
