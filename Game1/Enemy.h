#pragma once
#include "SFML\Graphics.hpp"

class Enemy {
private:
	sf::RenderWindow &okno;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	sf::View enemyView;
	sf::Clock zegar;
	sf::Time czas;
	const static int bombPos[];
	int pos;
public:
	Enemy(sf::RenderWindow&);
	~Enemy();
	sf::Sprite enemyDisplay();
	void enemyUpdate();
	sf::FloatRect enemyPosition();
};

