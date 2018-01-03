#include "Car.h"

Car::Car(sf::RenderWindow& _okno) : okno(_okno) {
	carTexture.loadFromFile("car.png");
	carSprite.setTexture(carTexture);
	carSprite.setScale(0.5, 0.5);
	carSprite.setPosition(450, 990);
	carSprite.setRotation(180);
}


Car::~Car() {
}

sf::Sprite Car::carDisplay() {
	return carSprite;
}

void Car::carUpdate() {
	okno.setView(viewCar);
}

void Car::moveLeft() {
	sf::Vector2f nextPos(carSprite.getPosition().x - 115, 990);
	if (nextPos.x>449)
		carSprite.setPosition(carSprite.getPosition().x - 115, 990);
}

void Car::moveRight() {
	sf::Vector2f nextPos (carSprite.getPosition().x + 115, 990);
	if (nextPos.x<691)
		carSprite.setPosition(carSprite.getPosition().x+115, 990);
}

sf::FloatRect Car::carPosition() {
	return carSprite.getGlobalBounds();
}

