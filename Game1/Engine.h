#pragma once
#include "Road.h"
#include "Car.h"
#include "Enemy.h"
#include "HUD.h"
#include <memory>

class Engine {
	private:
		bool play;
		sf::RenderWindow okno;
		Road *r;
		std::vector<Enemy*> enemys;
		Car *car;
		HUD *hud;
		int score;
		int lives;
		sf::Clock czas;
		sf::Time spawnTime;
		int enemyCout;
		bool boom;
	public:
		Engine();
		~Engine();
		void start();
		void collision();
		void update();
		void display();
		void enemySpawn();
};
