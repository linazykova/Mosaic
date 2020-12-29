#include "ViewControllerGame.h"

bool ViewControllerGame::isWin(sf::RenderWindow& window)
{
	for (int16_t i = 0; i < diffLvl; i++) 
	{
		if (mapGame[i].position != i)
			return false;
	}

	window.clear();
	getView(window);
	window.display();

	//����� �������� "�� ��������"
	sf::sleep(sf::seconds(2));
	window.clear();
	getView(window);

	Texture wT;
	wT.loadFromFile("resources/win.png");

	Sprite win;
	win.setTexture(wT);
	win.setPosition(402, 269);
	window.draw(win);
	window.display();

	sf::sleep(sf::seconds(3));

	//����������� � ����
	return true;
}

ViewControllerGame::ViewControllerGame(int16_t numI, int16_t diff)
{
	try 
	{
		if ((numI < 1) || (numI > 4))
			throw numI;

		if (!((diff == 9) || (diff == 16) || (diff == 25) || (diff == 36)))
			throw diff;

		numImage = numI;
		diffLvl = diff;
	}

	catch (int16_t num) 
	{
		std::cout << "������, �� ������� �������� �������� ����." << std::endl;
		exit(0);
	}

	length = sqrt(diff);

	// ����� �������� �� ������ ���� + �������� ����
	try 
	{
		Image Im_I;

		if (Im_I.loadFromFile("resources/game.png") != false) 
		{
			tFon.loadFromImage(Im_I);

			Fon.setTexture(tFon);
			Fon.setPosition(0, 0);
		}

		else 
		{
			std::cout << "������ �������� ���� ����, ���� ���� �� �����, ������������ ������������� ����" << std::endl;
		}

		//����� �������� ��� ����, ������ �� ������ �� ����
		int16_t count = 0;

		if (numImage == 1) 
		{
			Im_I.loadFromFile("resources/Image1.jpg");
			tGame.loadFromImage(Im_I);
			count++;
		}

		else if (numImage == 2)
		{
			Im_I.loadFromFile("resources/Image2.jpg");
			tGame.loadFromImage(Im_I);
			count++;
		}

		else if (numImage == 3)
		{
			Im_I.loadFromFile("resources/Image3.jpg");
			tGame.loadFromImage(Im_I);
			count++;
		}

		else if (numImage == 4)
		{
			Im_I.loadFromFile("resources/Image4.jpg");
			tGame.loadFromImage(Im_I);
			count++;
		}

		else
		{
			throw numImage;
		}
	}
	catch (int16_t numImage)
	{								// ������ ������ ���� �� ������, �� �� ��, �� ������ ������
		std::cout << "������, �� ������� �������� ��� ��� ������ �� ���������, �������� � ����� ����(������ �������� �.�. jpg). �������� ����." << std::endl;
		exit(0);
	}

	//���������� �������� �������� ����, � ����������� �� �������� ��� �� �� �������� �����������
	//����� �������� .������� �������� ���� ��������  1300�700
	try 
	{
		//y
		height = int16_t(700 / length) * length;

		//x
		width = int16_t(1300 / length) * length;		// ��� �� ���������� �� ������ ��� �������

		//���������� �������� �������� ����:
		Sprite tmpSpr;
		tmpSpr.setTexture(tGame);

		Theight = tmpSpr.getGlobalBounds().height;		//�������� ������� ������ � ������ ��������
		Twidth = tmpSpr.getGlobalBounds().width;

		if ((Theight < 100) || (Twidth < 100))
			throw Theight;

		changeScale(tmpSpr, height, width);				//����������� �������� ��� ������ ���� 

		// ������� ������� �������� �������� ����
		height = (int16_t)tmpSpr.getGlobalBounds().height;
		width = (int16_t)tmpSpr.getGlobalBounds().width;

		height = int16_t(height / length) * length;
		width = int16_t(width / length) * length;
	}
	catch (int16_t th) 
	{
		std::cout << "��������, �������� �������� ����� ������, ��� ��� � �� ������� ������ ����������." << std::endl;
	}

	//������ � ������ 1 ����� �� ������� ����
	Sheight = height / length;
	Swidth = width / length;


	//������� �������� ���� ������
	mapGame = new GameSprite[diff];						//������ ������ �� dif(9||16||25||36) ��������

	//��������� ������������� �������
	for (int16_t i = 0; i < diff; i++)
	{
		mapGame[i].position = diff - i - 1;
	}

	srand(time(NULL));

	//� ��������� ������� ������������ �������
	for (int16_t i = 0; i < 1000; i++) 
	{

		int16_t a = rand() % (diff);
		int16_t b = rand() % (diff);
		int16_t tmp = 0;

		//swap
		tmp = mapGame[a].position;
		mapGame[a].position = mapGame[b].position;
		mapGame[b].position = tmp;
	}


	//������������� x, y, � spr(Sprite)
	for (int16_t i = 0; i < diff; i++) 
	{
		mapGame[i].xPos = mapGame[i].position % length;		//������������ ������� � ������� � ����������� �� ���������� ������������� �� �������
		mapGame[i].yPos = mapGame[i].position / length;		//�� ��������

		//���������� ��������� ������ � ����� ������� ������������ ���������� ������� ��������� - (0,0) �� ������
		mapGame[i].xBeg = mapGame[i].xPos * Swidth;
		mapGame[i].yBeg = mapGame[i].yPos * Sheight;

		mapGame[i].xEnd = (mapGame[i].xPos + 1) * Swidth - 1;
		mapGame[i].yEnd = (mapGame[i].yPos + 1) * Sheight - 1;

		//��������� ����������� ������, ������������� ������(������� �� ��������) � ������������� ����� ������ �������
		mapGame[i].spr.setTexture(tGame);

		//--------------------------------------------------------------------------------------------------------------------------------
		//                                    |x ������ ������� |y ������ �������  | ������ | ������|
		mapGame[i].spr.setTextureRect(sf::IntRect((i % length) * (Twidth / length), (i / length) * (Theight / length),
			(Twidth / length), (Theight / length)));					//0 ������� ������� - 0,0 ������ �������, 1 - 0,1 � �.�

		changeScale(mapGame[i].spr, Sheight, Swidth);
		mapGame[i].spr.setPosition(mapGame[i].xBeg, mapGame[i].yBeg);	//�� ������� ������� �� ������� ���� ������ position
	}

	//�������� ������� ���� �������� ����
	BackFon = new sf::RectangleShape(sf::Vector2f(width + 5, height + 5));
	BackFon->setFillColor(sf::Color::Black);


	//Controller
	BMenu = new Button(0, 708, 213, 767);								//������ ������ � ����
}

ViewControllerGame::~ViewControllerGame()
{
	if (mapGame != nullptr)
		delete[]mapGame;

	if (BackFon != nullptr)
		delete BackFon;

	if (BMenu != nullptr)
		delete BMenu;
}

int16_t ViewControllerGame::controller(sf::RenderWindow& window, int16_t x, int16_t y)
{
	//������ ����
	if (BMenu->isPress(x, y)) 
	{
		return 1;													//���������� 1, ������� � ����
	}

	//����������� ��������� ������� ������()
	//���� ������ �� ������� ����, ����� ��������� ������������
	if (x < width, y < height) {
																	//������� ���� �� ������� ����
		bool isReleased = false;
		int16_t xEndState;
		int16_t yEndState;
		int16_t pressedPosition = -1;


		try 
		{
			//���� ����� c������ �� ������� ������
			for (int16_t i = 0; i < diffLvl; i++) 
			{
				if ((mapGame[i].xBeg < x) && (mapGame[i].yBeg < y) && (mapGame[i].xEnd > x) && (mapGame[i].yEnd > y)) 
				{
					pressedPosition = i;							//��������� ������� ������ �� ������� ������ 
					break;
				}
			}

			if (pressedPosition == -1)						//���-�� ����� �� ���, ��� �� ���� �� ������� ������������ � �������� ���� ����
				throw pressedPosition;
		}

		catch (int16_t pp)
		{
			return 0;
		}

		while (window.isOpen()) 
		{
			//C�������� ���������� �����
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//�������� ���������� �������
			sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
			sf::Event event;

			while (window.pollEvent(event)) 
			{

				if (event.type == sf::Event::Closed)
				{
					window.close();
					std::cout << "�����" << std::endl;
				}

				if (event.type == sf::Event::MouseButtonReleased) 
				{																	//���� ������ ������

					if (event.key.code == sf::Mouse::Left)
					{																// � ���� ������������ ������ ����� ������ ����
																					//�������� x, y ��������� ��������� ����
						xEndState = event.mouseButton.x;
						yEndState = event.mouseButton.y;

						if (!(xEndState < width && yEndState < height)) 
						{
							mapGame[pressedPosition].spr.setPosition(mapGame[pressedPosition].xBeg, mapGame[pressedPosition].yBeg);
							return 0;
						}

						isReleased = true;
						break;
					}
				}
			}

			if (isReleased)
				break;

										
			window.clear();				//����� ������ 
			window.draw(Fon);			//������ ���
			window.draw(*BackFon);		//������ ������ ��� �������� ������������


			for (int16_t i = 0; i < diffLvl; i++) 
			{
				//������ ��� �������, ����� pressedPosition
				if (i != pressedPosition)
					window.draw(mapGame[i].spr);
			}

			//������ ��������������� ������ Drug and drop
			mapGame[pressedPosition].spr.setPosition(mapGame[pressedPosition].xBeg - x + pos.x,		// x
				mapGame[pressedPosition].yBeg - y + pos.y);											// y
			window.draw(mapGame[pressedPosition].spr);
			window.display();
		}

		//��������� ���� ���������� ����� 
		int16_t EndPos = -1;

		try 
		{
			//���� ����� c������ �� ������� ������
			for (int16_t i = 0; i < diffLvl; i++) 
			{
				if ((mapGame[i].xBeg < xEndState) && (mapGame[i].yBeg < yEndState) &&
					(mapGame[i].xEnd > xEndState) && (mapGame[i].yEnd > yEndState)) 
				{
					EndPos = i;														//��������� ������� ������ �� ������� ������ 
					break;
				}
			}

			if (EndPos == -1)								//���-�� ����� �� ���, ��� �� ���� �� ������� ������������ � �������� ���� ����
				throw EndPos;
		}

		catch (int16_t pp)
		{
			return 0;
		}

		//������ ������� ������� �a����, �����, � �������
		mapGame[EndPos].swap(mapGame[pressedPosition]);

		if (isWin(window))
			return 1;
	}

	return 0;
}

void ViewControllerGame::getView(sf::RenderWindow& window)
{
	window.draw(Fon);					//������ ���
	window.draw(*BackFon);				//������ ������ ��� �������� ������������

	for (int16_t i = 0; i < diffLvl; i++) 
	{
		window.draw(mapGame[i].spr);
	}
}
