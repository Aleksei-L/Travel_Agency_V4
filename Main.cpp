#include "Class.h"

int main() {
	int size;
	std::cout << "Enter Table's size: ";
	std::cin >> size;
	Table myT(size);
	Client buf;

	myT.Input(&buf);
	std::cout << std::endl;
	myT.Sort();
	std::cout << std::endl;
	myT.Output();
	std::cout << std::endl;

	/*std::cout << "Enter new client for Replace:" << std::endl;
	Client one, two;
	one.input();
	two.input();
	myT.Replace(&one, &two);*/

	std::cout << std::endl;
	myT.Output();
	
	return 0;
}
