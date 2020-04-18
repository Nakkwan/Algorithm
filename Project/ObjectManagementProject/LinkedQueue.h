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
	@brief: Queue에 데이터 추가
	@pre: none
	@post: Queue에 데이터가 추가됨
	*/
	void push(int value);

	/*
	@brief: Queue에서 제일 뒤 삭제 후 반환
	@pre: Queue is not empty
	@post: Queue의 제일 뒤 요소를 reference로 반환 후 삭제
	*/
	int pop();

	/*
	@brief: Queue의 사이즈 return
	@pre: none
	@post: none
	@return: return size of queue
	*/
	int size();

	/*
	@brief: queue가 비어있는지 결정
	@pre: none
	@post: none
	@return: if queue is empty, return 1, else return 0
	*/
	int IsEmpty();

	/*
	@brief: Queue의 front data를 반환 
	@pre: queue is not empty
	@post: queue의 front data가 reference로 반환
	*/
	void front(T& data);

	/*
	@brief: Queue의 rear data를 반환
	@pre: queue is not empty
	@post: queue의 rear data가 reference로 반환
	*/
	void back(T& data);
};
#endif // !1