#include"gamedata.h"
#include"IDcard.h"
#include <SFML/Network.hpp>
std::string ip;
const int port = 303;
sf::TcpSocket socket;
sf::Mutex mutex;
bool gat = false;

bool client(void)
{
	if(socket.connect(ip,port) == sf::Socket::Done)
	{
		std::cout<<"Connected"<<std::endl;
		return true;
	}
	return false;
}
void manage(void)
{
	std::string msg;
	sf::Packet in;
	if(client())
	{
		mutex.lock();
		socket.receive(in);
		in >> msg;
		mutex.unlock();
		if(msg == "go")
		{
			gat= true;
		}
	}
	else
	{
		std::cout << "Connection has failed" <<std::endl;	
	}
}

int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE 
	gamedata data;
	sf::Window window(sf::VideoMode(1280,800),"Papes Pls");
	sf::Event event;
	sf::Keyboard keyboard;
	
	std::cout << "Input IP: ";
	std::cin >>ip;
	sf::Thread network_thread(&manage);
	network_thread.launch();
	
	//Okay, we're doing the game logic in  main
	// We'll seee how long I keep that up
	//gameplay loop runs until playerfinishes the month or loses all lives;
	//Once events are figgered out, be sure that the player can exit at their discretion 
	while (data.getlives() > 0 && data.getday() < 12) {
		data.genchara();
		//placeholder for actually displaying to the screen
		data.debugshowdata();
		data.displaychara(window);
		//get user input for judging the documents
		//replace with events once that's figured
		//for now a basic input loop
		if(gat == true)
		{
			// dont do normal event poll do the gat phase
			gat = false;	
		}
		else
		{
			while(window.pollEvent(event) != sf::Event::Closed)
			{
				if(keyboard.isKeyPressed((sf::Keyboard::Z))){
					data.advance(false);
					break;
				}
				else if(keyboard.isKeyPressed((sf::Keyboard::X))){
					data.advance(true);
					break;	
				}
			}
		}
		if(window.pollEvent(event) == sf::Event::Closed)
		{
			window.close();
			std::cout <<"Window was closed"<<std::endl;
			break;					      
		}
	}

	//TODO: Write a Game over display function
	// Function will internally handle whether to display a "Victory" or "Game Over" screen

	return 0;
};
