#include"Animation.hpp"

Animation::Animation(Texture &texture, int left, int top, int width, int height, float speed, int numberOfFrames) {
	frame = 0;
	this->speed = speed;
	sprite.setTexture(texture);
	//
	for (int i = 0; i < numberOfFrames; i++) {
		frames.push_back(IntRect((left + width * i), top, width, height));
		sprite.setOrigin(frames[0].width / 2, frames[0].height / 2);
	}
	sprite.setTextureRect(frames[0]);
}
void Animation::setting(Texture& texture, int left, int top, int width, int height, float speed, int numberOfFrames) {
	frame = 0;
	this->speed = speed;
	sprite.setTexture(texture);
	//
	for (int i = 0; i < numberOfFrames; i++) {
		frames.push_back(IntRect((left + width * i), top, width, height));
		sprite.setOrigin(frames[0].width / 2, frames[0].height / 2);
	}

	sprite.setTextureRect(frames[0]);
}
void Animation::update() {
	frame += speed;
	if (frame > frames.size()) {
		frame -= frames.size();
	}
	sprite.setTextureRect(frames[(int)frame]);
}
void Animation::draw(RenderWindow& window) {
	window.draw(sprite);
}
float Animation::getFrame() {
	return frame;
}
Sprite& Animation::getSprite(){
	return sprite;
}
int Animation::getNumberOfFrames(){
	return frames.size();
}
void Animation::setFrame(float frame){
	this->frame = frame;
}
