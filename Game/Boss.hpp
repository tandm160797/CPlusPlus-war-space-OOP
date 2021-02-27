#ifndef Boss_hpp
#define Boss_hpp
#include"Enemy.hpp"

class Boss :public Enemy {
private:
public:
	Boss() = default;
	~Boss() = default;
	virtual void ultimate();
};
#endif //Boss_hpp
