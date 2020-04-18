#ifndef __QUEUE_H
#define __QUEUE_H

template<typename T>
class Queue {
private:
	int Q_head;
	int Q_tail;
	int Q_size;					//데이터가 들어갈 수 있는 전체 queue의 크기, 전체 할당된 크기는 Q_size + 1이다.
	int Q_curSize;				//현재 저장된 것들의 크기
	int Q_curPointer;			//포인터
	T* Q_item;

public:
	Queue();					//생성자
	Queue(int size);			//생성자
	~Queue();					//소멸자

	/*
	@brief: queue 초기화
	@pre: none
	@post: queue의 크기가 0이 되고, head와 tail이 초기화 됨
	*/
	void MakeEmpty();

	/*
	@brief: queue가 꽉 찼는지 결정
	@pre: none
	@post: none
	*/
	bool IsFull();

	/*
	@brief: queue가 비었는지 결정
	@pre: none
	@post: none
	*/
	bool IsEmpty();

	/*
	@brief: queue에 데이터 추가
	@pre: 추가할 데이터 설정
	@post: queue에 데이터가 추가되고 크기가 1 늘어남. head가 다음 칸으로 이동
	@return: 추가가 되면 1, 안되면 0 return
	*/
	int Enqueue(T data);

	/*
	@brief: queue에 먼저 들어온 데이터 삭제
	@pre: none
	@post: queue에 데이터가 삭제되고 크기가 1 줄어듦. tail이 다음 칸으로 이동. 삭제된 데이터를 reference로 반환
	@param: 삭제된 데이터를 reference로 받을 변수
	@return: 삭제가 되면 1, 안되면 0 return
	*/
	int Dequeue(T& data);

	/*
	@brief: queue의 사이즈 확인
	@pre: none
	@post: none
	*/
	int GetSize();

	/*
	@brief: queue의 포인터 리셋
	@pre: none
	@post: queue의 포인터가 tail과 같게 초기화 됨
	*/
	void ResetQueue();

	/*
	@brief: 다음 포인터에 해당하는 데이터, pointer 반환
	@pre: none
	@post: 포인터가 1늘어나고 그에 해당하는 데이터가 return 됨
	@param: 데이터를 받을 변수
	@return: pointer return
	*/
	int GetNextItem(T& data);

	/*
	@brief: 데이터를 찾음
	@pre: 찾을 데이터 설정
	@post: 해당하는 데이터가 reference로 반환 됨
	@param: 반환 받을 변수
	@return: 데이터를 찾으면 1, 아니면 0을 return
	*/
	int Get(T& data);

	/*
	@brief: 해당하는 데이터 삭제
	@pre: 삭제할 데이터 설정
	@post: 해당하는 데이터가 삭제되고, queue가 재정렬됨
	@param: 삭제할 데이터의 정보가 담긴 변수
	@return: 삭제가 되면 1 아니면 0을 return
	*/
	int Delete(const T& data);

	/*
	@brief: queue의 element를 교체
	@pre: 교체할 데이터 설정
	@post: 해당하는 element의 데이터가 교체됨
	@param: 교체할 데이터
	@return: 데이터가 교체되면 1, 아니면 0을 return
	*/
	int Replace(T data);
};
#endif