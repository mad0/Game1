#include "Road.h"
#include <iostream>

Road::Road(sf::RenderWindow& _okno) : okno(_okno) {
	speed = 0.008;
	accu = sf::seconds(0.0f);
	std::cout << "ROAD start....\n";
	t.loadFromFile("road.png");
	r.setSize(sf::Vector2f(256, 800));
	//r.setFillColor(sf::Color::Color(127, 127, 127, 255));
	r.setTexture(&t);
	r.setPosition((okno.getSize().x / 2)-(r.getSize().x)/2, 0);
	widok.setSize(1024, 400);
	widok.setCenter(512, 600);
	std::cout << widok.getCenter().x << "------------" << widok.getCenter().y << "\n";
	std::cout << widok.getSize().x << "------------" << widok.getSize().y << "\n";
	okno.setView(widok);
	zegar.restart();
}


Road::~Road(){
	std::cout << "ROAD stop....\n";
}

sf::RectangleShape Road::roadDisplay(){
	return r;
}

void Road::roadUpdate() {
	czas = zegar.getElapsedTime();
	//std::cout << czas.asSeconds() << "\n";
	//std::cout << "update road...\n";
	if (czas.asSeconds() > speed) {
		widok.move(0, -1);
		accu += zegar.getElapsedTime();
		zegar.restart();
	}
	//std::cout <<"ACCU: "<< accu << "\n";
	//std::cout << "SPEED: " << speed << "\n";
	//std::cout << widok.getCenter().y<< "\n";
	if (widok.getCenter().y <= 200)
		widok.setCenter(512, 600);
	//sf::View currentView = okno.getView();
	//okno.setView(widok);
	
}

void Road::speedUp() {
	speed -= 0.001;
}

void Road::speedDown() {
	speed += 0.001;
}
