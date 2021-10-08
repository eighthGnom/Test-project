#include "Menu.h"
#include <conio.h>


Menu& Menu::instance()
{
	static Menu instance;
	return instance;
}
void Menu::display()
{
	cout << "-------------MENU---------------" << endl;
	cout << "<l>.Добавить учебник" << endl;
	cout << "<2>.Добавить художественную книгу" << endl;
	cout << "<3>.Отобразить все книги в очереди" << endl;
	cout << "<4>.Удалить все книги в очереди" << endl;
	cout << "<5>.Удалить первый элемент очереди" << endl;
	cout << "<6>.Сохранить данные в файл" << endl;
	cout << "<7>.Загрузить данные с файла" << endl;
	cout << "<8>.Сортировать очередь" << endl;
	cout << "<9>.Подсчитать общее количество учебников по заданному предмету" << endl;
	cout << "<0>.Выход" << endl;
}


void Menu::Run()
{
	Textbook* t_book;
	FictionBook* f_book;
	container = new Container();
	char exit = '?';
	while (exit != '0')
	{
		cin.clear();
		rewind(stdin);

		string sub;
		display();
		cout << "Нажмите на клавиатуре номер выбраного поля"<< endl;
		exit = _getch();
		switch (exit)
		{
		case '1':
			t_book = new Textbook();
			cin >> *t_book;
			container->push(t_book);
			break;

		case '2':
			f_book = new FictionBook();
			cin >> *f_book;
			container->push(f_book);
			break;

		case '3':
			container->print_all();
			break;

		case '4':
			container->pop_all();
			break;

		case '5':
			container->pop();
			break;

		case '6':
			container->write_to_file();
			break;

		case '7':
			container->read_from_file();
			break;

		case '8':
			container->sort();
			break;

		case '9':
			cout << "Введите название предмета: "; 
			getline(cin, sub);
			container->request_sub(sub);
			break;

		default:
			cout << "Ошибка, попробуйте еще." << endl;
			cin.clear();
			rewind(stdin);
			break;
		}
	}

	
}


