#ifndef _GAME_PAZZLE_H_
#define _GAME_PAZZLE_H_

#include "ViewControllerMenu.h"
#include "ViewControllerGame.h"

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

typedef sf::Event Event;

enum { menu, game };

class GamePazzle
{
private:
	sf::RenderWindow window;
	ViewControllerBase* viewController[2];

public:
	GamePazzle(const GamePazzle&) = delete;
	~GamePazzle();

	GamePazzle(int16_t x = SCREEN_WIDTH, int16_t y = SCREEN_HEIGHT) : window(sf::VideoMode(x, y), "GamePazzle", sf::Style::Titlebar)
	{
		viewController[menu] = ViewControllerMenu::Instance();
		viewController[game] = nullptr;
	}

	int16_t startGame();
};

#endif // !_GAME_PAZZLE_H_