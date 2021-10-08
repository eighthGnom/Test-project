 #include "Container.h"


Container::Container()
{
	size = 0;
}
Container::Container(PrintingHouse* obj)
{
	head = new(queue_ob);
	tail = head; 
	head->data = obj; 
	head->addr = NULL;
	size = 1;
}


void Container::push(PrintingHouse* obj)
{

	queue_ob* temp = new(queue_ob);
	temp->addr = NULL;
	temp->data = obj;
	if (size == 0)
	{ 
		head = tail = temp;
		size++;
	}
	else
	{ 
		tail->addr = temp;
		tail = temp;
		size++;
	}
	return;
}
void Container::pop(PrintingHouse* obj)//Удаляет элемент(выталкивает) и возвращает его
				 // По адресу, хранящемся в obj, передается значение удаляемой головы
{
	if (size == 0)
	{
		cout << "Очередь пуста - удалять нечего!" << endl;
		return;
	}
	queue_ob* temp = head; 
	*obj = *(head->data); 
	head = head->addr; 
	delete temp;
	size--;
	return;
}
void Container::pop()
{
	if (size == 0)
	{
		cout << "Очередь пуста - удалять нечего!" << endl;
		return;
	}
	queue_ob* temp = head;
	head = head->addr;
	if (head == NULL)
		tail = NULL;
	delete temp;
	size--;
	return;
}
void Container::pop_all()
{
	while (tail != NULL)
		pop();
	return;
}
void Container::peek(PrintingHouse* obj)//Выгружает значение по адресу, передаваемому в парметре
{
	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
		return;
	}
	*obj = *(head->data);
	return;
}
void Container::sort()
{
	if (size == 0)
	{
		cout << "Очередь пуста - сортировать нечего!" << endl;
		return;
	}
	int temp_size = size;
	PrintingHouse** temp_array = new PrintingHouse * [size];
	for (int i = 0; i < temp_size; i++)
	{
		temp_array[i] = head->data;
		pop();
	}
	for (int i = 0; i < temp_size; i++)

	{
		for (int j = i + 1; j < temp_size; j++)
		{
			if (temp_array[i]->get_title() > temp_array[j]->get_title())
			{

				swap(temp_array[i], temp_array[j]);
			}
		}

	}
	for (int i = 0; i < temp_size; i++)
		push(temp_array[i]);
	cout << "Контейнер отсортирован!" << endl;
	return;
}


void Container::print_all()
{
	cout << endl;
	if (size == 0)
	{
		cout << "Очередь пуста - выводить нечего!" << endl;
		return;
	}
	else
	{
		queue_ob* temp = head;
		while (temp != NULL)
		{
			cout << endl;
			cout << *(temp->data);
			temp = temp->addr;
		}
	}
	return;
}



int Container::test()
{
	if (size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



void Container::request_sub(string sub)
{
	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
		return;
	}
	else
	{
		int txb_count = 0;
		queue_ob* temp = head;
		while (temp != NULL)
		{
			if (typeid(*(temp->data)) == typeid(Textbook))
			{
				if (((Textbook*)(temp->data))->get_subject() == sub)
				{
					cout << *(temp->data);
					txb_count++;
				}
			}
			temp = temp->addr;
		}
		cout << "В контейнере " << txb_count << " учебников по заданому предмету.\n" << 
			"Информация о них выведена сверху." << endl;
		return;
	}
}


void Container::read_from_file()
{

	string path;
	cout << "Введите название файла, или путь: "; // Закоментировать для тестов
	getline(cin, path);
	//path = "data.txt";
	fstream fs;
	fs.open(path, fstream::in);
	if (fs.is_open())
	{
		string line;
		Textbook* t_book;
		FictionBook* f_book;
		
		while (!fs.eof())
		{
			fs >> line;
			if (line == "textbook")
			{
				t_book = new Textbook();
				fs >> *t_book;
				this->push(t_book);
			}
			else if (line == "fictionbook")
			{
				f_book = new FictionBook();
				fs >> *f_book;
				this->push(f_book);
			}
			else
			{
				cout << "СЧИТАНО С ОШИБКОЙ" << endl;
				break;
			}

			line.clear();
		}
		cout << "Данные считаны с файла!" << endl;
		return;
	}
	else
	{
		cout << "ОШИБКА ОТКРЫТИЯ ФАЙЛА!" << endl;
		return;
	}
}
void Container::write_to_file()
{
	if (size == 0)
	{
		cout << "Очередь пуста - нечего сохранять!" << endl;
		return;
	}
	else
	{
		string path;
		cout << "Введите название файла, или путь: ";
		getline(cin, path);
		fstream fs;
		fs.open(path, fstream::out | fstream::app);
		if (fs.is_open())
		{
			queue_ob* temp = head;
			while (temp != NULL)
			{
				if (typeid(*(temp->data)) == typeid(Textbook))
				{
					fs << "textbook" << endl;
					fs << (*((Textbook*)(temp->data)));
				}
				if (typeid(*(temp->data)) == typeid(FictionBook))
				{
					fs << "fictionbook" << endl;
					fs << (*((FictionBook*)(temp->data)));
				}
				temp = temp->addr;
			}
			cout << "Данные записаны в файл!" << endl;
		}
		else
			cout << "ОШИБКА ОТКРЫТИЯ ФАЙЛА!" << endl;
		return;
	}
	return;
}