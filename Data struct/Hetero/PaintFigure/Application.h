#pragma once

#include "Figure.h"
#include "LinkedQueue.h"
#include "LinkedQueueIterator.h"


class Application {
private:
	int Command;
	int selCommnad;
	Base* base;
	LinkedQueue<Base> baseList;

public:
	Application();

	/*
	@brief: 프로그램 구동
	@pre: none
	@post: none
	*/
	void Run();

	/*
	@brief: 프로그램 기능 선택
	@pre: none
	@post: none
	@return: int 반환(기능에 해당하는)
	*/
	int GetCommand();

	/*
	@brief: 출력할 종류의 도형 선택
	@pre: none
	@post: none
	@return: int 반환(출력할 도형에 해당하는)
	*/
	int SelectFigure();

	/*
	@brief: 모든 도형 출력
	@pre: Set List
	@post: Figure display
	*/
	void DrawAll();

	/*
	@brief: 입력에 따라 리스트에 해당 도형 출력 
	@pre: Set List
	@post: 해당하는 도형들이 출력됨
	*/
	void SelectDraw(int sel);
};