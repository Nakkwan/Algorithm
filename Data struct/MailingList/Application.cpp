#include "Application.h"

void Application::Run()
{
	while (1)
	{
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
			ReadDataFromFile();
			break;
		case 7:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cin >> command;
	return command;
}

void Application::AddMail() {

}

void Application::DisplayAllMail() {

}

void Application::FindNDispalyMail() {

}
void Application::DeleteMailsInTimeInterval() {

}

void Application::ReadDataFromFile() {

}

void Application::WriteDataToFile() {

}