#include"gamedata.h"
#include"IDcard.h"

int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	gamedata test;
	test.debugshowdata();
	test.genchara();
	test.debugshowdata();
	system("pause");

	return 0;
};
