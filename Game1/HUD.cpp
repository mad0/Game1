#include "HUD.h"
#include <string>


HUD::HUD(sf::RenderWindow& _okno) : okno(_okno){
	font.loadFromFile("font.ttf");
	speed.setFont(font);
	score.setFont(font);
	lives.setFont(font);
	boom.setFont(font);
	boom.setString("BOOM!");
	boom.setCharacterSize(200);
	boom.setPosition(499, 350);
	speed.setFillColor(sf::Color::Red);
	score.setFillColor(sf::Color::Red);
	lives.setFillColor(sf::Color::Red);
	speed.setPosition(0, 100);
	score.setPosition(0, 150);
	lives.setPosition(0, 200);
}

HUD::~HUD() {
}

void HUD::updateHUD(int _lives, int _speed, int _score) {
	lives.setString("LIVES: " + std::to_string(_lives));
	speed.setString("SPEED:" + std::to_string(_speed));
	score.setString("SCORE: " + std::to_string(_score));
}

void HUD::displayHUD()
{
	okno.draw(lives);
	okno.draw(speed);
	okno.draw(score);
}

void HUD::displayBOOM() {
	okno.draw(boom);
}




