#ifndef Player_h
#define Player_h
#include <string>
#include "Dot.h"
#include <SFML\Graphics.hpp>


class Player
{
private:
	//int playerId //n�dv�ndig??
	std::string name;
	int score;
	sf::Color playerColor;
	bool alive;

	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;

public:
	Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor);

	Player(); //OBS Helt tom

	~Player();

	void update();

	bool IsAlive();
	void Dead();

	sf::Keyboard:: Key GetRightKey()const;
	sf::Keyboard::Key GetLeftKey()const;
	std::string GetName() const;
	sf::Color GetPlayerColor();
	int GetScore() const;
	std::string ToString() const;

};

#endif // !Player_h
