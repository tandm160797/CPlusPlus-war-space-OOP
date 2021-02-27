#include"Data.hpp"

Data* Data::data = nullptr;
Data::Data() {}
Data::~Data() {
	if (data != nullptr) {
		delete data;
		data = nullptr;
	}
}
Data::Data(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath) {
	font.loadFromFile(fontPath);
	image.loadFromFile(imagePath);
	texture.loadFromFile(texturePath);
	soundBuffer.loadFromFile(soundBufferPath);
}
Data* Data::getData() {
	if (data == nullptr) {
		data = new Data;
	}
	return data;
}
Data* Data::getData(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath) {
	if (data == nullptr) {
		data = new Data(fontPath, imagePath, texturePath, soundBufferPath);
	}
	return data;
}
void Data::loadFromFile(const string &fontPath, const string &imagePath, const string &texturePath, const string &soundBufferPath) {
	font.loadFromFile(fontPath);
	image.loadFromFile(imagePath);
	texture.loadFromFile(texturePath);
	soundBuffer.loadFromFile(soundBufferPath);
}
DataManager<Font>& Data::getFonts() {
	return font;
}
DataManager<Image>& Data::getImages() {
	return image;
}
DataManager<Texture>& Data::getTextures() {
	return texture;
}
DataManager<SoundBuffer>& Data::getSoundBuffers() {
	return soundBuffer;
}
