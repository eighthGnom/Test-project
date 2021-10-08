#pragma once
#include "PrintingHouse.h"


class FictionBook : public PrintingHouse
{
private:
	string gener;
	float rating;
	static int f_ex_count;

public:
	FictionBook();
	FictionBook(string _title, string _authors_pib, string _language, unsigned int _pages, unsigned int _year,
		double _price, string _gener, float _rating);
	~FictionBook();


	void set_gener(string _gener);
	void set_rating(float _rating);


	static int get_f_ex_count();
	string get_gener();
	float get_rating();

	void write_to_file(fstream& obj) override;
	void read_from_file(fstream& obj) override;
	void write_to_console() override;
	void read_from_console() override;
};

