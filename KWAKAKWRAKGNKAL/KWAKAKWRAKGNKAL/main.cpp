#include"gamedata.h"
#include"IDcard.h"
#include <chrono>
#include <thread>
int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	gamedata data;
	sf::RenderWindow window1(sf::VideoMode(1280, 800), "Passport");
	sf::RenderWindow window2(sf::VideoMode(1280, 800), "ID");
	sf::RenderWindow window3(sf::VideoMode(1280, 800), "Visa");
	sf::RenderWindow window4(sf::VideoMode(1280, 800), "Orders");
	while (window1.isOpen() && window2.isOpen() && window3.isOpen() && window4.isOpen())
	{
		

		sf::Event event;
		sf::Keyboard keyboard;
		//Okay, we're doing the game logic in  main
		// We'll seee how long I keep that up
		//gameplay loop runs until playerfinishes the month or loses all lives;
		//Once events are figgered out, be sure that the player can exit at their discretion 
		int flip;
		while (data.getlives() > 0 && data.getday() < 12)
		{

			data.genchara();
			//placeholder for actually displaying to the screen
			data.debugshowdata();
			data.displaychara(window1, window2, window3, window4);
			//get user input for judging the documents
			//replace with events once that's figured
			//for now a basic input loop
			flip = 0;
			while (window1.pollEvent(event) != sf::Event::KeyPressed && flip == 0)
			{
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					window1.close();
					window2.close();
					window3.close();
					window4.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:

					if (event.key.code == sf::Keyboard::Z)
					{
						data.advance(false);
						flip = 1;
						std::this_thread::sleep_for(std::chrono::milliseconds(1000*3));

					}
					else if (event.key.code == sf::Keyboard::X)
					{
						data.advance(true);
						flip = 1;
						std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 3));

					}
					
					break;


					// we don't process other types of events
				default:
					break;
				}
			}
			
		}
		if (window1.pollEvent(event) == sf::Event::Closed || window2.pollEvent(event) == sf::Event::Closed || window3.pollEvent(event) == sf::Event::Closed || window4.pollEvent(event) == sf::Event::Closed )
		{
			window1.close();
			window2.close();
			window3.close();
			window4.close();
			std::cout << "Window was closed" << std::endl;
			break;
		}
	}
	//TODO: Write a Game over display function
	// Function will internally handle whether to display a "Victory" or "Game Over" screen

	return 0;
};
