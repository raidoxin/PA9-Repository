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
};
