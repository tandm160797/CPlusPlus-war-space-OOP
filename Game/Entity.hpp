#ifndef Entity_hpp
#define Entity_hpp
#include"SFML-2.5.1/include/SFML/Graphics.hpp"
#include"Animation.hpp"
using namespace sf;

class Speed {
private:
	int dx;
	int dy;
public:
	Speed() = default;
	~Speed() = default;
	Speed(int dx, int dy) {
		this->dx = dx;
		this->dy = dy;
	}
	int getDx() {
		return dx;
	}
	int getDy() {
		return dy;
	}
	void setDx(int dx) {
		this->dx = dx;
	}
	void setDy(int dy) {
		this->dy = dy;
	}
	void operator=(Speed speed) {
		dx = speed.dx;
		dy = speed.dy;
	}
};
class Entity {
protected:
	int hp;
	int dame;
	bool shoot;
	Speed speed;
	Sprite sprite;
public:
	Entity() = default;
	~Entity() = default;
	int getHp();
	int getDame();
	bool getShoot();
	Speed getSpeed();
	Sprite& getSprite();
	void setHp(int hp);
	void setDame(int dame);
	void setShoot(bool status);
	void setSpeed(Speed speed);
	bool isLife();
	void draw(RenderWindow &window);
	virtual void ultimate() = 0;
};
#endif //Entity_hpp
