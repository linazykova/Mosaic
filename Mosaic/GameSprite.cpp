#include "GameSprite.h"

void GameSprite::swap(GameSprite& obg)
{
	int16_t tmp;

	//x
	tmp = xBeg;
	xBeg = obg.xBeg;
	obg.xBeg = tmp;

	tmp = xEnd;
	xEnd = obg.xEnd;
	obg.xEnd = tmp;

	tmp = xPos;
	xPos = obg.xPos;
	obg.xPos = tmp;


	//y		
	tmp = yBeg;
	yBeg = obg.yBeg;
	obg.yBeg = tmp;

	tmp = yEnd;
	yEnd = obg.yEnd;
	obg.yEnd = tmp;

	tmp = yPos;
	yPos = obg.yPos;
	obg.yPos = tmp;

	//position
	tmp = position;
	position = obg.position;
	obg.position = tmp;

	//Установка нового начала спрайта

	spr.setPosition(xBeg, yBeg);
	obg.spr.setPosition(obg.xBeg, obg.yBeg);
}
