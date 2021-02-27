#ifndef Player_hpp
#define Player_hpp
#include"Entity.hpp"
#include<string>
using namespace std;

class Player :public Entity {
private:
	string name;
	int score;
public:
	Player() = default;
	~Player() = default;
	Player(Sprite &sprite, string name, Speed speed, int hp, int dame, int score = 0, bool shoot = false);
	void create(Sprite &sprite, string name, Speed speed, int hp, int dame, int score = 0, bool shoot = false);
	string getName();
	int getScore();
	void setName(string name);
	void setScore(int score);
	virtual void ultimate();
};
#endif //Player_hpp
