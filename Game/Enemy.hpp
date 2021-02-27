#ifndef Enemy_hpp
#define Enemy_hpp
#include"Entity.hpp"

class Enemy :public Entity {
private:
protected:
public:
	Enemy() = default;
	~Enemy() = default;
	virtual void ultimate();
};
#endif //Enemy_hpp
