#include "ViewControllerMenu.h"

ViewControllerMenu::ViewControllerMenu()
{
	Image Im_I;							//image ��� �������� ���� ������� � ��������� ��������

	Im_I.loadFromFile("resources/menu.png");
	//������ ����
	T5.loadFromImage(Im_I);

	Fon.setTexture(T5);
	Fon.setPosition(0, 0);

	int16_t count = 0;

	Im_I.loadFromFile("resources/Image1.jpg");

	if (T1.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image1.setTexture(T1);

		changeScale(Image1, 277, 377);	// ��������� ������� (����������� ���������� �� ����������)
		Image1.setPosition(7, 132);		// ������������� ������ �� ������ ��� �������
		count++;
	}

	else
	{
		std::cout << "���� Image1 �� ������" << std::endl;
	}

	Im_I.loadFromFile("resources/Image2.jpg");

	if (T2.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image2.setTexture(T2);

		changeScale(Image2, 277, 383);	// ��������� ������� (����������� ���������� �� ����������)
		Image2.setPosition(391, 132);	// ������������� ������ �� ������ ��� �����
		count++;
	}

	else
	{
		std::cout << "���� Image2 �� ������" << std::endl;
	}


	Im_I.loadFromFile("resources/Image3.jpg");

	if (T3.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image3.setTexture(T3);

		changeScale(Image3, 281, 377);	// ��������� ������� (����������� ���������� �� ����������)
		Image3.setPosition(7, 420);		// ������������� ������ �� ������ ��� �������
		count++;
	}

	else
	{
		std::cout << "���� Image3 �� ������" << std::endl;
	}


	Im_I.loadFromFile("resources/Image4.jpg");

	if (T4.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image4.setTexture(T4);

		changeScale(Image4, 281, 383);	// ��������� ������� (����������� ���������� �� ����������)
		Image4.setPosition(391, 420);	// ������������� ������ �� ������ ��� �������
		count++;
	}

	else
	{
		std::cout << "���� Image4 �� ������" << std::endl;
	}

	if (count == 0)
	{
		std::cout << "������, �� ��������� �� ���� ��������, �������� � ����� ����(������ �������� �.�. jpg). �������� ����." << std::endl;
		exit(0);
	}

	//For controller 

	BattonExit1 = new Button(2, 4, 298, 70);
	BattonStart = new Button(1093, 3, 1324, 70);

	BattonIm1 = new Button(7, 132, 384, 409);
	BattonIm2 = new Button(391, 132, 774, 409);
	BattonIm3 = new Button(7, 420, 395, 701);
	BattonIm4 = new Button(391, 420, 774, 701);

	BattonR9 = new Button(860, 216, 1285, 315);
	BattonR16 = new Button(860, 320, 1285, 420);
	BattonR25 = new Button(860, 425, 1285, 525);
	BattonR36 = new Button(860, 530, 1285, 629);

	numImage = diffLvl = none;

	choose_rect1.setFillColor(sf::Color::Cyan);
	choose_rect1.setSize(sf::Vector2f(385, 285));
	choose_rect1.setPosition(sf::Vector2f(-385, -285));

	choose_rect2.setFillColor(sf::Color::Red);
	choose_rect2.setSize(sf::Vector2f(421, 105));
	choose_rect2.setPosition(sf::Vector2f(-421, -105));

	// ����������� ������
	font_error = false;
	if (!font.loadFromFile("resources/fonts/calibri.ttf"))
	{
		std::cout << "\nFont error!" << std::endl;
		font_error = true;
	}

	if (!font_error)
	{
		choose_text.setFont(font);
		choose_text.setString(L"�������");
		choose_text.setCharacterSize(50);
		choose_text.setStyle(sf::Text::Bold);
		choose_text.setPosition(sf::Vector2f(970, 128));
	}
}

ViewControllerMenu::~ViewControllerMenu()
{
	delete BattonExit1;
	delete BattonStart;
	delete BattonIm1;
	delete BattonIm2;
	delete BattonIm3;
	delete BattonIm4;
	delete BattonR9;
	delete BattonR16;
	delete BattonR25;
	delete BattonR36;
}

ViewControllerBase* ViewControllerMenu::Instance()
{
	static ViewControllerBase* shared;

	if (!shared)
		shared = new ViewControllerMenu();
	return shared;
}

int16_t ViewControllerMenu::controller(sf::RenderWindow& window, int16_t x, int16_t y)
{
	if (BattonExit1->isPress(x, y)) 
	{
		window.close();
		return 0;
	}


	if (BattonStart->isPress(x, y))
	{
		if ((numImage == none) || (diffLvl == none))
		{

			Image Im_I;

			Im_I.loadFromFile("resources/er.png");

			Texture T;
			T.loadFromImage(Im_I);

			Sprite er;
			er.setTexture(T);
			er.setPosition(402, 269);
			window.draw(er);
			window.display();
			sf::sleep(sf::seconds(3));
			return 0;
		}
		return 1;
	}

	float _x, _y;
	_x = _y = 0.0f;

	if (BattonIm1->isPress(x, y)) { numImage = Im1; choose_rect1.setPosition(sf::Vector2f(3, 126)); }
	else if (BattonIm2->isPress(x, y)) { numImage = Im2; choose_rect1.setPosition(sf::Vector2f(3 + 385, 126)); }
	else if (BattonIm3->isPress(x, y)) { numImage = Im3; choose_rect1.setPosition(sf::Vector2f(3, 126 + 290)); }
	else if (BattonIm4->isPress(x, y)) { numImage = Im4; choose_rect1.setPosition(sf::Vector2f(3 + 385, 126 + 290)); }

	else if (BattonR9->isPress(x, y)) { diffLvl = 9; choose_rect2.setPosition(sf::Vector2f(859, 212)); _x = 970; _y = 233; }
	else if (BattonR16->isPress(x, y)) { diffLvl = 16; choose_rect2.setPosition(sf::Vector2f(859, 212 + 104)); _x = 970; _y = 338; }
	else if (BattonR25->isPress(x, y)) { diffLvl = 25; choose_rect2.setPosition(sf::Vector2f(859, 212 + 104 + 105)); _x = 970; _y = 443; }
	else if (BattonR36->isPress(x, y)) { diffLvl = 36; choose_rect2.setPosition(sf::Vector2f(859, 212 + 104 + 105 + 105)); _x = 970; _y = 548; }

	if (!font_error && _x != 0.0f && y != 0.0f) choose_text.setPosition(sf::Vector2f(_x, _y));

	return 0;
}

void ViewControllerMenu::getView(sf::RenderWindow& window)
{
	window.draw(Fon);

	window.draw(choose_rect1);
	window.draw(choose_rect2);
	if (!font_error) window.draw(choose_text);

	window.draw(Image1);
	window.draw(Image2);
	window.draw(Image3);
	window.draw(Image4);

	
}
