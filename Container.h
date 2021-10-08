#pragma once
#include "PrintingHouse.h"
#include "FictionBook.h"
#include "Textbook.h"


class Container
{
private:
	struct queue_ob// Структура для хранения элементов очереди
	{
		PrintingHouse* data;//Поле для хранения значения элемента очереди
		queue_ob* addr; // Поле для хранения слеющего элемента
	};

	queue_ob* head; // указатель, хранящий адресс головы очереди
	queue_ob* tail; // Указатель хранящий адрес хвоста
	int size; //Текущий размер очереди


public:
	Container(PrintingHouse* obj);
	Container();
	~Container() = default;


	void push(PrintingHouse* obj);
	void pop(PrintingHouse* obj);
	void pop();
	void peek(PrintingHouse* obj);
	void pop_all();
	void sort();

	int test();

	void print_all();


	void request_sub(string sub);


	void write_to_file();
	void read_from_file();
};