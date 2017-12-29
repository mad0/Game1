#pragma once
#include "SFML\Graphics.hpp"

class Road {
private:
	sf::RectangleShape r;
	sf::Texture t;
	sf::RenderWindow& okno;
	sf::View widok;
public:
	Road(sf::RenderWindow&);
	~Road();
	sf::RectangleShape roadDisplay();
	void roadUpdate();
};

