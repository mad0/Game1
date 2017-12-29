#include "Engine.h"
#include <iostream>

Engine::Engine() {
	std::cout << "ENGINE start....\n";
	okno.create(sf::VideoMode(1024, 768), "Game1");
	okno.setFramerateLimit(60);
	r = new Road(okno);
}

Engine::~Engine() {
	std::cout << "ENGINE stop....\n";
	delete r;
}

void Engine::start() {
	while (okno.isOpen())
	{
		sf::Event zdarz;
		while (okno.pollEvent(zdarz))
		{
			if (zdarz.type == sf::Event::Closed)
				okno.close();
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			r->roadUpdate();

		okno.clear(sf::Color::Black);
		okno.draw(r->roadDisplay());
		okno.display();
	}
	
}