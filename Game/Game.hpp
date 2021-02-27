#ifndef Game_hpp
#define Game_hpp
#include"Data.hpp"
#include"Enemy.hpp"
#include"Boss.hpp"
#include"Player.hpp"
#include"Animation.hpp"
#define WIDTH_WINDOW 400
#define HEIGHT_WINDOW 600

class Game {
private:
	static Game* game;
	RenderWindow window;
	Game();
public:
	~Game();
	static Game* getGame();
	RenderWindow& getWindow();
	void run();
};
#endif //Game_hpp
