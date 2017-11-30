#include "Player.h"

Player::Player(const std::string name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	//this-> playerId = slumpad funktion som tar nya v�rden varje g�ng???
	this->name = name;
	this->alive = true;
	this->score = 0;
	this->playerColor = playerColor;
	this->rightKey = rightKey;
	this->leftKey = leftKey;
}

Player::Player()
{
	this->name = "";
	this->score = 0;
	this->alive = true;

}

Player::~Player()
{
	//Empty
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(leftKey))
	{

		kurve.ChangeDir();
	}
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		
		kurve.ChangeDir();
	}

}

bool Player::IsAlive()
{
	return alive;
}

void Player::Dead()
{
	this->alive = false;
}

sf::Keyboard::Key Player::GetRightKey() const
{

	return rightKey;
}

sf::Keyboard::Key Player::GetLeftKey() const
{
	return leftKey;
}

std::string Player::GetName() const
{
	return this-> name;
}

sf::Color Player::GetPlayerColor()
{
	return playerColor;
}

int Player::GetScore() const
{
	return this-> score;
}

std::string Player::ToString() const
{
	std::string retString;
	retString+= "Name:\t" + this->name + "\nScore:\t" + std:: to_string(this-> score); 
	return std::string();
}
