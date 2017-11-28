#ifndef Kurve_h
#define Kurve_h
#include <string>
#include <SFML/Graphics.hpp>
#include "Line.h"

class Kurve
{
private:
	sf::Color playerColor;
	double positionX, positionY;
	 //B�r denna ligga i player ist�llet?
	float angle;
	sf::Vector2f direction;
	float speed;

public:
	Kurve(sf::Color playerColor);
	~Kurve();
	
	void ChangeDir(float angleChange);

};

#endif // !Kurve_h
