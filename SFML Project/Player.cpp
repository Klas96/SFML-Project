#include "Player.h"

Player::Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	this->name = name; 
	this->rightKey = rightKey;
	this->leftKey = leftKey;
	this->playerColor = playerColor;
	this->score = 0;
	this->alive = true;

	Dot playerDot(1200.0, 900.0, playerColor, rightKey, leftKey);
}

Player::Player()
{
}

Player::~Player()
{
	//Empty
}

void Player::update()
{
	//playerDot.DrawTo(window); // Beh�vs Update i playerklassen?
}

bool Player::IsAlive()
{
	return alive;
}

void Player::Dead()
{
	alive = false;
}

sf::Keyboard::Key Player::GetRightKey() const
{
	return this-> rightKey;
}

sf::Keyboard::Key Player::GetLeftKey() const
{
	return this-> leftKey;
}

std::string Player::GetName() const
{
	return this-> name;
}

sf::Color Player::GetPlayerColor()
{
	return this-> playerColor;
}

int Player::GetScore() const
{
	return score;
}

std::string Player::ToString() const
{
	std::string retString;
	retString += "Name:\t" + name + "\n";
	/*retString += "Color:\t" + to_string(playerColor) + "\n";
	retString += "Score:\t" + to_string(score) + "\n";*/
	
	return retString;
}
