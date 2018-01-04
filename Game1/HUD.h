#pragma once
#include "SFML\Graphics.hpp"

class HUD {
private:
	sf::RenderWindow& okno;
	sf::Text score;
	sf::Text speed;
	sf::Text lives;
	sf::Text boom;
	sf::Font font;
public:
	HUD(sf::RenderWindow&);
	~HUD();
	void updateHUD(int, int, int);
	void displayHUD();
	void displayBOOM();
};

