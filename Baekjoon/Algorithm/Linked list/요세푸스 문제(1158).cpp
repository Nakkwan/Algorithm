#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*Node class for list*/
template<typename T>
class Node {
public:
	T value;
	Node<T>* next;          //pointer for point next node

	Node<T>() {
		next = nullptr;
	}
	Node<T>(T value1, Node<T>* next1) {
	    next = next1;
		value = value1;
	}
};

/*Class for CircularList*/
template<typename T>
class CircularLinkedList {
public:
    int size;               //list size
    Node<T>* head;          //pointer for fist node of list

    // constructor
    CircularLinkedList<T>() : size(0), head(nullptr) {}

    // destructor
    ~CircularLinkedList<T>() {
        Node<T>* t1 = head, * t2;
        while (t1 != nullptr) {
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    // Insert value index k
    void insert(int k, T value) { 
        if (k == 0) { // index 0
            head = new Node<T>(value, head);
        }
        else if (k == size) {   //insert in last of list
            Node<T>* dest = head;
            for (int i = 0; i < k - 1; i++) dest = dest->next;
            dest->next = new Node<T>(value, head);
        }
        else { // insert in kth
            Node<T>* dest = head;
            for (int i = 0; i < k - 1; i++) dest = dest->next;
            dest->next = new Node<T>(value, dest->next);
        }
        size++;
    }

    /*Member function for erase kth index*/
    int erase(int k) {
        if (size > 1) {             // when size of list is bigger than 1 (In other word, list is not only made up of head)
            int count = 0;          //count for return value of erased node
            if (k >= size) {
                k = k % size;
            }

            if (k == 0) { // when erase head
                Node<T>* dest = head, * temp;
                while (dest->next != head) dest = dest->next;
                dest->next = head->next;
                count = head->value;
                delete head;
                head = dest->next;
            }

            else { // erase kth node
                Node<T>* dest = head, * temp;
                for (int i = 0; i < k - 1; i++) dest = dest->next;
                temp = dest->next;
                count = temp->value;
                dest->next = temp->next;
                delete temp;
            }
            size--;
            return count;
        }
        else if (size == 1) {               // list is made up of head
            int count = 0;
            count = head->value;
            delete head;
            head = nullptr;
            size--;
            return count;
        }
    }
};



int main() {
    int N, K;
    int count = 0;
    cin >> N >> K;

    /*Numbering poeple sitting at the desk*/
    CircularLinkedList<int> circle;
    for (int i = 0; i < N; i++) {
        circle.insert(i, i + 1);
    }


    count = K - 1;
    int count2 = N;
    cout << "<";
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            if (count2 <= count) {          // In the case of count exceed size of list 
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