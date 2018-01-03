#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &_okno) :okno(_okno) {
	enemyTexture.loadFromFile("bomb.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setPosition(300, 300);
	enemyView.setSize(310, 128);
	enemyView.setCenter(350, 340);
	okno.setView(enemyView);
}


Enemy::~Enemy() {
}

sf::Sprite Enemy::enemyDisplay() {
	return enemySprite;
}

void Enemy::enemyUpdate() {
	okno.setView(enemyView);
}
