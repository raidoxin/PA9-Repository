#pragma once
#include"document.h"


class IDcard : public passport {

private:
	string expiredate;
	string city;

public:
	//setters
	void setexpire(string & newexpire);
	void setcity(string & newcity);

	//getters
	string & getExp();
	string & getCity();

	// print override prints relevant document data;
	void print_all();

	//operator overload for quick copy of document data;
	passport & operator=(passport & copied);
};