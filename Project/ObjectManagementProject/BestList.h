#ifndef __BESTLIST_H
#define __BESTLIST_H

#include "pch.h"


class BestList : public Base {
private:
	Stack<ItemType> B_Array;		//가장 많이 검색된 물건의 리스트
	int B_length;					//최빈 물건 리스트의 크기
public:
	BestList();						//생성자
	~BestList(){}					//소멸자

	/*
	@brief: stack의 top data와 검색횟수 비교
	@pre: set stack
	@post: none
	@param: ItemType for compare
	@return: top data가 더 많으면 1, 같으면 0, 적으면 -1을 return
	*/
	bool CompareSearchNum(const ItemType& data);

	/*
	@brief: Stack에 물건 추가
	@pre: none
	@post: stack이 꽉 차지않았다면 물건을 추가하고, 
		   꽉 찼다면 top data와 비교하여 더 크면 top data삭제 후 추가
	*/
	int AddItem(ItemType& data);

	/*
	@brief: 검색 횟수에 따라 stack내부 위치 재정렬
	@pre: stack has more than 1 element
	@post: Readjust stack
	*/
	void RearrangeStack();

	/*
	@brief: stack에 있는 모든 물건 정보 출력
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@brief: Stack 초기화
	@pre: none
	@post: Stack를 빈 상태로 만들고, 물건들의 검색 횟수를 0으로 초기화
	*/
	//void MakeEmpty();

	/*
	@brief: 물건의 검색 횟수를 0으로 초기화
	@pre: index가 스택의 범위 이내여야 한다.
	@post: 해당 index의 물건의 검색 횟수를 0으로 초기화
	@param: index of stack for reset SearchNum
	*/
	/*void ResetObjectSearch(int index);*/
};


#endif // !__BESTLIST_H
