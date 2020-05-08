#pragma once

template<typename T>
class SortedIterator;


template <typename T>
struct SortedNode
{
	T value; 
	SortedNode* prev; 
	SortedNode* next; 
};

template <typename T>
class SortedLinkedList {
	friend class SortedIterator<T>; 

private:
	SortedNode<T>* first; 
	SortedNode<T>* last; 
	int length; 

public:
	SortedLinkedList();
	~SortedLinkedList();

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
	@post: ��ҵ鳢�� ������ ���Ͽ� �����Ͽ� ����Ʈ�� �߰�
	*/
	int Add(T& item);

	/*
	@brief: �Է¹��� ������ ����Ʈ���� ����
	@pre: ������ �Է¹޴´�, ����Ʈ�� �ش� ��Ұ� �����ؾ� �Ѵ�.
	@post: �Է¹��� ������ ����Ʈ���� ����
	@return: ������ �����ϸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int Delete(T& item);

	/*
	@brief:	����Ʈ�� ����� ������ �ٲ۴�.
	@pre: �ٲ� ������ �Է¹޴´�.
	@post: ����� ������ ���ŵȴ�.
	@return: �ٲٱ⿡ �����ϸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int Replace(const T& item);

	/*
	@brief:	�ش��ϴ� ����Ʈ�� ����� ������ �޴´�.
	@pre: �ش��ϴ� ������ �Է¹޴´�.
	@post: �ش� ������ reference�� ��ȯ�ȴ�.
	@return: ��ȭ�� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int Get(T& item);

};

template <typename T>
SortedLinkedList<T> ::SortedLinkedList()
{
	first = new SortedNode<T>;
	last = new SortedNode<T>;

	first->next = last;
	first->prev = nullptr; 

	last->next = nullptr;
	last->prev = first; 

	length = 0;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	MakeEmpty();
	delete first;
	delete last;
}

template <typename T>
bool SortedLinkedList<T>::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

template <typename T>
void SortedLinkedList<T>::MakeEmpty()
{
	SortedNode<T>* temp;
	SortedIterator<T> itor(*this);
	itor.Next(); 

	while (itor.NextNotNull())
	{
		temp = itor.s_pointer;
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
int SortedLinkedList<T>::GetLength() const {
	return length;
}


template <typename T>
int SortedLinkedList<T>::Add(T& data)
{
	SortedIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) {
		SortedNode<T>* temp = new SortedNode<T>;
		temp->value = data;
		first->next = temp;
		temp->prev = first;
		temp->next = last;
		last->prev = temp;
		length++;
		return 1;
	}
	else {
		while (itor.NextNotNull()) {
			if (data < itor.s_pointer->value) {
				SortedNode<T>* temp = new SortedNode<T>;
				temp->value = data;
				temp->prev = itor.s_pointer->prev;
				temp->next = itor.s_pointer;
				itor.s_pointer->prev->next = temp;
				itor.s_pointer->prev = temp;
				length++;
				return 1;
			}
			itor.Next();
		}
		SortedNode<T>* temp = new SortedNode<T>;
		temp->value = data;
		temp->next = last;
		temp->prev = last->prev;
		temp->prev->next = temp;
		last->prev = temp;
		return 1;
	}
}


template <typename T>
int SortedLinkedList<T>::Delete(T& data)
{
	SortedIterator<T> itor(*this);
	itor.Next(); 

	if (IsEmpty()) {
		return 0;
	}

	while (itor.NextNotNull()) {
		if (itor.s_pointer->value == data) {
			SortedNode<T>* temp = new SortedNode<T>;
			temp = itor.s_pointer;
			data = temp->value;
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
int SortedLinkedList<T>::Replace(const T& data)
{
	SortedIterator<T> itor(*this);
	itor.Next(); 

	while (itor.NextNotNull()) {
		if (itor.s_pointer->value == data) {
			itor.s_pointer->value = data;
			return 1;
		}	
		itor.Next();
	}

	return 0;
}


template <typename T>
int SortedLinkedList<T>::Get(T& data)
{
	SortedIterator<T> itor(*this);
	itor.Next();

	while (itor.NextNotNull()) {
		if (itor.s_pointer->value == data) {
			data = itor.s_pointer->value;
			return 1; 
		}
		itor.Next();
	}

	return 0; 
}