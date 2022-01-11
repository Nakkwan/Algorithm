#include <iostream>
#include <string>
using namespace std;

/*Node class for element of stack*/
class Node {
public:
	int value;
	Node* next;

	Node() {
		value = 0;
		next = nullptr;
	}
	Node(int value1, Node* next1) {
		value = value1;
		next = next1;
	}
};


class Stack {
public:
	Node* S_top;
	int S_size;

	Stack() {
		this->S_top = nullptr;
		S_size = 0;
	}
	~Stack() {
		Node* dest = S_top, * temp;
		while (dest != nullptr) {
			temp = dest->next;
			delete dest;
			dest = temp;
		}
	}

	/*add element of stack on top*/
	void push(int value) {
		if (S_size == 0) {
			Node* tem = new Node(value, nullptr);
			S_top = tem;
			S_size++;
		}
		else {
			S_top = new Node(value, S_top);
			S_size++;
		}
	}

	/*erase element of stack on top*/
	int pop() {
		if (S_size == 0) {
			return -1;
		}
		else if (S_size == 1) {
			int count = S_top->value;
			delete S_top;
			S_top = nullptr;
			S_size--;
			return count;
		}
		else {
			int count = S_top->value;
			Node* temp = S_top->next;
			delete S_top;
			S_top = temp;
			S_size--;
			return count;
		}
	}

	/*size of stack*/
	int Size() {
		return S_size;
	}

	/*Indicates whether it is empty */
	int empty() {
		if (S_size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	/*Print element of top of stack*/
	int top() {
		if (S_size == 0) {
			return -1;
		}
		else {
			return S_top->value;
		}
	}
};


int main() {
	int N;
	int value;
	string camend;
	Stack S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> camend;
		if (camend == "push") {
			cin >> value;
			S.push(value);
		}
		else if (camend == "pop") {
			cout << S.pop() << endl;
		}
		else if (camend == "size") {
			cout << S.Size() << endl;
		}
		else if (camend == "empty") {
			cout << S.empty() << endl;
		}
		else if (camend == "top") {
			cout << S.top() << endl;
		}
	}


	return 0;
}