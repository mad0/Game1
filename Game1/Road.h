#pragma once
#include "SFML\Graphics.hpp"

class Road {
private:
	sf::RectangleShape r;
	sf::Texture t;
	sf::RenderWindow& okno;
	sf::View widok;
	sf::Clock zegar;
	sf::Time czas;
	float speed;
	sf::Time accu;
public:
	Road(sf::RenderWindow&);
	~Road();
	sf::RectangleShape roadDisplay();
	void roadUpdate();
	void speedUp();
	void speedDown();
};

