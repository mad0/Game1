#include "Road.h"
#include <iostream>

Road::Road(sf::RenderWindow& _okno) : okno(_okno) {
	std::cout << "ROAD start....\n";
	t.loadFromFile("road.png");
	r.setSize(sf::Vector2f(200, 400));
	//r.setFillColor(sf::Color::Color(127, 127, 127, 255));
	r.setTexture(&t);
	r.setPosition((okno.getSize().x / 2)-(r.getSize().x)/2, 0);
	widok.setSize(400, 100);
	widok.setCenter(500, 155);
}


Road::~Road(){
	std::cout << "ROAD stop....\n";
}

sf::RectangleShape Road::roadDisplay(){
	return r;
}

void Road::roadUpdate() {
	std::cout << "update road...\n";
	widok.move(0, -1);
	okno.setView(widok);
	std::cout << widok.getCenter().y << "\n";
	if (widok.getCenter().y <= 80)
		widok.setCenter(500, 155);
	//sf::View currentView = okno.getView();
}
