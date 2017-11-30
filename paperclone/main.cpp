#include"gamedata.h"
#include"IDcard.h"

int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	gamedata data;

	//Okay, we're doing the game logic in  main
	// We'll seee how long I keep that up
	//gameplay loop runs until playerfinishes the month or loses all lives;
	//Once events are figgered out, be sure that the player can exit at their discretion 
	for (char input; data.getlives() > 0 && data.getday() < 12;) {
		data.genchara();
		//placeholder for actually displaying to the screen
		data.debugshowdata();
		//get user input for judging the documents
		//replace with events once that's figured
		//for now a basic input loop
		do {
			std::cout << "Z:Documents are Invalid" << std::endl << " X:Documents are Genuine" << std::endl;
			std::cin >> input;
		} while (input != 'z' && input != 'x');
		switch(input){
		case 'z': {
			data.advance(false);
			break;
		}
		case 'x': {
			data.advance(true);
			break;
		}
		}
	}

	//TODO: Write a Game over display function
	// Function will internally handle whether to display a "Victoly" or "Game Over" screen

	return 0;
};
