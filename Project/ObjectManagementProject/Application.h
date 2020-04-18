#pragma once
#include "Base.h"
#include <fstream>
using namespace std;

class Application : public Base {
private:
	ifstream m_inFile;
	ofstream m_outFile;
	int m_Command;
public:

};