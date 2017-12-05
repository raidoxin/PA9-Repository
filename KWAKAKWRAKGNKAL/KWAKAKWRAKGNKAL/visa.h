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
	void corrupt_destination_Country(int odds);
	void corrupt_destination_City(int odds);
	void corrupt_visatype(int odds);
	//void visa_mastercorrupt(int odds);
	\
		//draw function
	void	draw(sf::RenderWindow & window);
};