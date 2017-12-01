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
void orders::corrupt_mission(int odds)
{
	for (int i = 0; i < mission.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			mission[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void orders::corrupt_validdate(int odds)
{
	for (int i = 0; i < validdate.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false && i != 2 && i != 5)
		{
			validdate[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void orders::orders_mastercorrupt(int odds)
{
	orders::corrupt_validdate(odds);
	orders::corrupt_mission(odds);

}
