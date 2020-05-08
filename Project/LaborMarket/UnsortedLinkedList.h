#pragma once

template<typename T>
class UnsortedIterator;

template <typename T>
struct UnsortedNode
{
	T value; 
	UnsortedNode* prev; 
	UnsortedNode* next; 
};

template <typename T>
class UnsortedLinkedList {
	friend class UnsortedIterator<T>; 
private:
	UnsortedNode<T>* first;
	UnsortedNode<T>* last;
	int length;

public:
	UnsortedLinkedList();
	~UnsortedLinkedList();

	/*
	@brief:	����Ʈ�� ������� Ȯ���Ѵ�.
	@pre: none
	@post: ������� �ƴ����� �˷��ش�.
	@return: ��������� true, �ƴϸ� false�� return
	*/
	bool IsEmpty();

	/*
	@brief: ����Ʈ�� ����.
	@pre: ����.
	@post: ����Ʈ�� ���� �ʱ� ���·� �����.
	*/
	void MakeEmpty();

	/*
	@brief: ����Ʈ�� ���̸� ��ȯ�Ѵ�.
	@pre: none
	@post: ����Ʈ�� ���̸� return
	@return: ����Ʈ�� ���� 
	*/
	int GetLength() const;

	/*
	@brief: ����Ʈ�� ��Ҹ� �߰��Ѵ�.
	@pre: �߰��� ����� ������ ���õǾ� �־�� �Ѵ�.
	@post: ��Ҹ� ����Ʈ�� �߰�
	*/
	int Add(T& data);

	/*
	@brief: �Է¹��� ������ ����Ʈ���� ����
	@pre: ������ �Է¹޴´�, ����Ʈ�� �ش� ��Ұ� �����ؾ� �Ѵ�.
	@post: �Է¹��� ������ ����Ʈ���� ����
	@return: ������ �����ϸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int Delete(T& data);

	/*
	@brief:	����Ʈ�� ����� ������ �ٲ۴�.
	@pre: �ٲ� ������ �Է¹޴´�.
	@post: ����� ������ ���ŵȴ�.
	@return: �ٲٱ⿡ �����ϸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int Replace(const T& data);

	/*
	@brief:	����Ʈ�� ����� ������ �ٲ۴�.
	@pre: �ٲ� ������ �Է¹޴´�.
	@post: ����� ������ ���ŵȴ�.
	@param: �ٲ� ���, �ٲ� ��ġ�� index
	@return: �ٲٱ⿡ �����ϸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int ReplaceByIndex(const T& data, int index);

	/*
	@brief:	�ش��ϴ� ����Ʈ�� ����� ������ �޴´�.
	@pre: �ش��ϴ� ������ �Է¹޴´�.
	@post: �ش� ������ reference�� ��ȯ�ȴ�.
	@return: ��ȭ�� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int Get(T& item);
};


template <typename T>
UnsortedLinkedList<T> ::UnsortedLinkedList()
{
	first = new UnsortedNode<T>;
	last = new UnsortedNode<T>;

	first->next = last; 
	first->prev = nullptr; 

	last->next = nullptr;
	last->prev = first;

	length = 0;
}


template <typename T>
UnsortedLinkedList<T>::~UnsortedLinkedList()
{
	MakeEmpty();
	delete first;
	delete last;
}


template <typename T>
bool UnsortedLinkedList<T>::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}


template <typename T>
void UnsortedLinkedList<T>::MakeEmpty()
{
	UnsortedNode<T>* temp;
	UnsortedIterator<T> itor(*this);
	itor.Next();

	while (itor.NextNotNull())
	{
		temp = itor.u_pointer;
		itor.Next(); 
		delete temp;
	}

	first->next = last;
	first->prev = nullptr;
	last->prev = first;
	last->next = nullptr;

	return;
}

template <typename T>
int UnsortedLinkedList<T>::GetLength() const {
	return length;
}


template <typename T>
int UnsortedLinkedList<T>::Add(T& data) {
	UnsortedNode<T>* temp = new UnsortedNode<T>;
	temp->value = data;
	temp->next = last;
	temp->prev = last->prev;
	last->prev->next = temp;
	last->prev = temp;
	length++;

	return 1;
}

template <typename T>
int UnsortedLinkedList<T>::Delete(T& data) {
	UnsortedIterator<T> itor(*this);
	itor.Next(); 

	while (itor.NextNotNull()) {
		if (itor.u_pointer->value == data) {
			UnsortedNode<T>* temp = new UnsortedNode<T>;
			temp = itor.u_pointer;
			itor.Next();
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			length--;
			return 1;
		}
		else {
			itor.Next();
		}
	}
	return 0;
}

template <typename T>
int UnsortedLinkedList<T>::Replace(const T& data) {
	UnsortedIterator<T> itor(*this);
	itor.Next();

	while (itor.NextNotNull()) {
		if (itor.u_pointer->value == data) {
			itor.u_pointer->value = data;
			return 1;
		}	
		itor.Next();
	}

	return 0;
}

template <typename T>
int UnsortedLinkedList<T>::ReplaceByIndex(const T& data, int index) {
	UnsortedIterator<T> itor(*this);
	if (index >= length) {
		return 0;
	}
	itor.Next();

	for (int i = 0; i < index; i++) {
		itor.Next();
	}
	itor.u_pointer->value = data;
	return 1;
}

template <typename T>
int UnsortedLinkedList<T>::Get(T& data) {
	UnsortedIterator<T> itor(*this);
	itor.Next();

	while (itor.NextNotNull()) {
		if (itor.u_pointer->value == data) {
			data = itor.u_pointer->value;
			return 1;
		}
		itor.Next();
	}

	return 0;
}