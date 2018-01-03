#pragma once
#include "SFML\Graphics.hpp"

class Car {
private:
	sf::Sprite carSprite;
	sf::Texture carTexture;
	sf::View viewCar;
	sf::RenderWindow &okno;
public:
	Car(sf::RenderWindow&);
	~Car();
	sf::Sprite carDisplay();
	void carUpdate();
	void moveLeft();
	void moveRight();
	sf::FloatRect carPosition();
};

