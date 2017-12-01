#include "IDcard.h"

void IDcard::setexpire(string & newexpire)
{
	expiredate = newexpire;
}

void IDcard::setcity(string & newcity)
{
	city = newcity;
}

string & IDcard::getExp()
{
	return expiredate;
}

string & IDcard::getCity()
{
	return city;
}

void IDcard::print_all()
{
	std::cout << this->getID() << std::endl
		<< this->getFirstN() << std::endl
		<< this->getLastN() << std::endl
		<< this->getDoB() << std::endl
		<< this->getSex() << std::endl
		<< this->getCountry() << std::endl
		<< city << std::endl
		<< expiredate << std::endl;

}

passport & IDcard::operator=(passport & copied)
{
	this->setID(copied.getID());
	this->setBirth(copied.getDoB());
	this->setSex(copied.getSex());
	this->setFirst(copied.getFirstN());
	this->setLast(copied.getLastN());
	this->setHeight(copied.getHeight());
	this->setWeight(copied.getWeight());
	this->setDate(copied.getDate());
	this->setCountry(copied.getCountry());
	return *this;
}
