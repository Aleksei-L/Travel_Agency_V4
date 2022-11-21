#pragma once
#include <iostream>

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
	int cmp(const Client& t);
	int equal(const Client& t);
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
	int Input(T item);
	void Output();
	void Sort();
	int Search(const T& tempClient);
	int Replace(const T& oldClient, const T& newClient);
	int Remove(const T& badClient);
};
