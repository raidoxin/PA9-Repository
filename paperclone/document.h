#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <SFML/Graphics.hpp>



//using std::string cuz I don't feel like typing that out every time
using std::string;
using std::endl;

class passport {
protected:
	//for use later
	bool valid;
public:
	// default constructor
	// fills the fields with dummy information;
	passport();

	//assignement operator overload
	//this is meant to make assigning dublicate values to the derivative classes easier;
	passport& operator=(passport & copied);

	//setters
	void setID(string & newID);
	void setBirth(string & newDoB);
	void setSex(bool newsex);
	void setFirst(string & newFirst);
	void setLast(string & newLast);
	void setHeight(unsigned int newHeight);
	void setWeight(unsigned int newWeight);
	void setDate(string & newDate);
	void setCountry(string & newCountry);

	//getters

	string & getID();
	string & getDoB();
	bool & getSex();
	string & getFirstN();
	string & getLastN();
	unsigned & getHeight();
	unsigned & getWeight();
	string & getDate();
	string & getCountry();
	bool isValid();
	//Super printer
	void print_all();


	//master corruptor
	void master_corruptor(int odds); //odds act as percentage chance
	
	//void draw(sf::Window window);

private:
	string IDno;
	string DoB;
	bool sex;
	string firstN;
	string lastN;
	//height in cm
	unsigned int height;
	//weight in Kgs
	unsigned int weight;
	string date;
	string country;

	//corruptors --do not call 
	void corruptIdno(int odds);
	void corruptDob(int odds);
	void corruptsex(int odds);
	void corruptfirstN(int odds);
	void corruptlastN(int odds);
	void corruptheight(int odds);
	void corruptweight(int odds);
	void corruptdate(int odds);
	void corruptcountry(int odds);

};
