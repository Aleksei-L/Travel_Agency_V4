#pragma once
#include <iostream>
#include <string.h>

class Client {
private:
	char* name; // Имя клиента
	char city[30]; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
public:
	Client();
	Client(const char* n, const char* c, int p, int a);
	Client(const Client& t);
	void dispose();
	~Client();
	int input();
	void output();
	int cmp(const Client& b);
	int equal(const Client& b);
	Client* copy();
};

typedef Client* T; // Теперь таблица работает с абстрактным типом T

class Table {
private:
	int size; // Размер таблицы
	T* m; // Таблица клиентов
	T* current; // Указатель на первый свободный в таблице
public:
	Table(int s);
	~Table();
	T* Begin();
	T* End();
	int Length();
	int GetSize();
	T* Erase(T* pos);
	void Clear();
	T* Insert(const T& newClient);
	int Input(T buf);
	void Output();
	void Sort();
	int Search(const T& tempClient);
	void Replace(const T& newClient, const T& oldClient);
	void Remove(const T& badClient);
};
