#pragma once
#include <iostream>
#include <string.h>

// Прототип класса Client, т. к. он используется в классе Table до объявления самого класса Client
class Client;

class Table {
private:
	int size; // Размер таблицы
	Client** m; // Таблица клиентов
	Client** current; // Указатель на первый свободный в таблице
public:
	Table(int s);
	~Table();
	Client* Copy(Client& client);
	Client** Insert(Client& newClient);
	int Input();
	void Output();
	void Sort();
	int Search(const Client& tempClient);
	void Replace(Client* newClient);
	void Remove(Client& badClient);
};

class Client {
private:
	char* name; // Имя клиента
	char city[30]; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
public:
	Client();
	Client(const char* n, const char* c, int p, int a);
	~Client();
	int input();
	void output();
	int cmp(const Client& b);
	int equal(const Client& b);
	friend Client* Table::Copy(Client& client);
	friend void Table::Replace(Client* newClient);
	friend void Table::Remove(Client& badClient);
};
