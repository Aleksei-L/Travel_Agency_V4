#include "Class.h"
#include <algorithm>

// Конструктор таблицы
Table::Table(int s) {
	current = m = new T[size = s];
}

// Деструктор таблицы
Table::~Table() {
	Clear();
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

// Удаление одного элемента в таблице (по индексу)
T* Table::Erase(T* pos) {
	(*pos)->dispose();
	for (T* i = pos; i < End(); i++)
		*i = *(i + 1);
	current--;
	return pos;
}

// Удаление всех элементов в таблице
void Table::Clear() {
	for (T* i = m; i < current; i++) {
		delete (*i);
	}
	current = m;
}

// Вставка нового клиента в таблицу
T* Table::Insert(const T& newClient) {
	if (Length() < size)
		*current++ = newClient->copy();
	return current;
}

// Ввод таблицы
int Table::Input(T item) {
	int count;
	for (count = 0; Length() != GetSize(); count++) {
		if (!item->input())
			break;
		Insert(item);
	}
	return count;
}

// Вывод таблицы
void Table::Output() {
	bool flag = false;
	int counter = 1;
	for (T* i = Begin(); i != End(); i++) {
		std::cout << "Client #" << counter++ << std::endl;
		(*i)->output();
		flag = true;
		std::cout << std::endl;
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < GetSize(); i++) {
		for (int j = i + 1; j < GetSize(); j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const T& tempClient) {
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*tempClient))
			return i - Begin();
	}
	return -1;
}

// Замена клиента в таблице
int Table::Replace(const T& oldClient, const T& newClient) {
	int counter = 0;
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*oldClient)) {
			(*i)->dispose();
			(*i) = (newClient)->copy();
			counter++;
		}
	}
	return counter;
}

// Удаление всех вхождений
int Table::Remove(const T& badClient) {
	T* i = Begin();
	int n = 0;
	for (T* j = Begin(); j < End(); j++) {
		if (!(*j)->equal(*badClient)) {
			*i++ = *j;
		}
		else {
			(*j)->dispose();
			n++;
		}
	}
	current = i;
	return n;
}
