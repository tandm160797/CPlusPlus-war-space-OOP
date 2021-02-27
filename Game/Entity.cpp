#include"Entity.hpp"

int Entity::getHp() {
	return hp;
}
int Entity::getDame() {
	return dame;
}
bool Entity::getShoot(){
	return shoot;
}
Speed Entity::getSpeed(){
	return speed;
}
Sprite& Entity::getSprite() {
	return sprite;
}
void Entity::setHp(int hp) {
	this->hp = hp;
}
void Entity::setDame(int dame) {
	this->dame = dame;
}
void Entity::setShoot(bool status){
	shoot = status;
}
void Entity::setSpeed(Speed speed){
	this->speed = speed;
}
bool Entity::isLife() {
	return hp <= 0;
}
void Entity::draw(RenderWindow &window) {
	window.draw(sprite);
}
