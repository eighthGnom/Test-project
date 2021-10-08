#include"Menu.h"
#include<Windows.h>
#pragma warning(disable : 4996)

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu m = Menu::instance();
	m.Run();
	return 0;
}