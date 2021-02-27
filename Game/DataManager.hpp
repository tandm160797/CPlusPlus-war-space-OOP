#ifndef DataManager_hpp
#define DataManager_hpp
#include<map>
#include<string>
#include<fstream>
#include"SFML-2.5.1/include/SFML/Audio.hpp"
#include"SFML-2.5.1/include/SFML/Graphics.hpp"
using namespace sf;
using namespace std;

template <class Type>
class DataManager {
private:
	map<int, Type> map;
public:
	DataManager() = default;
	~DataManager() = default;
	DataManager(const string &path);
	void loadFromFile(const string &path);
	Type& getElementById(int id);
};
#include"DataManager.cpp"
#endif //DataManager_hpp
//Use for Font, Image, Texture, SoundBuffer!
