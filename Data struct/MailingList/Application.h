#ifndef APPLICATION_H
#define APPLICATION_H

#include "SortedListType.h"

class Application {
private:
	int m_command;
	SortedListType m_List;
public:
	Application() {
		m_command = 0;
	}
	~Application() {}
	void CommandUI();
	int GetCommand();
	void Run();
	void AddMail();
	void DisplayAllMail();
	void FindNDispalyMail();
	void DeleteMailsInTimeInterval();
	//void ReadDataFromFile();
	//void WriteDataToFile();
};

#endif // !APPLICATION_H
