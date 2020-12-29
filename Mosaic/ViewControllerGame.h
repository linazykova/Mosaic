#ifndef _VIEW_CONTROLLER_GAME_H_
#define _VIEW_CONTROLLER_GAME_H_

#include "ViewControllerBase.h"


class ViewControllerGame : public ViewControllerBase
{
private:

public:
	int16_t controller(sf::RenderWindow& window, int16_t x, int16_t y) override;
	void getView(sf::RenderWindow& window) override;
};


#endif // !_VIEW_CONTROLLER_GAME_H_