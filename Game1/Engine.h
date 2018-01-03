#pragma once
#include "Road.h"
#include "Car.h"

class Engine {
	private:
		sf::RenderWindow okno;
		Road *r;
		Car *car;
	public:
		Engine();
		~Engine();
		void start();
};
