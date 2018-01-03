#include "Car.h"
#include <iostream>

Car::Car(sf::RenderWindow& _okno) : okno(_okno) {
	carTexture.loadFromFile("car.png");
	carSprite.setTexture(carTexture);
	carSprite.setPosition(220, 1070);
	carSprite.setRotation(180);
	viewCar.setSize(1824, 1568);
	viewCar.setCenter(300, 300);
	okno.setView(viewCar);
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
	sf::Vector2f nextPos(carSprite.getPosition().x - 210, 1070);
	std::cout << nextPos.x << "\n";
	if (nextPos.x>210)
		carSprite.setPosition(carSprite.getPosition().x - 210, 1070);
}

void Car::moveRight() {
	sf::Vector2f nextPos (carSprite.getPosition().x + 210, 1070);
	if (nextPos.x<641)
		carSprite.setPosition(carSprite.getPosition().x+210, 1070);
}

