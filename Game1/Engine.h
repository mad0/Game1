#pragma once
#include "Road.h"
#include "Car.h"
#include "Enemy.h"
#include <memory>

class Engine {
	private:
		sf::RenderWindow okno;
		Road *r;
		std::vector<Enemy*> enemys;
		Car *car;
		//Enemy *enemy;
	public:
		Engine();
		~Engine();
		void start();
};
