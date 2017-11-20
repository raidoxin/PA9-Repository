#include"gamedata.cpp"


int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	passport test_p;
	gamedata testo;
	//testy->setCountry((std::string)"SAoVQ");
	
	//testo.genchara();
	//test_p.print_all();
	//test_p.master_corruptor(1);
	//test_p.print_all();
	
	while(testo.getlives() != 0)
	{
		testo.genchara();
		testo.getpassport().master_corruptor(1);
		testo.decrementlives();
	}
	system("pause");
	return 0;
};
