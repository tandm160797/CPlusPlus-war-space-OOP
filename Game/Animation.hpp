#ifndef Animation_hpp
#define Animation_hpp
#include<vector>
#include"SFML-2.5.1/include/SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Animation {
private:
	float frame;
	float speed;
	Sprite sprite;
	vector<IntRect> frames;
public:
	Animation() = default;
	~Animation() = default;
	Animation(Texture &texture, int left, int top, int width, int height, float speed, int numberOfFrames);
	void setting(Texture &texture, int left, int top, int width, int height, float speed, int numberOfFrames);
	void update();
	void draw(RenderWindow &window);
	float getFrame();
	Sprite& getSprite();
	int getNumberOfFrames();
	void setFrame(float frame);
};
#endif //Animation_hpp
