#include "pch.h"
#include "Employee.h"

int Employee::GetAge() const{
	return E_age;
}
int Employee::GetSkill() const{
	return E_skill;
}
int Employee::GetMoney() const{
	return E_money;
}
int Employee::GetRank() const{
	return E_rank;
}
string Employee::GetNumber() const{
	return E_number;
}
string Employee::GetName() const{
	return E_name;
}
int Employee::GetPrefer() const {
	return E_prefer;
}

void Employee::SetAge(int inage){
	E_age = inage;
}
void Employee::SetSkill(int inskill){
	E_skill - inskill;
}
void Employee::SetMoney(int inmoney){
	E_money = inmoney;
}
void Employee::SetRank(int inrank){
	E_rank = inrank;
}
void Employee::SetNumber(string innumber){
	E_number = innumber;
}
void Employee::SetName(string inname){
	E_name = inname;
}
void Employee::SetPrefer(int inprefer) {
	E_prefer = inprefer;
}

void Employee::SetAgeFromKB(){
	cout << "����: ";
	cin >> E_age;
}
void Employee::SetSkillFromKB() {
	do {
		cout << "���õ�(1:����, 2:��, 3:��, 4:��, 5:�ֻ�): ";
		cin >> E_skill;
		if (E_skill > 5 || E_skill < 1) {
			cout << "Out_of_Range!\n";
			continue;
		}
		break;
	} while (1);
}
void Employee::SetMoneyFromKB(){
	cout << "��� �ϴ�: ";
	cin >> E_money;
}
void Employee::SetNumberFromKB(){
	cout << "��ȭ��ȣ(-����): ";
	cin >> E_number;
}
void Employee::SetNameFromKB(){
	cout << "�̸�: ";
	cin >> E_name;
}

void Employee::SetPreferFromKB() {
	do {
		cout << "1.����, 2.����, 3.�輱, 4.Ư������, 5.��Ÿ, 6.����\n";
		cout << "��� ����: ";
		cin >> E_prefer;
		if (E_prefer < 7 && E_prefer > 0) {
			break;
		}
		cout << "Out_of_Range!\n";
	} while (1);
}


void Employee::SetRecordFromKB() {
	SetNameFromKB();
	SetAgeFromKB();
	SetNumberFromKB();
	SetSkillFromKB();
	SetMoneyFromKB();
	SetPreferFromKB();
}


int Employee::ReadDataFromFile(ifstream& fin) {
	if (fin.is_open()) {
		fin >> E_name;
		fin >> E_age;
		fin >> E_number;
		fin >> E_skill;
		fin >> E_money;
		fin >> E_prefer;
		return 1;
	}
	return 0;
}

int Employee::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << E_name << ' ';
		fout << E_age<< ' ';
		fout << E_number << ' ';
		fout << E_skill << ' ';
		fout << E_money << ' ';
		fout << E_prefer << '\n';
		return 1;
	}
	return 0;
}

void Employee::DisplayOnScreen() {
	cout << "�̸�: " << E_name << endl;
	cout << "����: " << E_age << endl;
	cout << "��ȭ��ȣ: " << E_number << endl;
	cout << "���õ�: " << E_skill << endl;
	cout << "��� �ݾ�: " << E_money << endl;
	cout << "���� �о�: " << E_prefer << endl;
	cout << "��� ����: " << E_rank << endl;
}