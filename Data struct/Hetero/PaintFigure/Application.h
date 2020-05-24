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
	@brief: ���α׷� ����
	@pre: none
	@post: none
	*/
	void Run();

	/*
	@brief: ���α׷� ��� ����
	@pre: none
	@post: none
	@return: int ��ȯ(��ɿ� �ش��ϴ�)
	*/
	int GetCommand();

	/*
	@brief: ����� ������ ���� ����
	@pre: none
	@post: none
	@return: int ��ȯ(����� ������ �ش��ϴ�)
	*/
	int SelectFigure();

	/*
	@brief: ��� ���� ���
	@pre: Set List
	@post: Figure display
	*/
	void DrawAll();

	/*
	@brief: �Է¿� ���� ����Ʈ�� �ش� ���� ��� 
	@pre: Set List
	@post: �ش��ϴ� �������� ��µ�
	*/
	void SelectDraw(int sel);
};