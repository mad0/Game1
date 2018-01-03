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
	enemys.push_back(new Enemy(okno));
}

Engine::~Engine() {
	std::cout << "ENGINE stop....\n";
	delete car;
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
		for (auto x : enemys) {
			if (x->enemyPosition().intersects(car->carPosition())) {
				std::cout << "BOOM\n";
				std::cout << enemys.size() << "\n";
				delete (&x);
				std::cout << enemys.size() << "\n";
			}
		}
		
		//std::cout << car->carPosition().left << " //// " << car->carPosition().top << "\n";
		//std::cout << enemy->enemyPosition().left << " //// " << enemy->enemyPosition().top << "\n";
		okno.clear(sf::Color(36, 255, 91, 0));
		r->roadUpdate();
		okno.draw(r->roadDisplay());
		car->carUpdate();
		okno.draw(car->carDisplay());
		if (enemys.size() > 0) {
			for (auto x : enemys) {
				x->enemyUpdate();
				okno.draw(x->enemyDisplay());
			}
			
		}
		
		okno.display();
	}
}