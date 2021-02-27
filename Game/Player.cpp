#include"Player.hpp"

Player::Player(Sprite &sprite, string name, Speed speed, int hp, int dame, int score, bool shoot){
	this->sprite = sprite;
	this->name = name;
	this->speed = speed;
	this->hp = hp;
	this->dame = dame;
}
void Player::create(Sprite &sprite, string name, Speed speed, int hp, int dame, int score, bool shoot){
	this->sprite = sprite;
	this->name = name;
	this->speed = speed;
	this->hp = hp;
	this->dame = dame;
}
string Player::getName(){
	return name;
}
int Player::getScore(){
	return score;
}
void Player::setName(string name){
	this->name = name;
}
void Player::setScore(int score){
	this->score = score;
}
void Player::ultimate(){
}
