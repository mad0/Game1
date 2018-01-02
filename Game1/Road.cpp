#include "Road.h"
#include <iostream>

Road::Road(sf::RenderWindow& _okno) : okno(_okno) {
	std::cout << "ROAD start....\n";
	t.loadFromFile("road2.png");
	r.setSize(sf::Vector2f(256, 800));
	//r.setFillColor(sf::Color::Color(127, 127, 127, 255));
	r.setTexture(&t);
	r.setPosition((okno.getSize().x / 2)-(r.getSize().x)/2, 0);
	widok.setSize(1024, 400);
	widok.setCenter(512, 600);
	std::cout << widok.getCenter().x << "------------" << widok.getCenter().y << "\n";
	std::cout << widok.getSize().x << "------------" << widok.getSize().y << "\n";
	okno.setView(widok);
}


Road::~Road(){
	std::cout << "ROAD stop....\n";
}

sf::RectangleShape Road::roadDisplay(){
	return r;
}

void Road::roadUpdate() {
	//std::cout << "update road...\n";
	widok.move(0, -1);
	std::cout << widok.getCenter().y<< "\n";
	if (widok.getCenter().y <= 200)
		widok.setCenter(512, 600);
	//sf::View currentView = okno.getView();
	okno.setView(widok);
}
