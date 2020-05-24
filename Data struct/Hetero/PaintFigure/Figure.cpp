#include "Figure.h"

void Circle::Draw()
{
	std::cout << "���� �߽� ��ǥ��\n";
	std::cout << "x��ǥ: ";
	std::cin >> vertex[0].x;
	std::cout << "y��ǥ: ";
	std::cin >> vertex[0].y;

	std::cout << "���� ��� ��ǥ��\n";
	std::cout << "x��ǥ: ";
	std::cin >> vertex[1].x;
	std::cout << "y��ǥ: ";
	std::cin >> vertex[1].y;

	std::cout << "���� ����: ";
	std::cin >> width;

	std::cout << "���� ��: ";
	std::cin >> color;

	area = 3.14 * pow(pow(pow(abs(vertex[0].x - vertex[1].x), 2) + pow(abs(vertex[0].y - vertex[1].y), 2), 0.5), 2);
}

void Circle::Display()
{
	std::cout << "���� ����\n";
	std::cout << "���� �߽�: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "���� ���: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";

	std::cout << "���� �� ����: " << width << std::endl;
	std::cout << "���� ��: " << color << std::endl;
	std::cout << "���� ����: " << area << std::endl;
}

void Triangle::Draw()
{
	std::cout << "�ﰢ���� ������ ��ǥ��\n";
	std::cout << "ù��° x��ǥ: ";
	std::cin >> vertex[0].x;
	std::cout << "ù��° y��ǥ: ";
	std::cin >> vertex[0].y;

	std::cout << "�ι�° x��ǥ: ";
	std::cin >> vertex[1].x;
	std::cout << "�ι�° y��ǥ: ";
	std::cin >> vertex[1].y;

	std::cout << "����° x��ǥ: ";
	std::cin >> vertex[2].x;
	std::cout << "����° y��ǥ: ";
	std::cin >> vertex[2].y;

	std::cout << "���� ����: ";
	std::cin >> width;

	std::cout << "���� ��: ";
	std::cin >> color;
}

void Triangle::Display()
{
	std::cout << "�ﰢ���� ����\n";
	std::cout << "ù ������ ��ǥ: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "��° ������ ��ǥ: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";
	std::cout << "��° ������ ��ǥ: (x, y) = " << '(' << vertex[2].x << ", " << vertex[2].y << ")\n";

	std::cout << "�ﰢ���� �� ����: " << width << std::endl;
	std::cout << "�ﰢ���� ��: " << color << std::endl;
}

void Rectangle::Draw()
{
	std::cout << "���簢���� ������ ��ǥ��\n";
	std::cout << "���� x��ǥ: ";
	std::cin >> vertex[0].x;
	std::cout << "���� y��ǥ: ";
	std::cin >> vertex[0].y;

	std::cout << "�� x��ǥ: ";
	std::cin >> vertex[1].x;
	std::cout << "�� y��ǥ: ";
	std::cin >> vertex[1].y;

	std::cout << "���� ����: ";
	std::cin >> width;

	std::cout << "���� ��: ";
	std::cin >> color;

	area = (double)abs(vertex[0].x - vertex[1].x) * abs(vertex[0].y - vertex[1].y);
}

void Rectangle::Display()
{
	std::cout << "�簢���� ����\n";
	std::cout << "���� ��ǥ: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "�� ��ǥ: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";

	std::cout << "�簢���� �� ����: " << width << std::endl;
	std::cout << "�簢���� ��: " << color << std::endl;
	std::cout << "�簢���� ����: " << area << std::endl;
}

void Polygon::Draw()
{
	std::cout << "�������� ����(�ִ� 50): ";
	std::cout << "<�ٰ����� ������>\n";
	std::cin >> vertexNum;
	for (int i = 0; i < vertexNum; i++) {
		std::cout << i + 1 << " ��° ������\n";
		std::cout << "x��ǥ: ";
		std::cin >> vertex[i].x;
		std::cout << "y��ǥ: ";
		std::cin >> vertex[i].y;
	}
	std::cout << "���� ����: ";
	std::cin >> width;

	std::cout << "���� ��: ";
	std::cin >> color;
}

void Polygon::Display()
{
	std::cout << "�ٰ����� ����\n";
	std::cout << "�������� ����: " << vertexNum << std::endl;
	for (int i = 0; i < vertexNum; i++) {
		std::cout << i + 1 << " ��° ��ǥ: (x, y) = " << '(' << vertex[i].x << ", " << vertex[i].y << ")\n";
	}
	std::cout << "�ٰ����� �� ����: " << width << std::endl;
	std::cout << "�ٰ����� ��: " << color << std::endl;
}