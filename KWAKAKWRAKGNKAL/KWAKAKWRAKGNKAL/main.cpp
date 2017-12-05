#include"gamedata.h"
#include"IDcard.h"

int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	gamedata data;
	sf::RenderWindow window1(sf::VideoMode(1280, 800), "Passport");
	sf::RenderWindow window2(sf::VideoMode(1280, 800), "ID");
	sf::RenderWindow window3(sf::VideoMode(1280, 800), "Visa");
	sf::RenderWindow window4(sf::VideoMode(1280, 800), "Orders");
	while (window1.isOpen() && window2.isOpen() && window3.isOpen() && window4.isOpen())
	{
		window1.clear();
		window2.clear();
		window3.clear();
		window4.clear();
		sf::Event event;
		sf::Keyboard keyboard;
		//Okay, we're doing the game logic in  main
		// We'll seee how long I keep that up
		//gameplay loop runs until playerfinishes the month or loses all lives;
		//Once events are figgered out, be sure that the player can exit at their discretion 
		while (data.getlives() > 0 && data.getday() < 12) {
			data.genchara();
			//placeholder for actually displaying to the screen
			data.debugshowdata();
			data.displaychara(window1, window2, window3, window4);
			//get user input for judging the documents
			//replace with events once that's figured
			//for now a basic input loop
			while (window1.pollEvent(event) != sf::Event::Closed)
			{
				if (keyboard.isKeyPressed(sf::Keyboard::Z)) {
					data.advance(false);
					break;
				}
				else if (keyboard.isKeyPressed(sf::Keyboard::X)) {
					data.advance(true);
					break;
				}
			}
			if (window1.pollEvent(event) == sf::Event::Closed)
			{
				window1.close();
				std::cout << "Window was closed" << std::endl;
				break;
			}
			while (window2.pollEvent(event) != sf::Event::Closed)
			{
				if (keyboard.isKeyPressed(sf::Keyboard::Z)) {
					data.advance(false);
					break;
				}
				else if (keyboard.isKeyPressed(sf::Keyboard::X)) {
					data.advance(true);
					break;
				}
			}
			if (window2.pollEvent(event) == sf::Event::Closed)
			{
				window2.close();
				std::cout << "Window was closed" << std::endl;
				break;
			}
			while (window3.pollEvent(event) != sf::Event::Closed)
			{
				if (keyboard.isKeyPressed(sf::Keyboard::Z)) {
					data.advance(false);
					break;
				}
				else if (keyboard.isKeyPressed(sf::Keyboard::X)) {
					data.advance(true);
					break;
				}
			}
			if (window3.pollEvent(event) == sf::Event::Closed)
			{
				window3.close();
				std::cout << "Window was closed" << std::endl;
				break;
			}
			while (window4.pollEvent(event) != sf::Event::Closed)
			{
				if (keyboard.isKeyPressed(sf::Keyboard::Z)) {
					data.advance(false);
					break;
				}
				else if (keyboard.isKeyPressed(sf::Keyboard::X)) {
					data.advance(true);
					break;
				}
			}
			if (window4.pollEvent(event) == sf::Event::Closed)
			{
				window4.close();
				std::cout << "Window was closed" << std::endl;
				break;
			}
		}
	}
	//TODO: Write a Game over display function
	// Function will internally handle whether to display a "Victory" or "Game Over" screen

	return 0;
};
