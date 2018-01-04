#include "HUD.h"
#include <string>


HUD::HUD(sf::RenderWindow& _okno) : okno(_okno){
	font.loadFromFile("font.ttf");
	speed.setFont(font);
	score.setFont(font);
	lives.setFont(font);
	//boom
	boom.setFont(font);
	boom.setString("");
	boom.setCharacterSize(110);
	boom.setPosition(720, 200);
	boom.setString("BOOM!");
	//TheEnd
	theend.setFont(font);
	theend.setString("THE END");
	theend.setCharacterSize(190);
	theend.setPosition(210, 350);
	theend.setFillColor(sf::Color::Red);
	///
	speed.setFillColor(sf::Color::Red);
	score.setFillColor(sf::Color::Red);
	lives.setFillColor(sf::Color::Red);
	speed.setPosition(60, 100);
	score.setPosition(60, 150);
	lives.setPosition(60, 200);
}

HUD::~HUD() {
}

void HUD::updateHUD(int _lives, int _speed, int _score) {
	lives.setString("LIVES: " + std::to_string(_lives));
	speed.setString("SPEED:" + std::to_string(_speed));
	score.setString("SCORE: " + std::to_string(_score));
}

void HUD::displayHUD() {
	okno.draw(lives);
	okno.draw(speed);
	okno.draw(score);
}

void HUD::displayTheEnd() { okno.draw(theend);  }

void HUD::displayBOOM() { okno.draw(boom);}




