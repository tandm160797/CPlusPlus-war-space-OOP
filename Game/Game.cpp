#include"Game.hpp"

Game* Game::game = nullptr;
Game::Game() {
	Data::getData("Assets/Paths/FontPath.txt", "Assets/Paths/ImagePath.txt", "Assets/Paths/TexturePath.txt", "Assets/Paths/SoundBufferPath.txt");
	window.create(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Game", Style::Close);
	window.setIcon(Data::getData()->getImages().getElementById(1).getSize().x, Data::getData()->getImages().getElementById(1).getSize().y, Data::getData()->getImages().getElementById(1).getPixelsPtr());
	window.setFramerateLimit(75);
}
RenderWindow& Game::getWindow() {
	return window;
}
Game::~Game() {
	if (game != nullptr) {
		delete game;
		game = nullptr;
	}
}
Game* Game::getGame() {
	if (game == nullptr) {
		game = new Game;
	}
	return game;
}
void Game::run() {
	window.setMouseCursorVisible(false);
	int xMouse, yMouse;
	//
	Sprite cucLua(Data::getData()->getTextures().getElementById(5));
	Animation cucLuaNo(Data::getData()->getTextures().getElementById(5), 0, 0, 50, 50, 0.2, 20);
	Sprite spriteBackground(Data::getData()->getTextures().getElementById(2));
	Sound soundBackground(Data::getData()->getSoundBuffers().getElementById(2));
	Data::getData()->getTextures().getElementById(2).setRepeated(true);
	int rectTopBackground = 0;
	soundBackground.play();
	soundBackground.setLoop(true);
	soundBackground.setVolume(25);
	spriteBackground.setTextureRect(IntRect(0, rectTopBackground, WIDTH_WINDOW, HEIGHT_WINDOW));
	Sprite spritePlayer(Data::getData()->getTextures().getElementById(3));
	Speed speedPlayer(0, 20);
	Player player(spritePlayer, "Mi", speedPlayer, 100, 5);
	vector<Animation> shoot;
	Sound soundPlayer(Data::getData()->getSoundBuffers().getElementById(3));
	Animation explosionPlayer(Data::getData()->getTextures().getElementById(5), 0, 0, 50, 50, 2, 20);
	int xBulletPlayer, yBulletPlayer;
	player.getSprite().setOrigin(Data::getData()->getTextures().getElementById(3).getSize().x / 2, Data::getData()->getTextures().getElementById(3).getSize().y / 2);
	//
	
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			//
			if (event.type == Event::MouseButtonPressed) {
				
				if (event.key.code == Mouse::Left) {
					Animation animationPlayer(Data::getData()->getTextures().getElementById(4), 0, 0, 11, 29, 1, 4);
					animationPlayer.getSprite().setPosition(xBulletPlayer -= player.getSpeed().getDx(), yBulletPlayer -= player.getSpeed().getDy());
					shoot.push_back(animationPlayer);
					soundPlayer.play();
				}
			}
			//
		}
		window.clear();
		rectTopBackground -= 3;
		window.draw(spriteBackground);
		spriteBackground.setTextureRect(IntRect(0, rectTopBackground, WIDTH_WINDOW, HEIGHT_WINDOW));
		//
		if ((Mouse::getPosition(window).x >= 0 && Mouse::getPosition(window).x <= WIDTH_WINDOW) && (Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y <= HEIGHT_WINDOW)) {
			xMouse = Mouse::getPosition(window).x;
			yMouse = Mouse::getPosition(window).y;
			if (xMouse <= 23) {
				xMouse = 23;
			}
			if (xMouse >= 377) {
				xMouse = 377;
			}
			if (yMouse <= 25) {
				yMouse = 25;
			}
			if (yMouse >= 575) {
				yMouse = 575;
			}
		}
		
		player.draw(window);
		player.getSprite().setPosition(xMouse, yMouse);
		for (int i = 0; i < shoot.size(); i++) {
			shoot[i].getSprite().setPosition(xBulletPlayer -= player.getSpeed().getDx(), yBulletPlayer -= player.getSpeed().getDy());
			shoot[i].draw(window);
			shoot[i].update();
			if (xBulletPlayer <= 0 || yBulletPlayer <= 0) {
				xBulletPlayer = player.getSprite().getPosition().x;
				yBulletPlayer = player.getSprite().getPosition().y;
				shoot.pop_back();
			}
		}
		//
		cucLuaNo.draw(window);
		cucLuaNo.update();
		cucLuaNo.getSprite().setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		window.display();
	}
}