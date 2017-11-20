#pragma once
#include"document.h"
#include<vector>
#include<fstream>

//Making these defines to kkep track of nation size and number of cities should we change our minds
#define NATIONS 5
#define CITIES 4

using std::vector;

//This class is meant to hold all the game data used to generate characters
//It also handles the actual generation of characters

class gamedata {

public:
	//constructor initializes gamedata
	gamedata();
	void genchara();

	void incrementday();
	void decrementlives();
	//debugshowdata();

private:
	//doxx
	passport passport;

	//this array holds the nations on the first row
	// and the corresponding cities in the following rows in the coresponding column
	// we will assume for the purposes of our game that "The Holy City" will occupty the last column
	string citystates[CITIES + 1][NATIONS];

	//these vectors hold the names used for generation
	//vectors are used so if we want to add names, we won;t have to hardcode it all
	vector <string> firstnames;
	vector <string> lastnames;
	vector <string> missions;


	unsigned int lives;
	unsigned int days;

	//private functions

	//This is used to populate the vectors during initialization
	void populatenamelist(vector <string> & load, std::string & filename);
	//these get a nation based on the number provided
	string & getnation(int & rand);
	string & getcity(int & nation);
	//this gets a random string form the specified vector
	string & getrando(vector <string> & spec);

};