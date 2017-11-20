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
	//
	populatenamelist(firstnames, (string)"firstnames.txt");
	populatenamelist(lastnames, (string)"lastnames.txt");
	populatenamelist(missions, (string)"missions.txt");

	//
	lives = 3;
	days = 0;
}

// generates a new character
// will be expanded as classes are implemented
// for now, just makes a passport
void gamedata::genchara()
{
	int rando;
	passport.setFirst(getrando(firstnames));
	passport.setLast(getrando(lastnames));
	rando = rand() % (NATIONS - 1);
	passport.setCountry(getnation(rando));
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
