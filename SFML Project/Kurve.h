#ifndef Kurve_h
#define Kurve_h
#include "SFML\Graphics.hpp"

class Kurve : public sf::Drawable
{
private:
	
	sf::Color playerColor;
	float size;
	
	sf::VertexArray vArray;


public:
	Kurve(sf::Color playerColor, float dotSize, sf::Vector2f originPoint, sf::Vector2f direction);
	~Kurve();
	void SetPosition(sf::Vector2f position);
	static float VectorLength(sf::Vector2f v);

	


	void Update(float dt, sf::Vector2f position);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;

 };

#endif // !Kurve_h