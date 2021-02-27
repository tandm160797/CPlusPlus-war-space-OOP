#ifndef Menu_hpp
#define Menu_hpp
#include"SFML-2.5.1/include/SFML/Graphics.hpp"
#include"Game.hpp"
#define MAX_NUMBER_OF_ITEMS 3
using namespace sf;

class Menu{
private:
	int selectedItemIndex;
	Text text[MAX_NUMBER_OF_ITEMS];
public:
	Menu() = default;
	~Menu() = default;
	Menu (RenderWindow &window);
	void create(RenderWindow &window);
	void draw(RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem();
};
#endif //Menu_hpp
