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
	@breif: 스택 비우기
	@pre: none
	@post: none
	*/
	void MakeEmpty();

	/*
	@breif: 스택이 찼는지 확인
	@pre: none
	@post: none
	*/
	bool IsFull();

	/*
	@breif: 스택이 비었는지 확인
	@pre: none
	@post: none
	*/
	bool IsEmpty();

	/*
	@breif: 스택에 element 추가
	@pre: 넣을 element 설정
	@post: 스택에 element 추가되고, 크기 +1
	*/
	int Push(T data);

	/*
	@breif: 스택에서 element 빼기
	@pre: none
	@post: stack 맨위 element가 삭제되고, reference로 반환
	@param: element값을 받을 변수
	*/
	int Pop(T& data);

	/*
	@breif: 스택의 포인터 초기화
	@pre: none
	@post: 스택의 pointer가 -1로 초기화
	*/
	void ResetStack();

	/*
	@breif: 다음 element를 받음
	@pre: none
	@post: stack의 크기 내에서 포인터를 1증가시키고, 해당하는 element를 reference로 받음.
			범위를 벗어나면 -1로 초기화
	@return: 포인터
	*/
	int GetNextItem(T& data);

	/*
	@breif: stack에서 데이터 찾기
	@pre: 찾을 데이터를 설정
	@post: 찾은 데이터를 reference로 반환
	@param: 데이터를 받을 변수
	@return: 데이터를 찾으면 1, 아니면 0을 반환
	*/
	int Get(T& data);

	/*
	@breif: stack의 데이터 교체
	@pre: 교체할 데이터 설정
	@post: 해당하는 stack의 element data가 바뀜
	@param: 바꿀 데이터
	@return: 데이터를 바꾸면 1, 아니면 0을 반환
	*/
	int Replace(T data);

	/*
	@breif: stack에서 데이터를 삭제함
	@pre: 삭제할 값 설정
	@post: 해당하는 stack의 element data가 삭제되고, stack의 크기가 1 줄어듦
	@param: 삭제할 데이터
	@return: 데이터를 삭제하면 1, 아니면 0을 반환
	*/
	int Delete(T data);

	/*
	@breif: stack의 사이즈 확인
	@pre: none
	@post: none
	@return: stack의 size return
	*/
	int getSize();
};
#endif