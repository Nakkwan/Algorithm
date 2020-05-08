#pragma once
template<typename T>
struct SortedNode;
template<typename T>
class SortedLinkedList;

template <typename T>
class SortedIterator
{
	friend class SortedLinkedList<T>;
private:
	const SortedLinkedList<T>& s_List;
	SortedNode<T>* s_pointer;

public:
	SortedIterator(const SortedLinkedList<T>& list) : s_List(list), s_pointer(list.first) {}; 


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
	@brief: 마지막 아이템을 반환한다.
	@pre: least one element is already exist
	@post: none
	*/
	T Last();

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
	SortedNode<T> GetCurrentNode();
};

template <typename T>
bool SortedIterator<T>::NotNull() {
	if (s_pointer == nullptr)
		return false;
	else
		return true;
}

template <typename T>
bool SortedIterator<T>::NextNotNull() {
	if (s_pointer->next == nullptr)
		return false;
	else
		return true;
}

template <typename T>
T SortedIterator<T>::First() {
	return s_List.first->next->value;
}

template <typename T>
T SortedIterator<T>::Last() {
	return s_List.last->prev->value;
}

template <typename T>
T SortedIterator<T>::Next() {
	s_pointer = s_pointer->next;
	return s_pointer->value;
}

template <typename T>
SortedNode<T> SortedIterator<T>::GetCurrentNode() {
	return *s_pointer;
}