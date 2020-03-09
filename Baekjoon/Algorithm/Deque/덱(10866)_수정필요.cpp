#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int value;
	Node* next;		
	Node* before;	

	Node() {
		value = 0;
		next = nullptr;
		before = nullptr;
	}

	Node(int val, Node* next1, Node* before1) {
		value = val;
		next = next1;
		before = before1;
	}
};

class Deque {
private:
	int D_size;
	Node* D_front;
	Node* D_rear;

public:
	Deque() {
		D_front = nullptr;
		D_rear = nullptr;
		D_size = 0;
	}
	~Deque() {
		Node* temp = D_front, * temp2;
		while (temp != nullptr) {
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	void push_front(int value) {
		if (D_size == 0) {
			D_front = new Node(value, nullptr, nullptr);
			D_rear = D_front;
			D_size++;
		}
		else {
			Node* temp = D_front;
			Node* dest = new Node(value, D_front, nullptr);
			temp->before = dest;
			D_front = dest;
			D_size++;
		}
	}

	void push_back(int value) {
		if (D_size == 0) {
			D_rear = new Node(value, nullptr, nullptr);
			D_front = D_rear;
			D_size++;
		}
		else {
			Node* temp = D_rear;
			Node* dest = new Node(value, nullptr, temp);
			temp->next = dest;
			D_rear = dest;
			D_size++;
		}
	}

	int pop_front() {
		if (D_size == 0) {
			return -1;
		}
		else if (D_size == 1) {
			int count = D_front->value;
			delete D_front;
			D_front = D_rear = nullptr;
			D_size--;
			return count;
		}
		else {
			int count = D_front->value;
			Node* temp = D_front->next;
			delete D_front;
			temp->before = nullptr;
			D_front = temp;
			D_size--;
			return count;
		}
	}

	int pop_back() {
		if (D_size == 0) {
			return -1;
		}
		else if (D_size == 1) {
			int count = D_rear->value;
			delete D_rear;
			D_rear = D_front = nullptr;
			D_size--;
			return count;
		}
		else {
			int count = D_rear->value;
			Node* temp = D_rear->before;
			delete D_rear;
			temp->next = nullptr;
			D_rear = temp;
			D_size--;
			return count;
		}
	}

	int size() {
		return D_size;
	}

	int empty() {
		if (D_size == 0) return 1;
		else return 0;
	}

	int front() {
		if (D_size == 0) return -1;
		else return D_front->value;
		
	}

	int back() {
		if (D_size == 0) return -1;
		else return D_rear->value;
	}
};


int main() {
	int N;
	int value;
	string camend;
	Deque D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> camend;
		if (camend == "push_front") {
			cin >> value;
			D.push_front(value);
		}
		else if (camend == "push_back") {
			cin >> value;
			D.push_back(value);
		}
		else if (camend == "pop_front") {
			cout << D.pop_front() << endl;
		}
		else if (camend == "pop_back") {
			cout << D.pop_back() << endl;
		}
		else if (camend == "size") {
			cout << D.size() << endl;
		}
		else if (camend == "empty") {
			cout << D.empty() << endl;
		}
		else if (camend == "front") {
			cout << D.front() << endl;
		}
		else if (camend == "back") {
			cout << D.back() << endl;
		}
	}


	return 0;
}