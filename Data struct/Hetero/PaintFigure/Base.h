#pragma once

#include <fstream>
#include <string>

class Point {			// 좌표 class
public:

	int x;
	int y;
	Point() {
		x = 0;
		y = 0;
	}
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void Init(int c, int e) {
		x = c;
		y = e; 
	}

	void operator=(Point& b)
	{
		this->x = b.x;
		this->y = b.y;
	};

	friend std::ostream& operator<<(std::ostream& out, Point t)
	{
		out << t.x << " , ";
		out << t.y;
		return out;
	};

	friend std::istream& operator>>(std::istream& in, Point& t)
	{
		in >> t.x;
		in >> t.y;

		return in;
	};
};

class Base {
protected:
	std::string color;					//선의 색
	int width;							//선의 굵기
	int type;							//자식 class 구분
	double area;						//넓이
public:
	Base() {
		color = "";
		width = -1;
		type = -1;
		area = 0;
	}
	virtual void Draw() = 0;		//도형 그리기 순수 가상 함수
	virtual void Display() = 0;		//도형 출력 순수 가상 함수
	bool operator==(Base& data) {	//도형 구별을 위한 ==operator
		if (type == data.type) {
			return true;
		}
		return false;
	}
};