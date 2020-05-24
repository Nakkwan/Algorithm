#pragma once

#include <fstream>
#include <string>

class Point {			// ��ǥ class
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
	std::string color;					//���� ��
	int width;							//���� ����
	int type;							//�ڽ� class ����
	double area;						//����
public:
	Base() {
		color = "";
		width = -1;
		type = -1;
		area = 0;
	}
	virtual void Draw() = 0;		//���� �׸��� ���� ���� �Լ�
	virtual void Display() = 0;		//���� ��� ���� ���� �Լ�
	bool operator==(Base& data) {	//���� ������ ���� ==operator
		if (type == data.type) {
			return true;
		}
		return false;
	}
};