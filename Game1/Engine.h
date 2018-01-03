#pragma once
#include "Road.h"
#include "Car.h"
#include "Enemy.h"

class Engine {
	private:
		sf::RenderWindow okno;
		Road *r;
		Car *car;
		Enemy *enemy;
	public:
		Engine();
		~Engine();
		void start();
};
