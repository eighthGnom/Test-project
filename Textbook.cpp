#include "Textbook.h"


int Textbook::t_ex_count = 0;
Textbook::Textbook()
{
    t_ex_count++;
}
Textbook::Textbook(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year,
    double _price, string _subject, int _year_of_study)
{
    title = _title;
    authors_pib = _authors_pib;
    language = _language;
    pages = _pages;
    year = _year;
    price = _price;
    subject = _subject;
    year_of_study = _year_of_study;
    t_ex_count++;
}
Textbook::~Textbook()
{
    t_ex_count--;
}


void Textbook::set_subject(string _subject)
{
    subject = _subject;
}
void Textbook::set_year_of_study(int _year_of_study)
{
    year_of_study = _year_of_study;
}


int Textbook::get_t_ex_count()
{
    return t_ex_count;
}

string Textbook::get_subject()
{
    return subject;
}
int Textbook::get_year_of_study()
{
    return year_of_study;
}


void Textbook::write_to_file(fstream& obj)
{
    PrintingHouse::write_to_file(obj);
    obj << subject << "\n" << year_of_study << endl;
}
void Textbook::read_from_file(fstream& obj)
{
    PrintingHouse::read_from_file(obj);
    obj.ignore();
    getline(obj, subject);
    obj >> year_of_study;
}
void Textbook::write_to_console()
{
    PrintingHouse::write_to_console();
    cout << "Предмет: " << subject << "\nГод обучения: " << year_of_study << endl;
}
void Textbook::read_from_console()
{
    PrintingHouse::read_from_console();
    cout << "Введите предмет обучения (для учета регистр и язык должни совпадать): ";
    cin.ignore();
    getline(cin, subject);
    cout << "Введите год обучения: ";
    while (!(cin >> year_of_study) && year_of_study <= 0)
    {
        cout << "Ошибка, попробуйте еще: ";
        cin.clear();
        rewind(stdin);
    }

}