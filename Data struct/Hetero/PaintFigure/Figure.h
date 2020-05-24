#pragma once
#include "Base.h"
#include <iostream>

#define MAXVERTEX 50				//�ٰ����� �ִ� ������ ����

//��
class Circle : public Base {
private:
	Point vertex[2];
public:
	Circle() {
		vertex[0].Init(0, 0);				//���� �߽�
		vertex[1].Init(0, 0);				//���� ���
		type = 0;
	}
	Circle(Point ver[]) {
		for (int i = 0; i < 2; i++) {
			vertex[i] = ver[i];
		}
		type = 0;
	}
	void Draw();
	void Display();
};

//�ﰢ��
class Triangle : public Base {
private:
	Point vertex[3];					//�� ������
public:
	Triangle() {
		vertex[0].Init(0, 0);
		vertex[1].Init(0, 0);
		vertex[2].Init(0, 0);
		type = 1;
	}
	Triangle(Point ver[]) {
		for (int i = 0; i < 3; i++) {
			vertex[i] = ver[i];
		}
		type = 1;
	}
	void Draw();
	void Display();
};

//�簢��
class Rectangle : public Base {				
private:
	Point vertex[2];							//�簢���� ���۰� ��
public:
	Rectangle() {
		vertex[0].Init(0, 0);
		vertex[1].Init(0, 0);
		type = 2;
	}
	Rectangle(Point ver[]) {
		for (int i = 0; i < 2; i++) {
			vertex[i] = ver[i];
		}
		type = 2;
	}
	void Draw();
	void Display();
};


// �ٰ���
class Polygon : public Base {
private:
	int vertexNum;							//�������� ����
	Point vertex[MAXVERTEX];				//�ٰ����� �� ������
public:
	Polygon() {
		vertexNum = 0;
		type = 3;
	}
	Polygon(Point ver[], int num) {
		if (num > MAXVERTEX) {
			vertexNum = MAXVERTEX;
		}
		else {
			vertexNum = num;
		}

		for (int i = 0; i < vertexNum; i++) {
			vertex[i] = ver[i];
		}
		type = 3;
	}
	void Draw();
	void Display();
};
