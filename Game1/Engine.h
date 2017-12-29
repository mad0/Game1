#pragma once
#include "Road.h"

class Engine {
	private:
		sf::RenderWindow okno;
		Road *r;
	public:
		Engine();
		~Engine();
		void start();
};
