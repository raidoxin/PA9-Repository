#include"gamedata.h"

gamedata::gamedata() {

	//the big ol city/nation table
	//Shikoma : An Empire Touched by the Sun
	citystates[0][0] = "Shikoma";
	citystates[1][0] = "Sankaku Island";
	citystates[2][0] = "Gao-tse";
	citystates[3][0] = "Daijin-Kodomoko";
	citystates[4][0] = "P L A C E H O L D E R";
	//Red Star : United in Opression
	citystates[0][1] = "Red Star";
	citystates[1][1] = "Gulagorod";
	citystates[2][1] = "Domor";
	citystates[3][1] = "Musordorog";
	citystates[4][1] = "Dzhugashville";
	//Vastlund : The Shattered Continent
	citystates[0][2] = "Vastlund";
	citystates[1][2] = "Vieletonneburg";
	citystates[2][2] = "Gutwasser";
	citystates[3][2] = "Collard";
	citystates[4][2] = "Neue Wiese";
	//Union State : A Confederation of the Powerful
	//Honestly, these are all little too on the nose
	citystates[0][3] = "Union State";
	citystates[1][3] = "Eagleland";
	citystates[2][3] = "Predatoria";
	citystates[3][3] = "Ammunation";
	citystates[4][3] = "Sealand";
	//The Holy City : Protectors of the /k/ube
	citystates[0][4] = "Holy City";
	citystates[1][4] = "The Kube";

	//load the names and orders
	populatenamelist(firstnames[0], (string)"firstnamesF.txt");
	populatenamelist(firstnames[1], (string)"firstnamesM.txt");
	populatenamelist(lastnames, (string)"lastnames.txt");
	populatenamelist(missions, (string)"missions.txt");

	//set the day count and lives
	lives = 3;
	days = 0;
	service = 0;
}

// generates a new character
// will be expanded as classes are implemented
// for now, just makes a passport
void gamedata::genchara()
{
	//Gen Passport and ID card;
	generateIDcard(generatePassport());
}

void gamedata::incrementday()
{
	days++;
}

void gamedata::decrementlives()
{
	if (lives > 0)
		lives--;
}

void gamedata::debugshowdata()
{
	passport_dox.print_all();
	IDcard_dox.print_all();
}

//this populates the gamedata vectors
//reads strings from a file
//loads a line into a buffer, then puts it on the vector
//assumes there's only one input per line
void gamedata::populatenamelist(vector<string>& load, string & filename)
{
	std::ifstream file(filename);
	string buffer;

	if (file.is_open()) {
		for (; !file.eof();) {
			getline(file, buffer);
			load.push_back(buffer);
		}

	}
	file.close();
}

//rand is a random integer provided to select a city
//rand must be between zero and one less than th width of the array so it does not pick the holy city
string & gamedata::getnation(int & rand)
{
	return citystates[0][rand];
}
//nation needs to be the same value provided to getnation to get a sensible result
//nation must not exceed of course should not exceed the NATION count
string & gamedata::getcity(int & nation)
{
	return citystates[rand() % (CITIES + 1)][nation];
}

//grabs a random string from the input vector
string & gamedata::getrando(vector<string>& spec)
{
	return spec.at(rand() % spec.size());
}

string gamedata::genID()
{
	string buff;
	// loop 9 times ,inserting a random number from 1 to 10 each time
	for (int i = 0; i < 9; i++) {
		buff += std::to_string((rand() % 9) + 1);
	}
	return buff;
}
//Generates Birthday in a DD-MM-YYYY format
// Everybody is between 18  and 99 years old
string gamedata::genBirth()
{
	string buff;
	buff += std::to_string((rand() % 30) + 1);
	buff += '-';
	buff += std::to_string((rand() % 12) + 1);
	buff +='-';
	buff += std::to_string(THECURRENTYEAR - 18 - (rand() % 100));
	return buff;
}
// Generates a valid expiry date that is anywhere between the current day and a year or so in the future
string gamedata::genExp()
{
	string buff;
	int year = THECURRENTYEAR + (rand() % 2) , month = month = (rand() % 12 + 1), day;
	if (year > THECURRENTYEAR || month > 1)
		day = (rand() % 30 + 1);
	else
		day - (rand() % 12 + 19);
	buff += std::to_string(day);
	buff += '-';
	buff += std::to_string(month);
	buff += '-';
	buff += std::to_string(year);
	return buff;
}

int gamedata::genHeight()
{
	return (rand() % 62) + 152;
}

int gamedata::genWeight()
{
	return (rand() % 92) + 45;
}
void gamedata::corrupt_passport(int odds)
{
	passport_dox.master_corruptor(odds);	
}

//single function to generate the passport
int gamedata::generatePassport()
{
	//this holds a rondom number as needed
	int rando;
	passport_dox.setSex((bool)(rand() % 2));
	//picks a name from the aprropriately gendered list
	passport_dox.setFirst(getrando(firstnames[passport_dox.getSex()]));
	passport_dox.setLast(getrando(lastnames));
	rando = rand() % (NATIONS - 1);
	passport_dox.setCountry(getnation(rando));
	passport_dox.setID(genID());
	passport_dox.setBirth(genBirth());
	passport_dox.setWeight(genWeight());
	passport_dox.setHeight(genHeight());
	//returns rando for use in generating ID city
	return rando;
}

//generates the ID card
void gamedata::generateIDcard(int country)
{
	//copy the relevant bits between items
	IDcard_dox = passport_dox;
	IDcard_dox.setexpire(genExp());
	IDcard_dox.setcity(getcity(country));
}
