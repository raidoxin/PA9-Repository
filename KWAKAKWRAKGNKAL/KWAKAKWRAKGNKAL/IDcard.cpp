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

void IDcard::draw(sf::RenderWindow & window)
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

	sf::RectangleShape card(sf::Vector2f(700, 600));
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
	static_info_IDno.setPosition(200, 50);
	static_info_DOB.setPosition(200, 100);
	static_info_SEX.setPosition(200, 150);
	static_info_FIRST.setPosition(200, 200);
	static_info_LAST.setPosition(200, 250);
	static_info_HEIGHT.setPosition(200, 300);
	static_info_WEIGHT.setPosition(200, 350);
	static_info_EXPD.setPosition(200, 400);
	static_info_COUNTRY.setPosition(200, 450);
	card.setFillColor(sf::Color::Blue);
	card.setPosition(170, 20);
	//for id class	
	sf::Text static_info_ID_EXP("ID EXP DATE: ", bold, 30);
	sf::Text static_info_CITY("CITY: ", bold, 30);
	static_info_ID_EXP.setPosition(200, 500);
	static_info_CITY.setPosition(200, 550);

	sf::Text IDno_draw;
	sf::Text DOB_draw;
	sf::Text sex_draw;
	sf::Text firstN_draw;
	sf::Text lastN_draw;
	sf::Text height_draw;
	sf::Text weight_draw;
	sf::Text date_draw;
	sf::Text country_draw;
	sf::Text id_exp_draw;
	sf::Text city_draw;
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
	country_draw.setFont(normal);
	id_exp_draw.setFont(normal);
	city_draw.setFont(normal);
	//		

	IDno_draw.setPosition(700, 50);
	DOB_draw.setPosition(700, 100);
	sex_draw.setPosition(700, 150);
	firstN_draw.setPosition(700, 200);
	lastN_draw.setPosition(700, 250);
	height_draw.setPosition(700, 300);
	weight_draw.setPosition(700, 350);
	date_draw.setPosition(700, 400);
	country_draw.setPosition(700, 450);
	id_exp_draw.setPosition(700, 500);
	city_draw.setPosition(700, 550);
	//	
	IDno_draw.setCharacterSize(25);
	DOB_draw.setCharacterSize(25);
	sex_draw.setCharacterSize(25);
	firstN_draw.setCharacterSize(25);
	lastN_draw.setCharacterSize(25);
	height_draw.setCharacterSize(25);
	weight_draw.setCharacterSize(25);
	date_draw.setCharacterSize(25);
	country_draw.setCharacterSize(25);
	id_exp_draw.setCharacterSize(25);
	city_draw.setCharacterSize(25);
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
	height_draw.setString(std::to_string(height));
	weight_draw.setString(std::to_string(weight));
	date_draw.setString(date);
	country_draw.setString(country);
	id_exp_draw.setString(expiredate);
	city_draw.setString(city);
	//		
	window.draw(card);
	window.draw(static_info_IDno); // says id is bold,30 pixels
	window.draw(static_info_DOB); //These are constants for all id
	window.draw(static_info_SEX);
	window.draw(static_info_FIRST);
	window.draw(static_info_LAST);
	window.draw(static_info_HEIGHT);
	window.draw(static_info_WEIGHT);
	window.draw(static_info_EXPD);
	window.draw(static_info_COUNTRY);
	window.draw(static_info_ID_EXP);
	window.draw(static_info_CITY);

	window.draw(IDno_draw);
	window.draw(DOB_draw);
	window.draw(sex_draw);
	window.draw(firstN_draw);
	window.draw(lastN_draw);
	window.draw(height_draw);
	window.draw(weight_draw);
	window.draw(date_draw);
	window.draw(country_draw);
	window.draw(id_exp_draw);
	window.draw(city_draw);
		
}