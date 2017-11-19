#include"document.h"


int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	passport test , *testy = new passport;
	testy->setCountry((std::string)"SAoVQ");


	test = *testy;
	delete testy;
	std::cout << test.getCountry();
	test.master_corruptor(1);

	system("pause");
	return 0;
};