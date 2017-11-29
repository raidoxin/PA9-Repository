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
void visa::corrupt_destination_Country(int odds)
{
	for (int i = 0; i < destinationCountry.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			destinationCity[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void visa::corrupt_destination_City(int odds)
{
	for (int i = 0; i < destinationCity.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			destinationCity[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void visa::corrupt_visatype(int odds)
{
	for (int i = 0; i < visatype.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			visatype[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void visa_mastercorrupt(int odds)
{
	visa::corrupt_destination_City(odds);
	visa::corrupt_destination_Country(odds);
	visa::corrupt_visatype(odds);

}
