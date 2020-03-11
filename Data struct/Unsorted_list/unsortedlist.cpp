#include "unsortedlist.h"
#include <iostream>

Unsortedlist::Unsortedlist(int size1) {
	size = size1;
	current = -1;
	data_length = 0;
	node = new int[size];
}

void Unsortedlist::Add(int val) {
	if (data_length < size) {
		node[data_length] = val;
		data_length++;
	}
	else {
		std::cout << "Error: List if full\n";
	}
}

void Unsortedlist::Delete(int val) {
	bool exist = false;
	for (int i = 0; i < data_length; i++) {
		if (node[i] == val) {
			node[i] == 0;
			for (int j = i; j < data_length; j++) {
				int temp = node[j];
				node[j] = node[j + 1];
				node[j + 1] = temp;
			}
			data_length--;
			node[data_length] = NULL;
			exist = true;
			break;
		}
	}
	if (exist == false) {
		std::cout << "Error: Value is not exist\n";
	}
}

void Unsortedlist::MakeEmpty() {
	if (data_length != 0) {
		for (int i = 0; i < data_length; i++) {
			node[i] = NULL;
		}
		data_length = 0;
	}
}

int Unsortedlist::Lengthls() {
	return data_length;
}

bool Unsortedlist::IsFull() {
	if (data_length == size) {
		return true;
	}
	else {
		return false;
	}
}

int Unsortedlist::GetNextItem() {
	current++;
	return node[current];
}

int Unsortedlist::RetrieveItem(int val) {
	for (int i = 0; i < data_length; i++) {
		if (val == GetNextItem()) {
			int index = current;
			current = -1;
			return index;
		}
	}
	current = -1;
	return current;
}

void Unsortedlist::Display() {
	if (data_length != 0) {
		for (int i = 0; i < data_length; i++) {
			std::cout << node[i] << ' ';
		}
		std::cout << '\n';
	}
	else {
		std::cout << "List is empty\n";
	}
}

void Unsortedlist::replace(int index, int value) {
	node[index] = value;
}