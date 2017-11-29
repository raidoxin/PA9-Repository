#include "orders.h"

string & orders::getmission()
{
	return mission;
}

string & orders::getvailiddate()
{
	return validdate;
}

void orders::setmission(string & newmission)
{
	mission = newmission;
}

void orders::setvaliddate(string newdate)
{
	validdate = newdate;
}

void orders::print_all()
{
	std::cout << this->getDestCity() << std::endl
		<< this->getDestCountry() << std::endl
		<< mission << std::endl
		<< validdate << std::endl;
}

//operator overload for copying relevant information from the visa
//changes the visa so that it always displays "Military" as its reason if this is invoked
orders & orders::operator=(visa & thevisa)
{
	this->setDestCountry(thevisa.getDestCountry());
	this->setDestCity(thevisa.getDestCity());
	thevisa.setVisaType((string)"Military");
	return *this;
}
