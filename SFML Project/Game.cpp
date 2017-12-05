#include "Game.h"

Game::Game()
{
	this->playerCap = 2;
	this->playerCount = 0;
	this->roundCount = 1;
	playerArr = new Player*[playerCap];
}

Game::~Game()
{
	for (int i = 0; i < playerCount; i++)
	{
		delete playerArr[i];
	}
	delete[] playerArr;
}

void Game::AddPlayer(std::string & name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	if (playerCount == playerCap)
	{
		ExpandPlayerArr();
	}
	
	playerArr[playerCount] = new Player(name, rightKey, leftKey, playerColor);
	playerCount++;
}

int Game::GetNrOfPlayers() const
{
	return playerCount;
}

bool Game::RoundEnded()
{
	int deathCounter = 0;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i]->IsAlive() == false)
		{
			deathCounter++;
		}

	}
	roundCount++;
	return playerCount == deathCounter - 1;
}

void Game::ExpandPlayerArr()
{
	playerCap = playerCap + 2;
	Player** temp = new Player*[playerCap];
	for (int i = 0; i < playerCount; i++)
	{
		temp[i] = playerArr[i];
	}
	delete[] playerArr;
	playerArr = temp;
}

void Game::Update(float dt)
{
	//Player kanske b�r h�lla speed, angle, direction?
	//I s�fall beh�ver ocks� size h�llas av player
	//Funderar p� att ta bort piltangenter fr�n Dot ocks� d� de inte beh�vs d�r?

	//H�r skall avst�ndet avg�ras f�r playerArr. for loop
	sf::Vector2f distance;

	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i]->GetAngle() > 360)
		{
			//angle -=360;
		}
		if (sf::Keyboard::isKeyPressed(playerArr[i]->GetRightKey()))
		{
			angle -= moveSpeed*dt*PI / 180.0f;
		}
		if (sf::Keyboard::isKeyPressed(playerArr[i]->GetRightKey()))
		{
			angle += moveSpeed*dt*PI / 180.0f;
		}
		
		sf::Vector2f direction(cos(angle), sin(angle));
		float factor = moveSpeed*dt;
		distance = (sin(angle)*factor, cos(angle)*factor);



		playerArr[i]->update(dt, distance);
	}

}
