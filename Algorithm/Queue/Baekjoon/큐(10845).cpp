#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node() {
		value = 0;
		next = nullptr;
	}

	Node(int val, Node* next1) {
		value = val;
		next = next1;
	}
};

class Queue {
private:
	int Q_size;
	Node* Q_front;
	Node* Q_rear;

public:
	Queue() {
		Q_front = nullptr;
		Q_rear = nullptr;
		Q_size = 0;
	}
	~Queue() {
		Node* temp = Q_front, * temp2;
		while (temp != nullptr) {
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	void push(int value) {
		if (Q_size == 0) {
			Q_rear = new Node(value, nullptr);
			Q_front = Q_rear;
			Q_size++;
		}
		else {
			Node* temp = Q_rear;
			Node* dest = new Node(value, nullptr);
			temp->next = dest;
			Q_rear = dest;
			Q_size++;
		}
	}

	int pop() {
		if (Q_size == 0) {
			return -1;
		}
		else if (Q_size == 1) {
			int count = Q_front->value;
			delete Q_front;
			Q_front = Q_rear = nullptr;
			Q_size--;
			return count;
		}
		else {
			int count = Q_front->value;
			Node* temp = Q_front->next;
			delete Q_front;
			Q_front = temp;
			Q_size--;
			return count;
		}
	}

	int size() {
		return Q_size;
	}

	int empty() {
		if (Q_size == 0) return 1;
		else return 0;
	}

	int front() {
		if (Q_size == 0) return -1;
		else return Q_front->value;
		
	}

	int back() {
		if (Q_size == 0) return -1;
		else return Q_rear->value;
	}
};


int main() {
	int N;
	int value;
	string camend;
	Queue Q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> camend;
		if (camend == "push") {
			cin >> value;
			Q.push(value);
		}
		else if (camend == "pop") {
			cout << Q.pop() << endl;
		}
		else if (camend == "size") {
			cout << Q.size() << endl;
		}
		else if (camend == "empty") {
			cout << Q.empty() << endl;
		}
		else if (camend == "front") {
			cout << Q.front() << endl;
		}
		else if (camend == "back") {
			cout << Q.back() << endl;
		}
	}


	return 0;
}