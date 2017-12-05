#include"visa.h"

class orders : public visa {

private:
	string mission;
	string validdate;

public:
	string & getmission();
	string & getvailiddate();

	void setmission(string & newmission);
	void setvaliddate(string newdate);

	void print_all();

	orders & operator= (visa & thevisa);

	void corrupt_mission(int odds);
	void corrupt_validdate(int odds);
	void orders_mastercorrupt(int odds);

	void draw(sf::RenderWindow & window);
};
