#include "visa.h"

string & visa::getDestCountry()
{
	return destinationCountry;
}

string & visa::getDestCity()
{
	return destinationCity;
}

string & visa::getVisatype()
{
	return visatype;
}

void visa::setDestCountry(string & newnation)
{
	destinationCountry = newnation;
}

void visa::setDestCity(string & newcity)
{
	destinationCity = newcity;
}

void visa::setVisaType(string & newtype)
{
	visatype = newtype;
}

void visa::print_all()
{
	std::cout << this->getID() << std::endl
		<< this->getLastN() << std::endl
		<< this->getFirstN() << std::endl
		<< this->getSex() << std::endl
		<< destinationCountry << std::endl
		<< destinationCity << std::endl
		<< visatype << std::endl;
}

visa & visa::operator=(passport & copied)
{
	this->setFirst(copied.getFirstN());
	this->setLast(copied.getLastN());
	this->setSex(copied.getSex());
	return *this;
}

