#ifndef Data_hpp
#define Data_hpp
#include"DataManager.hpp"

class Data {
private:
	static Data* data;
	Data();
	Data(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath);
	DataManager<Font> font;
	DataManager<Image> image;
	DataManager<Texture> texture;
	DataManager<SoundBuffer> soundBuffer;
public:
	~Data();
	static Data* getData();
	static Data* getData(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath);
	void loadFromFile(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath);
	DataManager<Font>& getFonts();
	DataManager<Image>& getImages();
	DataManager<Texture>& getTextures();
	DataManager<SoundBuffer>& getSoundBuffers();
};
#endif //Data_hpp
