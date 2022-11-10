#include "Class.h"

int main() {
	int size;
	std::cout << "Enter Table's size: ";
	std::cin >> size;
	Table myT(size);

	myT.Input();
	std::cout << std::endl;
	myT.Sort();
	std::cout << std::endl;
	myT.Output();
	std::cout << std::endl;

	std::cout << "Enter new client for Remove:" << std::endl;
	Client one;
	one.input();
	myT.Remove(one);

	std::cout << std::endl;
	myT.Output();
	
	return 0;
}
