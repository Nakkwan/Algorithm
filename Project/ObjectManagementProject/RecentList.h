#ifndef __RECENTLIST_H
#define __RECENTLIST_H

#include "ItemType.h"
#include "Queue.h"
#include "Base.h"


class RecentList : public Base{
private:
	Queue<ItemType> r_Array;
	int r_length;
	int r_curPointer;

private:
	/*
	@brief: Queue에 물건 추가
	@pre: none
	@post: Queue가 꽉 차지 않았다면, 물건을 추가하고, 
			찼다면, 먼저 들어온 물건을 삭제 후 추가
	*/
	void AddItem();

	/*
	@brief: Queue에 있는 모든 물건 정보 출력
	@pre: none
	@post: none
	*/
	void DisplayAllItem();

	/*
	@brief: Queue 초기화
	@pre: none
	@post: Queue를 빈 상태로 만듦
	*/
	void MakeEmpty();
};

#endif // !__RECENTLIST_H
