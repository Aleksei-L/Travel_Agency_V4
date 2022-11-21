#include <algorithm>
#include "Class.h"

// Конструктор таблицы
Table::Table(int s) {
	current = m = new T[size = s];
}

// Деструктор таблицы
Table::~Table() {
	delete[] m;
}

// Возвращает указатель на первый элемент таблицы
T* Table::Begin() {
	return m;
}

// Возвращает указатель на первый свободный элемент таблицы
T* Table::End() {
	return current;
}

// Возвращает размер заполненной части таблицы
int Table::Length() {
	return current - m;
}

// Возвращает общий размер таблицы
int Table::GetSize() {
	return size;
}

// Вставка нового клиента в таблицу
T* Table::Insert(const T& newClient) {
	if (Length() < size)
		*current++ = newClient->copy();
	return current;
}

// Ввод таблицы
int Table::Input(T buf) {
	int count;
	for (count = 0; count < GetSize() && buf->input(); count++)
		Insert(buf);
	return count;
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
//int Table::Search(const T& tempClient) {
//	for (int i = 0; i < size; i++) {
//		if (m[i]->equal(tempClient))
//			return i;
//	}
//	return -1;
//}

// Замена клиента в таблице
//void Table::Replace(const T& oldClient, const T& newClient) {
//	int index = Search(oldClient);
//	while (index != -1) {
//		delete m[index];
//
//		m[index] = newClient;
//
//		index = Search(oldClient);
//	}
//}

//// Уменьшает размер таблицы после удаления клиентов
//Client** SizeMinus(Client** myTable, int newsize) {
//	Client** arr = new Client * [newsize];
//	for (int i = 0; i < newsize; i++) {
//		arr[i] = new Client;
//		arr[i] = myTable[i];
//	}
//	return arr;
//}

// Удаление всех вхождений
//void Table::Remove(const T& badClient) {
//	int index = Search(badClient);
//	while (index != -1) {
//		delete m[index];
//		m[index] = NULL;
//		for (int i = index; i < size - 1; i++) {
//			m[i] = m[i + 1];
//		}
//		size--;
//		current--;
//		index = Search(badClient);
//	}
//	//m = SizeMinus(m, size);
//}
