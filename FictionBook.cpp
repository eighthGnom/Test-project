#include "FictionBook.h"


int FictionBook::f_ex_count = 0;
FictionBook::FictionBook()
{
    f_ex_count++;
}
FictionBook::FictionBook(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year,
	double _price, string _gener, float _rating)
{
    title = _title;
    authors_pib = _authors_pib;
    language = _language;
    pages = _pages;
    year = _year;
    price = _price;
    gener = _gener;
    rating = _rating;
    f_ex_count++;
}
FictionBook::~FictionBook()
{
    f_ex_count--;
}


void FictionBook::set_gener(string _gener)
{
    gener = _gener;
}
void FictionBook::set_rating(float _rating)
{
    rating = _rating;
}


int FictionBook::get_f_ex_count()
{
    return f_ex_count;
}
string FictionBook::get_gener()
{
    return gener;
}
float FictionBook::get_rating()
{
    return rating;
}


void FictionBook::write_to_file(fstream& obj)
{
    PrintingHouse::write_to_file(obj);
    obj << gener << "\n" << rating << endl;
}
void FictionBook::read_from_file(fstream& obj)
{
    PrintingHouse::read_from_file(obj);
    obj.ignore();
    getline(obj, gener);
    obj >> rating;
}
void FictionBook::write_to_console()
{
    PrintingHouse::write_to_console();
    cout << "Жанр: " << gener << "\nРейтинг: " << rating << endl;
}
void FictionBook::read_from_console()
{
    PrintingHouse::read_from_console();
    cout << "Введите жанр книги (для учета регистр и язык должни совпадать): ";
    cin.ignore();
    getline(cin, gener);
    cout << "Введите рейтинг книги: ";
    while (!(cin >> rating) && rating <= 0)
    {
        cout << "Ошибка, попробуйте еще: ";
        cin.clear();
        rewind(stdin);
    }
}