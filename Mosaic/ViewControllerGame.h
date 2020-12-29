#ifndef _VIEW_CONTROLLER_GAME_H_
#define _VIEW_CONTROLLER_GAME_H_

#include "ViewControllerBase.h"
#include "GameSprite.h"
#include "Button.h"


class ViewControllerGame : public ViewControllerBase
{
private:
	sf::RectangleShape* BackFon;

	Texture tGame;					//“екстура картинки, которую нужно собрать
	Texture tFon;					// “екстура фона

	Sprite Fon;						// —прайт фона 
	Sprite t;

	GameSprite* mapGame;

	int16_t length;					// количество мозаек в одной строке

	int16_t height;					//ширина и высота пол€ игры
	int16_t width;

	int16_t Sheight;				//ширина и высота одног окусочка мозайки
	int16_t Swidth;

	int16_t Theight;				//высота текстуры
	int16_t Twidth;					// ширина текстуры

	//Controller
	Button* BMenu;


	bool isWin(sf::RenderWindow& window);

public:
	ViewControllerGame(int16_t numI, int16_t diff);
	~ViewControllerGame();

	int16_t controller(sf::RenderWindow& window, int16_t x, int16_t y) override;
	void getView(sf::RenderWindow& window) override;

	friend class GameSprite;
};


#endif // !_VIEW_CONTROLLER_GAME_H_