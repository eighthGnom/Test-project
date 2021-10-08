#pragma once
#include "PrintingHouse.h"


class Textbook : public PrintingHouse
{
private:
	string subject;
	int year_of_study;
	static int t_ex_count;


public:
	Textbook();
	Textbook(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year,
		double _price, string _subject, int _year_of_study);
	~Textbook();


	void set_subject(string _subject);
	void set_year_of_study(int _rating);

	static int get_t_ex_count();
	string get_subject();
	int get_year_of_study();


	void write_to_file(fstream& obj) override;
	void read_from_file(fstream& obj) override;
	void write_to_console() override;
	void read_from_console() override;;

};