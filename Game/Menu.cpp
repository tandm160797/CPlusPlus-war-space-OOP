#include"Menu.hpp"

Menu::Menu(RenderWindow &window) {
	selectedItemIndex = 0;
	//
	text[0].setString("Play");
	text[1].setString("Info");
	text[2].setString("Exit");
	//
	text[0].setFillColor(Color::Red);
	text[1].setFillColor(Color::White);
	text[2].setFillColor(Color::White);
	//
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		text[i].setFont(Data::getData()->getFonts().getElementById(1));
		text[i].setOrigin((text[i].getGlobalBounds().width) / 2, text[i].getGlobalBounds().height / 2);
		text[i].setPosition(window.getSize().x / 2, ((window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1))*i) + (window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1)));
	}
}
void Menu::create(RenderWindow &window) {
	selectedItemIndex = 0;
	//
	text[0].setString("Play");
	text[1].setString("Options");
	text[2].setString("Exit");
	//
	text[0].setFillColor(Color::Red);
	text[1].setFillColor(Color::White);
	text[2].setFillColor(Color::White);
	//
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		text[i].setFont(Data::getData()->getFonts().getElementById(1));
		text[i].setOrigin((text[i].getGlobalBounds().width) / 2, text[i].getGlobalBounds().height / 2);
		text[i].setPosition(window.getSize().x / 2, ((window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1))*i) + (window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1)));
	}
}
void Menu::draw(RenderWindow &window) {
	Sprite spriteMenu(Data::getData()->getTextures().getElementById(1));
	Sound soundMenu(Data::getData()->getSoundBuffers().getElementById(1));
	soundMenu.play();
	soundMenu.setLoop(true);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			//
			if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Up: {
					moveUp();
					break;
				}
				case Keyboard::Down: {
					moveDown();
					break;
				}
				case Keyboard::Return: {
					switch (getPressedItem()) {
					case 0: {
						soundMenu.pause();
						Game::getGame()->run();
						break;
					}
					case 1: {
						Text info(L"Phương pháp lập trình hướng đối tượng!", Data::getData()->getFonts().getElementById(1), 14);
						Text back(L"Nhấn ESC để trở lại!", Data::getData()->getFonts().getElementById(1), 20);
						info.setFillColor(Color::White);
						info.setStyle(Text::Bold | Text::Italic);
						back.setOrigin(back.getGlobalBounds().width / 2, back.getGlobalBounds().height / 2);
						back.setFillColor(Color::Red);
						back.setPosition(window.getSize().x / 2, window.getSize().y / 2);
						//
						while (window.isOpen()) {
							Event event;
							while (window.pollEvent(event)) {
								if (event.type == Event::Closed) {
									window.close();
								}
								//
								if (event.type == Event::KeyPressed) {
									if (event.key.code == Keyboard::Escape) {
										soundMenu.pause();
										draw(window);
									}
								}
							}
							window.clear();
							window.draw(spriteMenu);
							window.draw(info);
							window.draw(back);
							window.display();
						}
						//
						break;
					}
					case 2: {
						soundMenu.pause();
						window.close();
					}
					default: {
						break;
					}
					}
					break;
				}
				default: {
					break;
				}
				}
			}
		}
		window.clear();
		window.draw(spriteMenu);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
			window.draw(text[i]);
		}
		window.display();
	}
}
void Menu::moveUp() {
	if (selectedItemIndex > 0) {
		text[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Menu::moveDown() {
	if (selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1) {
		text[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setFillColor(Color::Red);
	}
}
int Menu::getPressedItem() {
	return selectedItemIndex;
}
