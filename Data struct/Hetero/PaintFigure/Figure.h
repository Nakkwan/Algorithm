#pragma once
#include "Base.h"
#include <iostream>

#define MAXVERTEX 50				//다각형의 최대 꼭짓점 개수

//원
class Circle : public Base {
private:
	Point vertex[2];
public:
	Circle() {
		vertex[0].Init(0, 0);				//원의 중심
		vertex[1].Init(0, 0);				//원의 경계
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

//삼각형
class Triangle : public Base {
private:
	Point vertex[3];					//세 꼭짓점
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

//사각형
class Rectangle : public Base {				
private:
	Point vertex[2];							//사각형의 시작과 끝
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


// 다각형
class Polygon : public Base {
private:
	int vertexNum;							//꼭짓점의 개수
	Point vertex[MAXVERTEX];				//다각형의 각 꼭짓점
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
