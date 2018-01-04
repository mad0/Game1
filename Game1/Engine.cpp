#include "Engine.h"
#include <iostream>

Engine::Engine() {
	std::cout << "ENGINE start....\n";
	play = true;
	enemyCout = 0;
	boom = false;
	spawnTime = sf::seconds(0.0f);
	score = 0;
	lives = 3;
	okno.create(sf::VideoMode(1024, 768), "Game1");
	//okno.setFramerateLimit(60);
	//okno.setVerticalSyncEnabled(true);
	okno.setKeyRepeatEnabled(false);
	r = new Road(okno);
	car = new Car(okno);
	hud = new HUD(okno);
	czas.restart();
}

Engine::~Engine() {
	std::cout << "ENGINE stop....\n";
	delete car;
	delete r;
	delete hud;
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
			if (play) {
				update();
				display();
			}
			
		}
}

void Engine::collision() {
	for (int z = 0; z < enemys.size(); z++) {
		//BOMB with CAR (-lives)
		if (enemys[z]->enemyPosition().intersects(car->carPosition())) {
			lives--;
			boom = true;
			enemys.erase(enemys.begin() + z);
			
		} else {
			if (enemys[z]->enemyPosition().top >= 1000) {
				score++;
				boom = false;
				enemys.erase(enemys.begin() + z);
			}
		}
	}
}

void Engine::update() {
	std::cout << play << "\n";
	okno.clear(sf::Color(36, 255, 91, 0));
	//okno.clear(sf::Color::Black);
	hud->updateHUD(lives, 20, score);
	hud->displayHUD();
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
	enemySpawn();
	collision();
	if (boom)
		hud->displayBOOM();
	if (lives <= 0) {
		boom = false;
		hud->displayTheEnd();
		play = false;
	}
		
		
}

void Engine::display() {
	okno.display();
}

void Engine::enemySpawn() {
	spawnTime = czas.getElapsedTime();
	if (spawnTime.asSeconds() > 0.6) {
		enemys.push_back(new Enemy(okno));
		czas.restart();
	}	
}
