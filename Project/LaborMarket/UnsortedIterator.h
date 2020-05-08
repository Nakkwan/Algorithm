#pragma once
template<typename T>
struct UnsortedNode;
template<typename T>
class UnsortedLinkedList;

template <typename T>
class UnsortedIterator
{
	friend class UnsortedLinkedList<T>;
private:
	const UnsortedLinkedList<T>& u_List;
	UnsortedNode<T>* u_pointer;

public:

	UnsortedIterator(const UnsortedLinkedList<T>& list) : u_List(list), u_pointer(list.first) {}; 


	/*
	@brief: 현재 포인터가 nullptr인지 확인
	@pre: none
	@post: none
	@param: return true if current pointer is not null, otherwise return false
	*/
	bool NotNull();

	/*
	@brief: 다음 포인터가 nullptr인지 확인
	@pre: none
	@post: none
	@param: return true if next pointer is not null, otherwise return false
	*/
	bool NextNotNull();

	/*
	@brief: 첫 아이템을 반환한다.
	@pre: least one element is already exist
	@post: none
	*/
	T First();

	/*
	@brief: 포인터를 다음 노드로 바꾼다.
	@pre: none
	@post: none
	*/
	T Next();

	/*
	@brief: 현재 포인터가 가르키는 노드를 반환한다.
	@pre: none
	@post: none
	*/
	UnsortedNode<T> GetCurrentNode();
};

template <typename T>
bool UnsortedIterator<T> ::NotNull()
{
	if (u_pointer == nullptr)
		return false;
	else
		return true;
}

template <typename T>
bool UnsortedIterator<T> ::NextNotNull()
{
	if (u_pointer->next == nullptr)
		return false;
	else
		return true;
}

template <typename T>
T UnsortedIterator<T> ::First()
{
	return u_List.first->next->value;
}

template <typename T>
T UnsortedIterator<T> ::Next()
{
	u_pointer = u_pointer->next;
	return u_pointer->value;
}

template <typename T>
UnsortedNode<T> UnsortedIterator<T> ::GetCurrentNode()
{
	return *u_pointer;
}