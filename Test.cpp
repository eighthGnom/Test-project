#define BOOST_TEST_MODULE mytests
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include "Container.h"

BOOST_AUTO_TEST_SUITE(TestCase)

BOOST_AUTO_TEST_CASE(Add_textbook)
{
	Container* container = new Container();
	Textbook* book = new Textbook("Title", "Name Surname Lastname", "LANGUAGE", 999, 2021, 99.99, "Subject", 9);
	container->push(book);
	BOOST_REQUIRE_EQUAL(container->test(), 1);
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(Add_fictionbook)
{
	Container* container = new Container();
	FictionBook* book = new FictionBook("Название", "Фамилия Имя Отчество ", "Язык", 999, 2021, 99.99, "Жанр", 9);
	container->push(book);
	BOOST_REQUIRE_EQUAL(container->test(), 1);
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(Pop_elements)
{
	Container* container = new Container();
	FictionBook* book1 = new FictionBook("Title", "Name, Surname Lastname", "LANGUAGE", 999, 2021, 99.99, "Gener",9.99);
	Textbook* book2 = new Textbook("Название", "Фамилия Имя Отчество ", "Язык", 999, 2021, 99.99, "предмет",9);
	container->push(book2);
	container->push(book1);
	BOOST_REQUIRE_EQUAL(container->test(), 1);
	container->pop_all();
	BOOST_REQUIRE_EQUAL(container->test(), 0); // Контейнер повинен стати пустим
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(LoadTest)
{
	Container* container = new Container();
	BOOST_REQUIRE_EQUAL(container->test(), 0); // При створенні контейнер має бути пустим
	container->read_from_file();
	BOOST_REQUIRE_EQUAL(container->test(), 1); // В контенері повинні бути книги
}


BOOST_AUTO_TEST_SUITE_END()