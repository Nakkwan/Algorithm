#include "pch.h"
#include "SimpleItemType.h"

SimpleItemType::SimpleItemType() {
	S_label = 0;
	S_name = "";
	S_type = "";
}

SimpleItemType::SimpleItemType(int inlabel) {
	S_label = inlabel;
	S_name = "";
	S_type = "";
}

int SimpleItemType::getLabel() const {
	return S_label;
}

int SimpleItemType::GetRoomID() {
	return S_label / 1000000;
}

int SimpleItemType::GetDrawerID() {
	return (S_label / 10000) % 100;
}

int SimpleItemType::GetContainerID() {
	return (S_label / 100) % 100;
}

string SimpleItemType::getName() const {
	return S_name;
}

string SimpleItemType::getType() const {
	return S_type;
}

void SimpleItemType::setLabel(int inlabel) {
	S_label = inlabel;
}

void SimpleItemType::setName(string inname) {
	S_name = inname;
}

void SimpleItemType::setType(string intype) {
	S_type = intype;
}

void SimpleItemType::setRecord(int inlabel, string inname, string intype) {
	S_label = inlabel;
	S_name = inname;
	S_type = intype;
}

void SimpleItemType::SetRecordByItemType(const ItemType& data) {
	S_label = data.GetLabel();
	S_name = data.GetName();
	S_type = data.GetType();
}

void SimpleItemType::DisplayItem() {
	std::cout << "Object Label: " << S_label << '\n';
	std::cout << "Object Name: " << S_name << '\n';
	std::cout << "Object Type: " << S_type << '\n';
}