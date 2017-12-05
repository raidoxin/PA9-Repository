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
/*
void visa_mastercorrupt(int odds)
{
visa::corrupt_destination_City(odds);
visa::corrupt_destination_Country(odds);
visa::corrupt_visatype(odds);

}
*/

void visa::draw(sf::RenderWindow & window)
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

	sf::RectangleShape card(sf::Vector2f(770, 650));
	sf::Text static_info_IDno("ID: ", bold, 30); // says id is bold,30 pixels
	sf::Text static_info_DOB("DOB: ", bold, 30); //These are constants for all id
	sf::Text static_info_SEX("SEX: ", bold, 30);
	sf::Text static_info_FIRST("FIRST: ", bold, 30);
	sf::Text static_info_LAST("LAST: ", bold, 30);
	sf::Text static_info_HEIGHT("HEIGHT: ", bold, 30);
	sf::Text static_info_WEIGHT("WEIGHT: ", bold, 30);
	sf::Text static_info_EXPD("EXP DATE: ", bold, 30);
	sf::Text static_info_COUNTRY("COUNTRY: ", bold, 30); //need to set position
	sf::Text static_info_DEST_COUNTRY("DEST. COUNTRY: ", bold, 30);
	sf::Text static_info_DEST_CITY("DEST. CITY: ", bold, 30);
	sf::Text static_info_VISA_TYPE("Visa type: ", bold, 30);
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
	static_info_DEST_COUNTRY.setPosition(200, 500);
	static_info_DEST_CITY.setPosition(200, 550);
	static_info_VISA_TYPE.setPosition(200, 600);

	static_info_IDno.setFillColor(sf::Color::Black);
	static_info_DOB.setFillColor(sf::Color::Black);
	static_info_SEX.setFillColor(sf::Color::Black);
	static_info_FIRST.setFillColor(sf::Color::Black);
	static_info_LAST.setFillColor(sf::Color::Black);
	static_info_HEIGHT.setFillColor(sf::Color::Black);
	static_info_WEIGHT.setFillColor(sf::Color::Black);
	static_info_EXPD.setFillColor(sf::Color::Black);
	static_info_COUNTRY.setFillColor(sf::Color::Black);
	static_info_DEST_COUNTRY.setFillColor(sf::Color::Black);
	static_info_DEST_CITY.setFillColor(sf::Color::Black);
	static_info_VISA_TYPE.setFillColor(sf::Color::Black);

	card.setFillColor(sf::Color::White);
	card.setPosition(170, 20);
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
	sf::Text dest_city_draw;
	sf::Text dest_country_draw;
	sf::Text visa_type_draw;
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
	dest_country_draw.setFont(normal);
	dest_city_draw.setFont(normal);
	visa_type_draw.setFont(normal);

	IDno_draw.setFillColor(sf::Color::Black);
	DOB_draw.setFillColor(sf::Color::Black);
	sex_draw.setFillColor(sf::Color::Black);
	firstN_draw.setFillColor(sf::Color::Black);
	lastN_draw.setFillColor(sf::Color::Black);
	height_draw.setFillColor(sf::Color::Black);
	weight_draw.setFillColor(sf::Color::Black);
	date_draw.setFillColor(sf::Color::Black);
	country_draw.setFillColor(sf::Color::Black);
	dest_country_draw.setFillColor(sf::Color::Black);
	dest_city_draw.setFillColor(sf::Color::Black);
	visa_type_draw.setFillColor(sf::Color::Black);
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
	dest_country_draw.setPosition(700,500l);
	dest_city_draw.setPosition(700, 550);
	visa_type_draw.setPosition(700, 600);
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
	dest_country_draw.setCharacterSize(25);
	dest_city_draw.setCharacterSize(25);
	visa_type_draw.setCharacterSize(25);
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
	//for visa class
	dest_country_draw.setString(destinationCountry);
	dest_city_draw.setString(destinationCity);
	visa_type_draw.setString(visatype);
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
	window.draw(static_info_DEST_COUNTRY);
	window.draw(static_info_DEST_CITY);
	window.draw(static_info_VISA_TYPE);

	window.draw(IDno_draw);
	window.draw(DOB_draw);
	window.draw(sex_draw);
	window.draw(firstN_draw);
	window.draw(lastN_draw);
	window.draw(height_draw);
	window.draw(weight_draw);
	window.draw(date_draw);
	window.draw(country_draw);
	window.draw(dest_country_draw);
	window.draw(dest_city_draw);
	window.draw(visa_type_draw);


}