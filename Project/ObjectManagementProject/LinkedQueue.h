#ifndef __LINKEDQUEUE_H
#define __LINKEDQUEUE_H


#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
public:
	T value;
	Node<T>* next;

	Node() {
		next = nullptr;
	}

	Node(int val, Node<T>* next1) {
		value = val;
		next = next1;
	}
};

template <typename T>
class LinkedQueue {
private:
	int Q_size;
	Node<T>* Q_front;
	Node<T>* Q_rear;

public:
	LinkedQueue() {
		Q_front = nullptr;
		Q_rear = nullptr;
		Q_size = 0;
	}
	~LinkedQueue() {
		Node<T>* temp = Q_front, * temp2;
		while (temp != nullptr) {
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	/*
	@brief: Queue�� ������ �߰�
	@pre: none
	@post: Queue�� �����Ͱ� �߰���
	*/
	void push(int value);

	/*
	@brief: Queue���� ���� �� ���� �� ��ȯ
	@pre: Queue is not empty
	@post: Queue�� ���� �� ��Ҹ� reference�� ��ȯ �� ����
	*/
	int pop();

	/*
	@brief: Queue�� ������ return
	@pre: none
	@post: none
	@return: return size of queue
	*/
	int size();

	/*
	@brief: queue�� ����ִ��� ����
	@pre: none
	@post: none
	@return: if queue is empty, return 1, else return 0
	*/
	int IsEmpty();

	/*
	@brief: Queue�� front data�� ��ȯ 
	@pre: queue is not empty
	@post: queue�� front data�� reference�� ��ȯ
	*/
	void front(T& data);

	/*
	@brief: Queue�� rear data�� ��ȯ
	@pre: queue is not empty
	@post: queue�� rear data�� reference�� ��ȯ
	*/
	void back(T& data);
};
#endif // !1