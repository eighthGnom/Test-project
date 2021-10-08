#pragma once
#include "Container.h"


class Menu {
private:
	Menu() = default;
	Container* container;
	void display();
public:
	static Menu& instance();
	void Run();


};