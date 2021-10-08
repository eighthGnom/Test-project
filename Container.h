#pragma once
#include "PrintingHouse.h"
#include "FictionBook.h"
#include "Textbook.h"


class Container
{
private:
	struct queue_ob// ��������� ��� �������� ��������� �������
	{
		PrintingHouse* data;//���� ��� �������� �������� �������� �������
		queue_ob* addr; // ���� ��� �������� �������� ��������
	};

	queue_ob* head; // ���������, �������� ������ ������ �������
	queue_ob* tail; // ��������� �������� ����� ������
	int size; //������� ������ �������


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