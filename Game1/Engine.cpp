#include "Engine.h"
#include <iostream>

Engine::Engine() {
	std::cout << "ENGINE start....\n";
	okno.create(sf::VideoMode(1024, 768), "Game1");
	//okno.setFramerateLimit(60);
	//okno.setVerticalSyncEnabled(true);
	okno.setKeyRepeatEnabled(false);
	r = new Road(okno);
	car = new Car(okno);
	enemy = new Enemy(okno);
}

Engine::~Engine() {
	std::cout << "ENGINE stop....\n";
	delete car;
	delete r;
	delete enemy;
}

void Engine::start() {
	while (okno.isOpen())
	{
		sf::Event zdarz;
		while (okno.pollEvent(zdarz))
		{
			if (zdarz.type == sf::Event::Closed)
				okno.close();
			if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Down)
				r->speedDown();
			if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Up)
				r->speedUp();
			if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Right)
				car->moveRight();
			if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Left)
				car->moveLeft();
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			
		if (enemy->enemyPosition().intersects(car->carPosition()))
			std::cout << "BOOM\n";
		//std::cout << car->carPosition().left << " //// " << car->carPosition().top << "\n";
		//std::cout << enemy->enemyPosition().left << " //// " << enemy->enemyPosition().top << "\n";
		okno.clear(sf::Color(36, 255, 91, 0));
		r->roadUpdate();
		okno.draw(r->roadDisplay());
		car->carUpdate();
		okno.draw(car->carDisplay());
		enemy->enemyUpdate();
		okno.draw(enemy->enemyDisplay());
		okno.display();
	}
}