#include "document.h"

//again, this default constructor creates a passport filled with default data for testing purposes
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

void passport::setSex(bool newsex)
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

void passport::setHeight(unsigned int newHeight)
{
	height = newHeight;
}

void passport::setWeight(unsigned int newWeight)
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

bool  &passport::getSex()
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
		if (1 == 2 || i == 5)
		{
		}
		else if (!(rand() % (100 / odds)) && valid != false)
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
		if (!(rand() % (100 / odds)) && valid != false && i != 2 && i != 5)
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
void passport::print_all()
{
	std::cout << IDno << endl;
	std::cout << DoB << endl;
	std::cout << sex << endl;
	std::cout << firstN << endl;
	std::cout << lastN << endl;
	std::cout << height << endl;
	std::cout << weight << endl;
	std::cout << date << endl;
	std::cout << country << endl << endl;
}


void passport::draw(sf::RenderWindow & window)
{
	
	
	string sex_str;
	sf::Font normal;
	sf::Font bold;
	
	if (!normal.loadFromFile("DejaVuSansMono.ttf"))
	{
		// Error...
	}
	if (bold.loadFromFile("DejaVuSansMono-Bold.ttf"))
	{
		//Error
	}

	sf::RectangleShape card(sf::Vector2f(200, 130));
	sf::Text static_info_IDno("ID: ", bold, 30); // says id is bold,30 pixels
	sf::Text static_info_DOB("DOB: ", bold, 30); //These are constants for all id
	sf::Text static_info_SEX("SEX: ", bold, 30);
	sf::Text static_info_FIRST("FIRST: ", bold, 30);
	sf::Text static_info_LAST("LAST: ", bold, 30);
	sf::Text static_info_HEIGHT("HEIGHT: ", bold, 30);
	sf::Text static_info_WEIGHT("WEIGHT: ", bold, 30);
	sf::Text static_info_EXPD("EXP DATE: ", bold, 30);
	sf::Text static_info_COUNTRY("COUNTRY: ", bold, 30); //need to set position
														 //	
														 //	
	static_info_IDno.setPosition(100, 10);
	static_info_DOB.setPosition(100, 15);
	static_info_SEX.setPosition(100, 20);
	static_info_FIRST.setPosition(100, 25);
	static_info_LAST.setPosition(100, 30);
	static_info_HEIGHT.setPosition(100, 35);
	static_info_WEIGHT.setPosition(100, 40);
	static_info_EXPD.setPosition(100, 45);
	static_info_COUNTRY.setPosition(100, 50);
	//	
	sf::Text IDno_draw;
	sf::Text DOB_draw;
	sf::Text sex_draw;
	sf::Text firstN_draw;
	sf::Text lastN_draw;
	sf::Text height_draw;
	sf::Text weight_draw;
	sf::Text date_draw;
	sf::Text country_draw;
	window.display();
	//	
	IDno_draw.setFont(normal);
	DOB_draw.setFont(normal);
	sex_draw.setFont(normal);
	firstN_draw.setFont(normal);
	lastN_draw.setFont(normal);
	height_draw.setFont(normal);
	weight_draw.setFont(normal);
	date_draw.setFont(normal);
	//	coutry_draw.setFont(normal);
	//		
	IDno_draw.setPosition(200, 10);
	DOB_draw.setPosition(200, 15);
	sex_draw.setPosition(200, 20);
	firstN_draw.setPosition(200, 25);
	lastN_draw.setPosition(200, 30);
	height_draw.setPosition(200, 35);
	weight_draw.setPosition(200, 45);
	date_draw.setPosition(200, 50);
	//coutry_draw.setPosition();
	//	
	IDno_draw.setCharacterSize(25);
	DOB_draw.setCharacterSize(25);
	sex_draw.setCharacterSize(25);
	firstN_draw.setCharacterSize(25);
	lastN_draw.setCharacterSize(25);
	height_draw.setCharacterSize(25);
	weight_draw.setCharacterSize(25);
	date_draw.setCharacterSize(25);
	//coutry_draw.setCharacterSize(25);
	//		
	IDno_draw.setString(IDno);
	DOB_draw.setString(DoB);
	if (sex == true)
	{
		sex_str = "m";
	}
	else
	{
		sex_str = "f";
	}
	sex_draw.setString(sex_str);
	firstN_draw.setString(firstN);
	lastN_draw.setString(lastN);
	height_draw.setString(height);
	weight_draw.setString(weight);
	date_draw.setString(date);
	//coutry_draw.setString(country);
	//		
	window.draw(IDno_draw);
	window.draw(DOB_draw);
	window.draw(sex_draw);
	window.draw(firstN_draw);
	window.draw(lastN_draw);
	window.draw(height_draw);
	window.draw(weight_draw);
	window.draw(date_draw);
	//window.draw(coutry_draw);
	
}

