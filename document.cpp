#include "document.h"

//again, this default constructor creates a passport fiolled with default data for testing purposes
passport::passport()
{
	IDno = "8675309";
	DoB = "20APR1969";
	sex = true;
	firstN = "Suq";
	lastN = "Madiq";
	height = 200;
	weight = 69;
	date = "07AUG1999";
	country = "Vastlund";
	valid = true;
}

passport & passport::operator=(passport & copied)
{
	//check for self assign
	if (this != &copied) {
		this->setID(copied.getID());
		this->setBirth(copied.getDoB());
		this->setSex(copied.getSex());
		this->setFirst(copied.getFirstN());
		this->setLast(copied.getLastN());
		this->setHeight(copied.getHeight());
		this->setWeight(copied.getWeight());
		this->setDate(copied.getDate());
		this->setCountry(copied.getCountry());
	}
	return *this;
}

void passport::setID(string & newID)
{
	IDno = newID;
}

void passport::setBirth(string & newDoB)
{
	DoB = newDoB;
}

void passport::setSex(bool & newsex)
{
	sex = newsex;
}

void passport::setFirst(string & newFirst)
{
	firstN = newFirst;
}

void passport::setLast(string & newLast)
{
	lastN = newLast;
}

void passport::setHeight(unsigned int & newHeight)
{
	height = newHeight;
}

void passport::setWeight(unsigned int & newWeight)
{
	weight = newWeight;
}

void passport::setDate(string & newDate)
{
	date = newDate;
}

void passport::setCountry(string & newCountry)
{
	country = newCountry;
}

string & passport::getID()
{
	return IDno;
}

string & passport::getDoB()
{
	return DoB;
}

bool & passport::getSex()
{
	return sex;
}

string & passport::getFirstN()
{
	return firstN;
}

string & passport::getLastN()
{
	return lastN;
}

unsigned & passport::getHeight()
{
	return height;
}

unsigned & passport::getWeight()
{
	return weight;
}

string & passport::getDate()
{
	return date;
}

string & passport::getCountry()
{
	return country;
}

bool passport::isValid()
{
	return false;
}

//Corruptor declerations
void passport::corruptIdno(int odds)
{
	for (int i = 0; i < IDno.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			IDno[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void passport::corruptDob(int odds)
{
	for (int i = 0; i < DoB.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			DoB[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void passport::corruptsex(int odds)
{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			sex = !sex;
			valid = false;
		}
}
void passport::corruptfirstN(int odds)
{
	for (int i = 0; i < firstN.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			firstN[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void passport::corruptlastN(int odds)
{
	for (int i = 0; i < lastN.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			lastN[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void passport::corruptheight(int odds)
{

		if (!(rand() % (100 / odds)) && valid != false)
		{
			height += rand() % 20;
			valid = false;
		}

}
void passport::corruptweight(int odds)
{

	if (!(rand() % (100 / odds)) && valid != false)
	{
		weight += rand() % 50;
		valid = false;
	}
}
void passport::corruptdate(int odds)
{
	for (int i = 0; i < date.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			date[i] = 97 + rand() % 26;
			valid = false;
		}
		
	}
}
void passport::corruptcountry(int odds)  //will finish with country choice randomizer
{
	{
		for (int i = 0; i < country.length(); i++)
		{
			if (!(rand() % (100 / odds)) && valid != false)
			{
				country[i] = 97 + rand() % 26;
				valid = false;
			}

		}
	}
}
void passport::master_corruptor(int odds)//public corruptor
{
	passport::corruptIdno(odds);
	passport::corruptDob(odds);
	passport::corruptsex(odds);
	passport::corruptfirstN(odds);
	passport::corruptlastN(odds);
	passport::corruptheight(odds);
	passport::corruptweight(odds);
	passport::corruptdate(odds);
	passport::corruptcountry(odds);
	if (valid == false)
	{
		std::cout << "DATA was corrupted" << std::endl;

	}
	else
	{
		std::cout << "Data was not corrupted" << std::endl;
	}
}