#include "Car.h"

Car::Car(sf::RenderWindow& _okno) : okno(_okno) {
	carTexture.loadFromFile("car.png");
	carSprite.setTexture(carTexture);
	carSprite.setPosition(300, 300);
	viewCar.setSize(200, 400);
	viewCar.setCenter(300, 300);
	//okno.setView(viewCar);
}


Car::~Car() {
}

sf::Sprite Car::carDisplay() {
	return carSprite;
}

void Car::carUpdate() {
}

