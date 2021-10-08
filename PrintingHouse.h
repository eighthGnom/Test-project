#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PrintingHouse
{
protected:
    string title;
    string authors_pib;
    string language;
    unsigned int pages;
    unsigned int year;
    double price;

public:
    PrintingHouse(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year, double _price);
    PrintingHouse() = default;
    virtual ~PrintingHouse() = default;

    void set_title(string _title);
    void set_authors_pib(string _authors_pib);
    void set_language(string _language);
    void set_pages(unsigned int _pages);
    void set_year(unsigned int _year);
    void set_price(double _price);

    string get_title();
    string get_authors_pib();
    string get_language();
    unsigned int get_pages();
    unsigned int get_year();
    double get_price();


    virtual void write_to_file(fstream& obj);
    virtual void read_from_file(fstream& obj);
    virtual void write_to_console();
    virtual void read_from_console();
  

    friend ostream& operator << (ostream& os, PrintingHouse& other);
    friend fstream& operator << (fstream& ofs, PrintingHouse& other);
    friend istream& operator >> (istream& is, PrintingHouse& other);
    friend fstream& operator >> (fstream& ifs, PrintingHouse& other);
};