#include "Figure.h"

void Circle::Draw()
{
	std::cout << "¿øÀÇ Áß½É ÁÂÇ¥°ª\n";
	std::cout << "xÁÂÇ¥: ";
	std::cin >> vertex[0].x;
	std::cout << "yÁÂÇ¥: ";
	std::cin >> vertex[0].y;

	std::cout << "¿øÀÇ °æ°è ÁÂÇ¥°ª\n";
	std::cout << "xÁÂÇ¥: ";
	std::cin >> vertex[1].x;
	std::cout << "yÁÂÇ¥: ";
	std::cin >> vertex[1].y;

	std::cout << "¼±ÀÇ ±½±â: ";
	std::cin >> width;

	std::cout << "¼±ÀÇ »ö: ";
	std::cin >> color;

	area = 3.14 * pow(pow(pow(abs(vertex[0].x - vertex[1].x), 2) + pow(abs(vertex[0].y - vertex[1].y), 2), 0.5), 2);
}

void Circle::Display()
{
	std::cout << "¿øÀÇ Á¤º¸\n";
	std::cout << "¿øÀÇ Áß½É: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "¿øÀÇ °æ°è: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";

	std::cout << "¿øÀÇ ¼± ±½±â: " << width << std::endl;
	std::cout << "¼±ÀÇ »ö: " << color << std::endl;
	std::cout << "¿øÀÇ ³ÐÀÌ: " << area << std::endl;
}

void Triangle::Draw()
{
	std::cout << "»ï°¢ÇüÀÇ ²ÀÁþÁ¡ ÁÂÇ¥°ª\n";
	std::cout << "Ã¹¹øÂ° xÁÂÇ¥: ";
	std::cin >> vertex[0].x;
	std::cout << "Ã¹¹øÂ° yÁÂÇ¥: ";
	std::cin >> vertex[0].y;

	std::cout << "µÎ¹øÂ° xÁÂÇ¥: ";
	std::cin >> vertex[1].x;
	std::cout << "µÎ¹øÂ° yÁÂÇ¥: ";
	std::cin >> vertex[1].y;

	std::cout << "¼¼¹øÂ° xÁÂÇ¥: ";
	std::cin >> vertex[2].x;
	std::cout << "¼¼¹øÂ° yÁÂÇ¥: ";
	std::cin >> vertex[2].y;

	std::cout << "¼±ÀÇ ±½±â: ";
	std::cin >> width;

	std::cout << "¼±ÀÇ »ö: ";
	std::cin >> color;
}

void Triangle::Display()
{
	std::cout << "»ï°¢ÇüÀÇ Á¤º¸\n";
	std::cout << "Ã¹ ²ÀÁþÁ¡ ÁÂÇ¥: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "µÑÂ° ²ÀÁþÁ¡ ÁÂÇ¥: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";
	std::cout << "¼ÂÂ° ²ÀÁþÁ¡ ÁÂÇ¥: (x, y) = " << '(' << vertex[2].x << ", " << vertex[2].y << ")\n";

	std::cout << "»ï°¢ÇüÀÇ ¼± ±½±â: " << width << std::endl;
	std::cout << "»ï°¢ÇüÀÇ »ö: " << color << std::endl;
}

void Rectangle::Draw()
{
	std::cout << "Á÷»ç°¢ÇüÀÇ ²ÀÁþÁ¡ ÁÂÇ¥°ª\n";
	std::cout << "½ÃÀÛ xÁÂÇ¥: ";
	std::cin >> vertex[0].x;
	std::cout << "½ÃÀÛ yÁÂÇ¥: ";
	std::cin >> vertex[0].y;

	std::cout << "³¡ xÁÂÇ¥: ";
	std::cin >> vertex[1].x;
	std::cout << "³¡ yÁÂÇ¥: ";
	std::cin >> vertex[1].y;

	std::cout << "¼±ÀÇ ±½±â: ";
	std::cin >> width;

	std::cout << "¼±ÀÇ »ö: ";
	std::cin >> color;

	area = (double)abs(vertex[0].x - vertex[1].x) * abs(vertex[0].y - vertex[1].y);
}

void Rectangle::Display()
{
	std::cout << "»ç°¢ÇüÀÇ Á¤º¸\n";
	std::cout << "½ÃÀÛ ÁÂÇ¥: (x, y) = " << '(' << vertex[0].x << ", " << vertex[0].y << ")\n";
	std::cout << "³¡ ÁÂÇ¥: (x, y) = " << '(' << vertex[1].x << ", " << vertex[1].y << ")\n";

	std::cout << "»ç°¢ÇüÀÇ ¼± ±½±â: " << width << std::endl;
	std::cout << "»ç°¢ÇüÀÇ »ö: " << color << std::endl;
	std::cout << "»ç°¢ÇüÀÇ ³ÐÀÌ: " << area << std::endl;
}

void Polygon::Draw()
{
	std::cout << "²ÀÁþÁ¡ÀÇ °³¼ö(ÃÖ´ë 50): ";
	std::cout << "<´Ù°¢ÇüÀÇ ²ÀÁþÁ¡>\n";
	std::cin >> vertexNum;
	for (int i = 0; i < vertexNum; i++) {
		std::cout << i + 1 << " ¹øÂ° ²ÀÁþÁ¡\n";
		std::cout << "xÁÂÇ¥: ";
		std::cin >> vertex[i].x;
		std::cout << "yÁÂÇ¥: ";
		std::cin >> vertex[i].y;
	}
	std::cout << "¼±ÀÇ ±½±â: ";
	std::cin >> width;

	std::cout << "¼±ÀÇ »ö: ";
	std::cin >> color;
}

void Polygon::Display()
{
	std::cout << "´Ù°¢ÇüÀÇ Á¤º¸\n";
	std::cout << "²ÀÁþÁ¡ÀÇ °³¼ö: " << vertexNum << std::endl;
	for (int i = 0; i < vertexNum; i++) {
		std::cout << i + 1 << " ¹øÂ° ÁÂÇ¥: (x, y) = " << '(' << vertex[i].x << ", " << vertex[i].y << ")\n";
	}
	std::cout << "´Ù°¢ÇüÀÇ ¼± ±½±â: " << width << std::endl;
	std::cout << "´Ù°¢ÇüÀÇ »ö: " << color << std::endl;
}