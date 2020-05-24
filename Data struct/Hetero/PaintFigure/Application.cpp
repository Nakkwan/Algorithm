#include "Application.h"

Application::Application()
{
	base = nullptr;
	Command = -1;
	selCommnad = -1;
}

void Application::Run()
{
	while (1) {
		int c = GetCommand();
		base = nullptr;
		switch (c)
		{
		case 1:
			base = new Circle();
			base->Draw();
			break;
		case 2:
			base = new Triangle();
			base->Draw();
			break;
		case 3:
			base = new Rectangle();
			base->Draw();
			break;
		case 4:
			base = new Polygon();
			base->Draw();
			break;
		case 5:
			std::cout << "  <현재 도형 출력>\n";
			baseList.LastIn()->Display();
			break;
		case 6:
			SelectDraw(SelectFigure());
			break;
		case 7:
			DrawAll();
			break;
		case 8:
			baseList.MakeEmpty();
			break;
		case 0:
			return;
		default:
			"  <잘못된 입력입니다>\n";
			break;
		}
		if (base != nullptr) {
			baseList.Enqueue(base);
		}
	}
}

int Application::GetCommand()
{
	std::cout << "\n\t<도형 그리기>\n";
	std::cout << "    1. 원 그리기\n";
	std::cout << "    2. 삼각형 그리기\n";
	std::cout << "    3. 사각형 그리기\n";
	std::cout << "    4. 다각형 그리기\n";
	std::cout << "    5. 현재 도형 출력\n";
	std::cout << "    6. 종류별 출력\n";
	std::cout << "    7. 모두 출력\n";
	std::cout << "    8. 기록 지우기\n";
	std::cout << "    0. 끝내기\n";

	std::cout << "---> Command 입력: ";
	std::cin >> Command;

	return Command;
}

int Application::SelectFigure()
{
	std::cout << "\t <도형 선택>\n";
	std::cout << " 1. 원, 2. 삼각형, 3. 사각형, 4. 다각형\n";
	std::cout << " 입력: ";
	std::cin >> selCommnad;

	return selCommnad;
}

void Application::DrawAll()
{
	int count = 1;
	LinkedQueueIterator<Base> itor(baseList);
	Base* temp;
	temp = itor.Next();
	while (itor.NextNotNull()) {
		std::cout << count << ".\n";
		temp->Display();
		std::cout << std::endl;
		temp = itor.Next();
		std::cout << std::endl;
		count++;
	}
}

void Application::SelectDraw(int sel)
{
	Base* temp = nullptr;
	switch (sel)
	{
	case 1:
		temp = new Circle();
		std::cout << "  <원 출력>\n";
		break;
	case 2:
		temp = new Triangle();
		std::cout << "  <삼각형 출력>\n";
		break;
	case 3:
		temp = new Rectangle();
		std::cout << "  <사각형 출력>\n";
		break;
	case 4:
		temp = new Polygon();
		std::cout << "  <다각형 출력>\n";
		break;
	default:
		break;
	}

	int count = 1;
	LinkedQueueIterator<Base> itor(baseList);
	Base* data;
	data = itor.Next();
	while (itor.NextNotNull()) {
		if (*data == *temp) {						//해당하는  도형 출력
			std::cout << count << ".\n";
			data->Display();
			std::cout << std::endl;
			count++;
		}

		data = itor.Next();
	}
}
