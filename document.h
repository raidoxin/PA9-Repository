#pragma once
#include<string>

//using std::string cuz I don't feel like typing that out every time
using std::string;

class passport {

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
	void setSex(bool & newsex);
	void setFirst(string & newFirst);
	void setLast(string & newLast);
	void setHeight(unsigned int & newHeight);
	void setWeight(unsigned int & newWeight);
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
		//asdf

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
	
	//for use later
	bool valid;
};