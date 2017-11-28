#include "Kurve.h"



Kurve::Kurve(sf::Color playerColor)
{
	this->playerColor = playerColor;
	this->speed = 2.0;
	this->direction = { cos(angle), sin(angle) };
}

Kurve::~Kurve()
{
	//Empty
}



void Kurve::Dead() //B�r denna ligga i player ist�llet?
{
	alive = false;
}

bool Kurve::IsAlive()//B�r denna ligga i player ist�llet?
{
	return alive;
}

void Kurve::ChangeDir(float angleChange)
{
	this->angle = angleChange;
}
