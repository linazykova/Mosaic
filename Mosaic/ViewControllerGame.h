#ifndef _VIEW_CONTROLLER_GAME_H_
#define _VIEW_CONTROLLER_GAME_H_

#include "ViewControllerBase.h"
#include "GameSprite.h"
#include "Button.h"


class ViewControllerGame : public ViewControllerBase
{
private:
	sf::RectangleShape* BackFon;

	Texture tGame;					//�������� ��������, ������� ����� �������
	Texture tFon;					// �������� ����

	Sprite Fon;						// ������ ���� 
	Sprite t;

	GameSprite* mapGame;

	int16_t length;					// ���������� ������ � ����� ������

	int16_t height;					//������ � ������ ���� ����
	int16_t width;

	int16_t Sheight;				//������ � ������ ����� �������� �������
	int16_t Swidth;

	int16_t Theight;				//������ ��������
	int16_t Twidth;					// ������ ��������

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