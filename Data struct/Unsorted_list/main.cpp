#include <iostream>
#include "ArrayList.h"


int main() {
	ArrayList ls(4);
	ls.Add(1);
	ls.Display();
	ls.Add(2);
	ls.Display();
	ls.Add(3);
	ls.Display();
	ls.Add(4);
	ls.Display();
	std::cout << ls.IsFull() << '\n';
	ls.Add(5);
	ls.Display();
	ls.Delete(3);
	std::cout << ls.RetrieveItem(3) << '\n';
	std::cout << ls.RetrieveItem(4) << '\n';
	ls.Display();
	ls.replace(1, 10);
	ls.Display();
	std::cout << ls.Lengthls() << '\n';
	std::cout << ls.IsFull() << '\n';
	ls.MakeEmpty();
	ls.Display();
}