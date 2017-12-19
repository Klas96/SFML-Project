#ifndef Dot_h
#define Dot_h
#include "SFML\Graphics.hpp"
#include "math.h"
#include "Kurve.h"

class Dot : public sf::Drawable
{
private:
	float size;
	float speed;
	float angle;
	float PI = 3.145;
	//sf::Vector2f position;
	sf::CircleShape dot;
	sf::Vector2f direction;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;
	Kurve kurve;

	void draw(sf::RenderTarget& t, sf::RenderStates s) const;


public:
	Dot(sf:: Color playerColor, sf::Keyboard::Key rightKey,sf::Keyboard::Key leftKey, sf::RectangleShape & border);

	void SetPosition(sf::Vector2f newPosition, float angle= float(rand() % 360 + 50));
	sf::Vector2f GetPosition();
	sf::Vector2f GetDirection();
	float GetSize();
	void SetSize(float newSize);
	float GetSpeed();
	void SetSpeed(float newSpeed);
	float GetAngle();
	void SetAngle(float newAngle);

	sf::VertexArray GetKurveArr();
	bool selfIntersect();
	sf::FloatRect GetDotBounds();

	bool intersects(const sf::FloatRect& box);
	void Update(float dt);
	void move(sf::Vector2f distance);
	void Draw();
};


#endif