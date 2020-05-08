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
	@post: 요소를 리스트에 추가
	*/
	int Add(T& data);

	/*
	@brief: 입력받은 정보를 리스트에서 삭제
	@pre: 정보를 입력받는다, 리스트에 해당 요소가 존재해야 한다.
	@post: 입력받은 정보를 리스트에서 삭제
	@return: 삭제에 성공하면 1, 아니면 0을 반환한다.
	*/
	int Delete(T& data);

	/*
	@brief:	리스트의 요소의 정보를 바꾼다.
	@pre: 바꿀 정보를 입력받는다.
	@post: 요소의 정보가 갱신된다.
	@return: 바꾸기에 성공하면 1, 아니면 0을 반환한다.
	*/
	int Replace(const T& data);

	/*
	@brief:	리스트의 요소의 정보를 바꾼다.
	@pre: 바꿀 정보를 입력받는다.
	@post: 요소의 정보가 갱신된다.
	@param: 바꿀 요소, 바꿀 위치의 index
	@return: 바꾸기에 성공하면 1, 아니면 0을 반환한다.
	*/
	int ReplaceByIndex(const T& data, int index);

	/*
	@brief:	해당하는 리스트의 요소의 정보를 받는다.
	@pre: 해당하는 정보를 입력받는다.
	@post: 해당 정보가 reference로 반환된다.
	@return: 반화에 성공하면 1, 그렇지 않으면 0을 반환
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