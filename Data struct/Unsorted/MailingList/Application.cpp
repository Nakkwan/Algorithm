#include "Application.h"

void Application::Run()
{
	while (1)
	{
		CommandUI();
		m_command = GetCommand();

		switch (m_command)
		{
		case 1:		// Get a mail from keyboard and add to list
			AddMail();
			break;
		case 2:		// display all the mail in list on screen.
			DisplayAllMail();
			break;
		case 3:		// delete all the mails in list.
			m_List.MakeEmpty();
			break;
		case 4:		// display mails in the given time interval
			FindNDispalyMail();
			break;
		case 5:		// delete mails in the given time interval
			DeleteMailsInTimeInterval();
			break;
		case 6:		// load list data from a file.
			//ReadDataFromFile();
			break;
		case 7:		// save list data into a file.
			//WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::CommandUI() {
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add mail" << endl;
	cout << "\t   2 : Print all mail on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search mail by time period" << endl;
	cout << "\t   5 : Delete mail by time period" << endl;
	cout << "\t   6 : Get from file" << endl;
	cout << "\t   7 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
}

int Application::GetCommand() {
	int command;
	cin >> command;
	return command;
}

void Application::AddMail() {
	ItemType data;
	cout << "\t\t< Add Mail>";
	cout << "\n\tEnter mail title: ";
	data.SetTitleFromKB();
	cout << "\n\tEnter mail sender: ";
	data.SetSenderFromKB();
	cout << "\n\tEnter mail label: ";
	data.SetLabelFromKB();
	cout << "\n\tEnter the time of received mail: ";
	data.SetTimeFromKB();
	cout << "\n\tEnter mail content: ";
	data.SetContentFromKB();
	m_List.Add(data);
}

void Application::DisplayAllMail() {
	ItemType temp;
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.ResetList();
		m_List.GetNextItem(temp);
		cout << '\t' << i << '.' << endl;
		temp.DisplayRecordOnScreen();
	}
	m_List.ResetList();
}

void Application::FindNDispalyMail() {
	ItemType start;
	ItemType finish;
	cout << "\tEnter the search start time: ";
	start.SetTimeFromKB();
	cout << "\tEnter the search finish time: ";
	finish.SetTimeFromKB();
	ItemType temp;
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.ResetList();
		m_List.GetNextItem(temp);
		if (temp.ComparedByTime(start) == LATER && temp.ComparedByTime(finish) == BEFORE) {
			temp.DisplayRecordOnScreen();
		}
	}
}

void Application::DeleteMailsInTimeInterval() {
	ItemType start;
	ItemType finish;
	cout << "\tEnter the delete start time: ";
	start.SetTimeFromKB();
	cout << "\tEnter the delete finish time: ";
	finish.SetTimeFromKB();
	ItemType temp;
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.ResetList();
		m_List.GetNextItem(temp);
		if (temp.ComparedByTime(start) == LATER && temp.ComparedByTime(finish) == BEFORE) {
			m_List.Delete(temp);
		}
	}
}

//void Application::ReadDataFromFile() {
//
//}
//
//void Application::WriteDataToFile() {
//
//}