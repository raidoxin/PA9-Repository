#include"gamedata.cpp"


int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	passport test;
	gamedata testo;
	//testy->setCountry((std::string)"SAoVQ");
	testo.genchara();
	test.print_all();
	test.master_corruptor(1);
	test.print_all();

	system("pause");
	return 0;
};
