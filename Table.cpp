#include <algorithm>
#include "Class.h"

// Выделение памяти под таблицу, её конструктор
Table::Table(int s) {
	size = s;
	m = new Client * [s];
	current = NULL;
}

// Деструктор таблицы
Table::~Table() {
	delete[] m;
}

/*
// Увеличение размера таблицы по запросу пользователя
// TODO: написать функцию
void Table::Resize(int newsize) {
	/*Client** newTable = new Client * [newsize];
	for (int i = 0; i < newsize; i++)
		newTable[i] = new Client;
}
*/

// Создание копии объекта в динамической памяти
Client* Table::Copy(Client& client) {
	Client* newClient = new Client;

	delete[] newClient->name;
	newClient->name = new char[strlen(client.name) + 1];
	strcpy_s(newClient->name, strlen(client.name) + 1, client.name);

	strcpy_s(newClient->city, strlen(client.city) + 1, client.city);

	newClient->phone = client.phone;

	newClient->age = client.age;

	return newClient;
}

// Вставка нового клиента в таблицу
Client** Table::Insert(Client& newClient) {
	if (current - m < size) {
		*current++ = Copy(newClient);
		return current;
	}
	return NULL; // TODO: Предложение пользователю увеличить размер таблицы
	/*Resize(size);
	*current++ = Copy(newClient);
	return current;*/
}

// Ввод таблицы
int Table::Input() {
	// Выделение памяти под каждую ячейку таблицы
	for (int i = 0; i < size; i++)
		m[i] = new Client;

	// Установка указателя на первое свободное место в первую ячейку
	current = &m[0];

	// Ввод данных в таблицу
	for (int i = 0; i < size; i++) {
		Client newClient;
		newClient.input();
		Insert(newClient);
	}
	return !std::cin.eof();
}

// Вывод таблицы
void Table::Output() {
	bool flag = false;
	for (int i = 0; i < size; i++) {
		std::cout << "Client #" << i + 1 << std::endl;
		m[i]->output();
		flag = true;
		std::cout << std::endl;
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const Client& tempClient) {
	for (int i = 0; i < size; i++) {
		if (m[i]->equal(tempClient))
			return i;
	}
	return -1;
}

// Замена клиента в таблице
void Table::Replace(Client* newClient) {
	// Запрос старого клиента
	std::cout << std::endl << "Enter old client: " << std::endl;
	Client oldClient;
	oldClient.input();

	// Поиск и замена
	int index = Search(oldClient);
	while (index != -1) {
		delete m[index];

		m[index] = newClient;

		index = Search(oldClient);
	}
}

// Уменьшает размер таблицы после удаления клиентов
Client** SizeMinus(Client** myTable, int newsize) {
	Client** arr = new Client * [newsize];
	for (int i = 0; i < newsize; i++) {
		arr[i] = new Client;
		arr[i] = myTable[i];
	}
	return arr;
}

// Удаление всех вхождений
void Table::Remove(Client& badClient) {
	int index = Search(badClient);
	while (index != -1) {
		delete m[index];
		m[index] = NULL;
		for (int i = index; i < size - 1; i++) {
			m[i] = m[i + 1];
		}
		size--;
		current--;
		index = Search(badClient);
	}
	m = SizeMinus(m, size);
}
