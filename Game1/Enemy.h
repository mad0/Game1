#pragma once
#include "SFML\Graphics.hpp"

class Enemy {
private:
	sf::RenderWindow &okno;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	sf::View enemyView;
public:
	Enemy(sf::RenderWindow&);
	~Enemy();
	sf::Sprite enemyDisplay();
	void enemyUpdate();
};

