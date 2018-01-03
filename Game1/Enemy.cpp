#include "Enemy.h"
#include <iostream>

const int Enemy::bombPos [3] = { 355, 470, 585 };

Enemy::Enemy(sf::RenderWindow &_okno) :okno(_okno) {
	enemyTexture.loadFromFile("bomb.png");
	enemySprite.setTexture(enemyTexture);
	pos = (std::rand() % 3) + 0;
	enemySprite.setPosition(bombPos[pos], 0);
	czas = sf::seconds(0.0f);
	zegar.restart();
}

Enemy::~Enemy() {
}

sf::Sprite Enemy::enemyDisplay() {
	return enemySprite;
}

void Enemy::enemyUpdate() {
	czas = zegar.getElapsedTime();
	if (czas.asSeconds() > 0.4) {
		enemySprite.move(0, 40);
		zegar.restart();
	}
	okno.setView(enemyView);
}

sf::FloatRect Enemy::enemyPosition() {
	return enemySprite.getGlobalBounds();
}


