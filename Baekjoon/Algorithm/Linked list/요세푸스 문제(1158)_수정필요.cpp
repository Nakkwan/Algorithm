#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


template<typename T>
class Node {
public:
	T value;
	Node<T>* next;

	Node<T>() {
		prev = nullptr;
		next = nullptr;
	}
	Node<T>(T value1, Node<T>* next1) {
	    next = next1;
		value = value1;
	}
};

template<typename T>
class LinkedList {
public:
    int size;
    Node<T>* head;

    // 생성자
    LinkedList<T>() : size(0), head(nullptr) {}

    // 소멸자
    ~LinkedList<T>() {
        Node<T>* t1 = head, * t2;
        while (t1 != nullptr) {
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    // 멤버 함수
    void insert(int k, T value) { // k번째 원소 앞에 새 원소 삽입
        if (k == 0) { // 처음에 삽입
            head = new Node<T>(value, head);
        }
        else if (k == size) {
            Node<T>* dest = head;
            for (int i = 0; i < k - 1; i++) dest = dest->next;
            dest->next = new Node<T>(value, head);
        }
        else { // k번째 원소 앞에 삽입
            Node<T>* dest = head;
            for (int i = 0; i < k - 1; i++) dest = dest->next;
            dest->next = new Node<T>(value, dest->next);
        }
        size++;
    }

    int erase(int k) { // k번째 원소를 제거
        int count = 0;
        if (k >= size) {
            k = k % size;
        }

        if (k == 0) { // head를 삭제
            Node<T>* dest = head, * temp;
            for (int i = 0; i < size - 1; i++) dest = dest->next;
            dest->next = head->next;
            count = head->value;
            delete head;
            head = dest->next;
        }

        else { // k번째 원소 삭제
            Node<T>* dest = head, * temp;
            for (int i = 0; i < k - 1; i++) dest = dest->next;
            temp = dest->next;
            count = temp->value;
            temp = temp->next;
            delete dest->next;
            dest->next = temp;
        }
        size--;
        return count;
    }

};



int main() {
    int N, K;
    int count = 0;
    cin >> N >> K;
    LinkedList<int> circle;
    for (int i = 0; i < N; i++) {
        circle.insert(i, i + 1);
    }

    count = K - 1;
    int count2 = N;
    cout << "<";
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            if (count2 <= count) {
                count = count % count2;
            }
                cout << circle.erase(count) << ", ";
                count = count + K - 1;
        }
        else {
            cout << circle.erase(count) << '>' << endl;
        }
        count2--;
    }


	return 0;
}