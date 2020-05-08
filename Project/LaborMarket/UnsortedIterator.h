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
	@brief: ���� �����Ͱ� nullptr���� Ȯ��
	@pre: none
	@post: none
	@param: return true if current pointer is not null, otherwise return false
	*/
	bool NotNull();

	/*
	@brief: ���� �����Ͱ� nullptr���� Ȯ��
	@pre: none
	@post: none
	@param: return true if next pointer is not null, otherwise return false
	*/
	bool NextNotNull();

	/*
	@brief: ù �������� ��ȯ�Ѵ�.
	@pre: least one element is already exist
	@post: none
	*/
	T First();

	/*
	@brief: �����͸� ���� ���� �ٲ۴�.
	@pre: none
	@post: none
	*/
	T Next();

	/*
	@brief: ���� �����Ͱ� ����Ű�� ��带 ��ȯ�Ѵ�.
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