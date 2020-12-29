#ifndef _VIEW_CONTROLLER_BASE_H_
#define _VIEW_CONTROLLER_BASE_H_

#include "Library.h"

class ViewControllerBase
{
protected:
	int16_t numImage;															// номер текущей выбраной картинки
	int16_t diffLvl;															// уровень сложности 

public:
	virtual ~ViewControllerBase() = default;

	virtual void getView(sf::RenderWindow & window) = 0;
	virtual int16_t controller(sf::RenderWindow & window, int16_t x, int16_t y) = 0;

	int16_t getNumImage() { return numImage; };
	int16_t getDiffLvl() { return diffLvl; };

	void setNumImage(int16_t num) { numImage = num; };
	void setDiffLvl(int16_t dif) { diffLvl = dif; };

	void changeScale(sf::Sprite& spr, float height, float width);
};

#endif // !_VIEW_CONTROLLER_BASE_H_