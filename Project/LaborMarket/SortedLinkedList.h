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
	@brief:	리스트가 비었는지 확인한다.
	@pre: none
	@post: 비었는지 아닌지를 알려준다.
	@return: 비어있으면 true, 아니면 false를 return
	*/
	bool IsEmpty();

	/*
	@brief: 리스트를 비운다.
	@pre: 없음.
	@post: 리스트를 비우고 초기 상태로 만든다.
	*/
	void MakeEmpty();

	/*
	@brief: 리스트의 길이를 반환한다.
	@pre: none
	@post: 리스트의 길이를 return
	@return: 리스트의 길이
	*/
	int GetLength() const;

	/*
	@brief: 리스트에 요소를 추가한다.
	@pre: 추가할 요소의 정보가 셋팅되어 있어야 한다.
	@post: 요소들끼리 정보를 비교하여 정렬하여 리스트에 추가
	*/
	int Add(T& item);

	/*
	@brief: 입력받은 정보를 리스트에서 삭제
	@pre: 정보를 입력받는다, 리스트에 해당 요소가 존재해야 한다.
	@post: 입력받은 정보를 리스트에서 삭제
	@return: 삭제에 성공하면 1, 아니면 0을 반환한다.
	*/
	int Delete(T& item);

	/*
	@brief:	리스트의 요소의 정보를 바꾼다.
	@pre: 바꿀 정보를 입력받는다.
	@post: 요소의 정보가 갱신된다.
	@return: 바꾸기에 성공하면 1, 아니면 0을 반환한다.
	*/
	int Replace(const T& item);

	/*
	@brief:	해당하는 리스트의 요소의 정보를 받는다.
	@pre: 해당하는 정보를 입력받는다.
	@post: 해당 정보가 reference로 반환된다.
	@return: 반화에 성공하면 1, 그렇지 않으면 0을 반환
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