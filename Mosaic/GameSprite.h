#ifndef _GAME_SPRITE_H_
#define _GAME_SPRITE_H_

#include "ViewControllerGame.h"

class ViewControllerGame;

class GameSprite
{
private:
	sf::Sprite spr;
	int16_t xPos, yPos;		// Позиция в мозайке по линии
	int16_t position;
	int16_t xBeg, yBeg, xEnd, yEnd;

	void swap(GameSprite& obg);

	friend class ViewControllerGame;
};

#endif // !_GAME_SPRITE_H_