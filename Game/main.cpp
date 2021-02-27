#include"Menu.hpp"
#include<Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	Menu menu(Game::getGame()->getWindow());
	menu.draw(Game::getGame()->getWindow());
	return 0;
}
