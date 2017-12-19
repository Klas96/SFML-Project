#include "Player.h"

void Player::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(playerDot);
}

Player::Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor, sf::RectangleShape& border)
	: playerDot(1200.0, 900.0, playerColor, rightKey,leftKey, border)
{
	this->name = name; 
	this->playerColor = playerColor;
	this->score = 0;
	this->alive = true;
	this->border = border;
	/*sf::Vector2f position = { float(rand() % int(1200.0) + 300), float(rand() % int(900.0) + 200) };
	playerDot.SetPosition(position, float(rand()%360));*/

	sf::Vector2f borderpositioned = { float(rand() % int(border.getSize().x) + border.getPosition().x), float(rand() % int(border.getSize().y) + border.getPosition().y + 20) };
	playerDot.SetPosition(borderpositioned, float(rand() % 360));


}

Player::~Player()
{ 
	//Empty
}

void Player::update(float dt)
{
	checkCollision();
	playerDot.Update(dt);
}

bool Player::IsAlive()
{
	return alive;
}

void Player::Kill()
{
	alive = false;
	playerDot.SetSpeed(0.0f);
}

void Player::Resurrect()
{
	alive = true;
	sf::Vector2f position = { float(rand() % int(800.0)+100), float(rand() % int(450.0)+50)}; //slumpar fram en ny position
	playerDot.SetPosition(position, float(rand() % 360)); //s�tter positionen och slumpar en ny vinkel
	playerDot.SetSpeed(10.0f);
}

void Player::AddScore()
{
	score++;
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
	//retString += "Color:\t" + std:: to_string(playerColor) + "\n";
	retString += "Score:\t" + std:: to_string(score) + "\n";
	
	return retString;
}

sf::VertexArray Player::GetKurveArr()
{
	return playerDot.GetKurveArr();
}

Dot Player::GetPlayerDot()
{
	return playerDot;
}




bool Player::checkCollision()
{
	bool retValue = false;

	

	sf::Vector2f xBounds(border.getPosition().x, border.getPosition().x +border.getSize().x);
	sf::Vector2f yBounds(border.getPosition().y, border.getPosition().y + border.getSize().y);

	/*sf::Vector2f xBounds(0.0f, 1200.0f);
	sf::Vector2f yBounds(0.0f, 900.0f);*/

	if ((playerDot.GetPosition().x + playerDot.GetSize()) >= xBounds.y || (playerDot.GetPosition().x + playerDot.GetSize()) <= xBounds.x || (playerDot.GetPosition().y + playerDot.GetSize()) >= yBounds.y || (playerDot.GetPosition().y + playerDot.GetSize()) <= yBounds.x)
	{
		Kill();
		retValue = true;
	}
	if (playerDot.selfIntersect())
	{
		Kill();
		retValue = true; 
	}

	

	//if  (playerDot.GetKurveArr().getBounds().intersects((playerDot.GetPosition().x +playerDot.GetSize())))



	return retValue;
}

bool Player::otherCollision(const sf::FloatRect & box)
{
	return playerDot.intersects(box);
}

