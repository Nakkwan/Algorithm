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
			std::cout << "  <���� ���� ���>\n";
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
			"  <�߸��� �Է��Դϴ�>\n";
			break;
		}
		if (base != nullptr) {
			baseList.Enqueue(base);
		}
	}
}

int Application::GetCommand()
{
	std::cout << "\n\t<���� �׸���>\n";
	std::cout << "    1. �� �׸���\n";
	std::cout << "    2. �ﰢ�� �׸���\n";
	std::cout << "    3. �簢�� �׸���\n";
	std::cout << "    4. �ٰ��� �׸���\n";
	std::cout << "    5. ���� ���� ���\n";
	std::cout << "    6. ������ ���\n";
	std::cout << "    7. ��� ���\n";
	std::cout << "    8. ��� �����\n";
	std::cout << "    0. ������\n";

	std::cout << "---> Command �Է�: ";
	std::cin >> Command;

	return Command;
}

int Application::SelectFigure()
{
	std::cout << "\t <���� ����>\n";
	std::cout << " 1. ��, 2. �ﰢ��, 3. �簢��, 4. �ٰ���\n";
	std::cout << " �Է�: ";
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
		std::cout << "  <�� ���>\n";
		break;
	case 2:
		temp = new Triangle();
		std::cout << "  <�ﰢ�� ���>\n";
		break;
	case 3:
		temp = new Rectangle();
		std::cout << "  <�簢�� ���>\n";
		break;
	case 4:
		temp = new Polygon();
		std::cout << "  <�ٰ��� ���>\n";
		break;
	default:
		break;
	}

	int count = 1;
	LinkedQueueIterator<Base> itor(baseList);
	Base* data;
	data = itor.Next();
	while (itor.NextNotNull()) {
		if (*data == *temp) {						//�ش��ϴ�  ���� ���
			std::cout << count << ".\n";
			data->Display();
			std::cout << std::endl;
			count++;
		}

		data = itor.Next();
	}
}
