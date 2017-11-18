#include"document.h"
#include<iostream>

int main(void) {
	passport test , *testy = new passport;
	testy->setCountry((std::string)"SAoVQ");


	test = *testy;
	delete testy;
	std::cout << test.getCountry();

	system("pause");
	return 0;
};