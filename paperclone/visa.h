#pragma once
#include"document.h"

class visa : public passport {

private:
	string destinationCountry;
	string destinationCity;
	string visatype;

public:
	
	string & getDestCountry();
	string & getDestCity();
	string & getVisatype();

	void setDestCountry(string & newnation);
	void setDestCity(string & newcity);
	void setVisaType(string & newtype);

	void print_all();

	visa & operator=(passport & copied);

};