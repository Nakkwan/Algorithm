#ifndef __TEMPTYPE_H
#define __TEMPTYPE_H

#include "pch.h"

class TempList : public Base {
private:
	int numOfItems;
	LinkedQueue<ItemType> tItemList;
public:
	TempList() {				//constructor
		numOfItems = 0;
	}
	~TempList() {}				//destructor

	/*
	@breif: tItemList에 데이터 추가
	@pre: 저장 장소를 뺀 ItemType 설정
	@post: tItemList에 head에 데이터 추가
	*/
	int Enqueue(const ItemType& data);				//queue에 데이터 추가4

	/*
	@breif: tItemList에서 먼저 들어간 데이터 삭제
	@pre: ItemType에 삭제
	@post: tItemList에서 제일 먼저 들어간 데이터가 삭제되고 reference로 반환
	*/
	int Dequeue(ItemType& data);					//queue에 데이터 삭제하고 반환

	/*
	@breif: tItemList에 들어있는 element 값 바꾸기
	@pre: 바꿀 data값 설정
	@post: tItemList의 element가 바뀜
	*/
	int Replace(const ItemType& data);					//queue의 데이터 교체

	/*
	@breif: tItemList의 크기
	@pre: none
	@post: tItemList의 크기 리턴
	*/
	int getNumofItem();

	/*
	@breif: tItemList를 비움
	@pre: none
	@post: tItemList가 비워지고 크기가 0이 됨
	*/
	void MakeEmpty();

	/*
	@breif: tItemList가 꽉 찼는지 확인
	@pre: none
	@post: tItemList가 꽉 찼는지 확인
	@return: tItemList의 queue가 찼으면 1, 아니면 0을 리턴
	*/
	bool IsFull();

	/*
	@breif: tItemList가 비었는지 확인
	@pre: none
	@post: tItemList가 비었는지 확인
	@return: tItemList의 queue가 비었으면 1, 아니면 0을 리턴
	*/
	bool IsEmpty();

	/*
	@breif: tItemList에 들어있는 element display
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@breif: 해당하는 데이터 찾기
	@pre: 찾을 데이터 설정
	@post: 해당하는 데이터가 reference로 반환됨
	*/
	int Get(ItemType& data);

	/*
	@breif: tItemList에서 element 삭제
	@pre: 삭제할 데이터 설정
	@post: parameter에 해당하는 element 삭제
	@param: 삭제할 데이터의 primary ID가 있는 변수
	*/
	int Delete(ItemType& data);

	/*int AllocateItem(ItemType& data);*/

};


#endif // !__TEMPTYPE_H
