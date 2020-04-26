#ifndef __STACK_H
#define __STACK_H

template<typename T>
class Stack {
private:
	int S_top;
	int S_size;
	int cur_Pointer;
	T* S_stack;
public:
	Stack();				//constructor
	Stack(int size);		//constructor
	~Stack();				//destructor

	/*
	@breif: ���� ����
	@pre: none
	@post: none
	*/
	void MakeEmpty();

	/*
	@breif: ������ á���� Ȯ��
	@pre: none
	@post: none
	*/
	bool IsFull();

	/*
	@breif: ������ ������� Ȯ��
	@pre: none
	@post: none
	*/
	bool IsEmpty();

	/*
	@breif: ���ÿ� element �߰�
	@pre: ���� element ����
	@post: ���ÿ� element �߰��ǰ�, ũ�� +1
	*/
	int Push(T data);

	/*
	@breif: ���ÿ��� element ����
	@pre: none
	@post: stack ���� element�� �����ǰ�, reference�� ��ȯ
	@param: element���� ���� ����
	*/
	int Pop(T& data);

	/*
	@breif: ������ ������ �ʱ�ȭ
	@pre: none
	@post: ������ pointer�� -1�� �ʱ�ȭ
	*/
	void ResetStack();

	/*
	@breif: ���� element�� ����
	@pre: none
	@post: stack�� ũ�� ������ �����͸� 1������Ű��, �ش��ϴ� element�� reference�� ����.
			������ ����� -1�� �ʱ�ȭ
	@return: ������
	*/
	int GetNextItem(T& data);

	/*
	@breif: stack���� ������ ã��
	@pre: ã�� �����͸� ����
	@post: ã�� �����͸� reference�� ��ȯ
	@param: �����͸� ���� ����
	@return: �����͸� ã���� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Get(T& data);

	/*
	@breif: stack�� ������ ��ü
	@pre: ��ü�� ������ ����
	@post: �ش��ϴ� stack�� element data�� �ٲ�
	@param: �ٲ� ������
	@return: �����͸� �ٲٸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Replace(T data);

	/*
	@breif: stack���� �����͸� ������
	@pre: ������ �� ����
	@post: �ش��ϴ� stack�� element data�� �����ǰ�, stack�� ũ�Ⱑ 1 �پ��
	@param: ������ ������
	@return: �����͸� �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Delete(T data);

	/*
	@breif: stack�� ������ Ȯ��
	@pre: none
	@post: none
	@return: stack�� size return
	*/
	int getSize();
};


template<typename T>
Stack<T>::Stack() {
	S_stack = new T[MAXSTACK];
	S_size = MAXSTACK;
	S_top = -1;
	cur_Pointer = -1;
}

template<typename T>
Stack<T>::Stack(int size) {
	S_stack = new T[size];
	S_size = size;
	S_top = -1;
	cur_Pointer = -1;
}

template<typename T>
Stack<T>::~Stack() {
	delete[] S_stack;
}

template<typename T>
void Stack<T>::MakeEmpty() {
	S_top = -1;
}

template<typename T>
bool Stack<T>::IsFull() {
	if (S_top == S_size - 1) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Stack<T>::IsEmpty() {
	if (S_top == -1) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
int Stack<T>::Push(T data) {
	if (IsFull()) {						//�迭�� �� ���� ����
		cout << "Error: Stack is already full\n";
		return 0;
	}
	else {
		S_top++;
		S_stack[S_top] = data;
	}
	return 1;
}

template<typename T>
int Stack<T>::Pop(T& data) {
	if (IsEmpty()) {						//�迭�� ������� ����
		cout << "Error: Stack is already empty\n";
		return 0;
	}
	else {
		data = S_stack[S_top];
		S_top--;
	}
	return 1;
}

template<typename T>
void Stack<T>::ResetStack() {
	cur_Pointer = -1;
}

template<typename T>
int Stack<T>::GetNextItem(T& data) {
	if (cur_Pointer == S_top) {				//�����Ͱ� stack�� ����⿡ ���������� -1�� ����
		cur_Pointer = -1;
		return cur_Pointer;
	}
	else {
		cur_Pointer++;						//�����͸� ������Ų �� �� ��ȯ
		data = S_stack[cur_Pointer];
		return cur_Pointer;
	}
}

template<typename T>
int Stack<T>::Get(T& data) {
	T temp;
	ResetStack();
	GetNextItem(temp);
	while (cur_Pointer != -1) {
		if (temp == data) {				//ã�� �����Ͱ� �ִٸ�
			data = temp;				//reference�� ��ȯ
			return 1;
		}
		else {
			GetNextItem(temp);
		}
	}
	return 0;
}

template<typename T>
int Stack<T>::Replace(T data) {
	T temp;
	ResetStack();
	GetNextItem(temp);
	while (cur_Pointer != -1) {
		if (temp == data) {						//�ٲ� �����͸� ã������
			S_stack[cur_Pointer] = data;		//�����͸� �ٲ���
			return 1;
		}
		else {
			GetNextItem(temp);					//�ش� �����Ͱ� �ƴ� ��, ���� �� ����
		}
	}
	return 0;
}

template<typename T>
int Stack<T>::Delete(T data) {
	T temp;
	ResetStack();
	GetNextItem(temp);
	while (cur_Pointer != -1) {
		if (temp == data) {										//������ �����Ͱ� ������
			for (int i = cur_Pointer; i < S_top; i++) {			//top���� �ش� �����ͱ��� ���� �ϳ��� ������
				S_stack[i] = S_stack[i + 1];
			}
			S_top--;
			return 1;
		}
		else {
			GetNextItem(temp);
		}
	}
	return 0;
}

template<typename T>
int Stack<T>::getSize() {
	return S_top;
}

#endif