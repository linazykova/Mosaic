#ifndef _VIEW_CONTROLLER_MENU_H_
#define _VIEW_CONTROLLER_MENU_H_

#include "ViewControllerBase.h"
#include "Button.h"

enum { none, Im1, Im2, Im3, Im4 };

class ViewControllerMenu : public ViewControllerBase
{
private:
	//For ViewMenu
	Texture T1, T2, T3, T4, T5;

	Sprite Fon;

	Sprite Image1;//4 загруженных пользователем картинки
	Sprite Image2;
	Sprite Image3;
	Sprite Image4;

	//For ControllerMenu
	Button* BattonExit1;
	Button* BattonExit2;
	Button* BattonStart;
	Button* BattonIm1;
	Button* BattonIm2;
	Button* BattonIm3;
	Button* BattonIm4;
	Button* BattonR9;
	Button* BattonR16;
	Button* BattonR25;
	Button* BattonR36;


	ViewControllerMenu();
	ViewControllerMenu(const ViewControllerMenu& obg) = delete;

public:
	~ViewControllerMenu();

	static ViewControllerBase* Instance();

	int16_t controller(sf::RenderWindow& window, int16_t x, int16_t y) override;
	void getView(sf::RenderWindow& window) override;
};


#endif // !_VIEW_CONTROLLER_MENU_H_