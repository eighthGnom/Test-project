#include "PrintingHouse.h"


PrintingHouse::PrintingHouse(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year, double _price)
{
    title = _title;
    authors_pib = _authors_pib;
    language = _language;
    pages = _pages;
    year = _year;
    price = _price;
}


void PrintingHouse::set_title(string _title) 
{
    title = _title;
}
void PrintingHouse::set_authors_pib(string _authors_pib)
{
    authors_pib = _authors_pib;
}
void PrintingHouse::set_language(string _language)
{
    language = _language;
}
void PrintingHouse::set_pages(unsigned int _pages)
{
    pages = _pages;
}
void PrintingHouse::set_year(unsigned int _year)
{
    year = _year;
}
void PrintingHouse::set_price(double _price)
{
    price = _price;
}


string PrintingHouse::get_title()
{
    return title;
}
string PrintingHouse::get_authors_pib()
{
    return authors_pib;
}
string PrintingHouse::get_language()
{
    return language;
}
unsigned int PrintingHouse::get_pages()
{
    return pages;
}
unsigned int PrintingHouse::get_year()
{
    return year;
}
double PrintingHouse::get_price()
{
    return price;
}


void PrintingHouse::write_to_file(fstream& obj)
{
    obj << title << "\n" << authors_pib <<
        "\n" << language << "\n" << pages <<
        "\n" << year << "\n" << price << endl;
}
void PrintingHouse::read_from_file(fstream& obj)
{
    obj.ignore();
    getline(obj, title);
    getline(obj, authors_pib);
    getline(obj, language);
    obj >> pages;
    obj >> year;
    obj >> price;
}
void PrintingHouse::write_to_console()
{
    cout << "Название: " << title << "\nФИО Автора: " << authors_pib <<
        "\nЯзык: " << language << "\nКоличество страниц: " << pages <<
        "\nГод написания: " << year << "\nРекомедованная цена: " << price << endl;
}
void PrintingHouse::read_from_console()
{
    cout << "Введите название книги: ";
    getline(cin, title);
    cout << "Введите ФИО автора: ";
    getline(cin, authors_pib);
    cout << "Введите язык: ";
    getline(cin, language);
    cout << "Введите количество страниц: ";
    while (!(cin >> pages) && pages <= 0)
    {
        cout << "Ошибка, попробуйте еще: ";
        cin.clear();
        rewind(stdin);
    }
    cout << "Введите год написания: ";
    cin >> year;
    cout << "Введите рекомедованную стоимость: ";
    while (!(cin >> price) && price <= 0)
    {
        cout << "Ошибка, попробуйте еще: ";
        cin.clear();
        rewind(stdin);
    }
}


ostream& operator << (ostream& os, PrintingHouse& other)
{
    other.write_to_console();
    return os;
}
fstream& operator << (fstream& ofs, PrintingHouse& other)
{
    other.write_to_file(ofs);
    return ofs;
}
istream& operator >> (istream& is, PrintingHouse& other)
{
    other.read_from_console();
    return is;
}
fstream& operator >> (fstream& ifs, PrintingHouse& other)
{
    other.read_from_file(ifs);
    return ifs;
}