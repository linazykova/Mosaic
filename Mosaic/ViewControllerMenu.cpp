#include "ViewControllerMenu.h"

ViewControllerMenu::ViewControllerMenu()
{
	Image Im_I;							//image ��� �������� ���� ������� � ��������� ��������

	Im_I.loadFromFile("Fon.jpg");
	//������ ����
	T5.loadFromImage(Im_I);

	Fon.setTexture(T5);
	Fon.setPosition(0, 0);

	int16_t count = 0;

	Im_I.loadFromFile("Image1.jpg");

	if (T1.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image1.setTexture(T1);

		changeScale(Image1, 271, 386);	// ��������� ������� (����������� ���������� �� ����������)
		Image1.setPosition(9, 135);		// ������������� ������ �� ������ ��� �������
		count++;
	}

	else
	{
		std::cout << "���� Image1 �� ������" << std::endl;
	}

	Im_I.loadFromFile("Image2.jpg");

	if (T2.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image2.setTexture(T2);

		changeScale(Image2, 271, 377);	// ��������� ������� (����������� ���������� �� ����������)
		Image2.setPosition(397, 135);	// ������������� ������ �� ������ ��� �����
		count++;
	}

	else
	{
		std::cout << "���� Image2 �� ������" << std::endl;
	}


	Im_I.loadFromFile("Image3.jpg");

	if (T3.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image3.setTexture(T3);

		changeScale(Image3, 299, 386);	// ��������� ������� (����������� ���������� �� ����������)
		Image3.setPosition(9, 408);		// ������������� ������ �� ������ ��� �������
		count++;
	}

	else
	{
		std::cout << "���� Image3 �� ������" << std::endl;
	}


	Im_I.loadFromFile("Image4.jpg");

	if (T4.loadFromImage(Im_I)) 
	{									//���� �������� ��������� ������������� � ����� �������

		Image4.setTexture(T4);

		changeScale(Image4, 299, 377);	// ��������� ������� (����������� ���������� �� ����������)
		Image4.setPosition(397, 408);	// ������������� ������ �� ������ ��� �������
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

	BattonExit1 = new Button(9, 7, 69, 67);
	BattonExit2 = new Button(70, 24, 177, 51);
	BattonStart = new Button(977, 24, 1312, 73);
	BattonIm1 = new Button(9, 135, 395, 406);
	BattonIm2 = new Button(397, 135, 774, 406);
	BattonIm3 = new Button(9, 409, 395, 706);
	BattonIm4 = new Button(397, 408, 774, 706);
	BattonR9 = new Button(815, 150, 1175, 214);
	BattonR16 = new Button(815, 280, 1175, 345);
	BattonR25 = new Button(815, 409, 1175, 473);
	BattonR36 = new Button(815, 540, 1175, 604);

	numImage = diffLvl = none;
}

ViewControllerMenu::~ViewControllerMenu()
{
	delete BattonExit1;
	delete BattonExit2;
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
	if ((BattonExit1->isPress(x, y)) || (BattonExit2->isPress(x, y))) 
	{
		window.close();
		return 0;
	}


	if (BattonStart->isPress(x, y))
	{
		if ((numImage == none) || (diffLvl == none))
		{

			Image Im_I;

			Im_I.loadFromFile("er.png");

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

	if (BattonIm1->isPress(x, y)) { numImage = Im1; }
	else if (BattonIm2->isPress(x, y)) { numImage = Im2; }
	else if (BattonIm3->isPress(x, y)) { numImage = Im3; }
	else if (BattonIm4->isPress(x, y)) { numImage = Im4; }

	else if (BattonR9->isPress(x, y)) { diffLvl = 9; }
	else if (BattonR16->isPress(x, y)) { diffLvl = 16; }
	else if (BattonR25->isPress(x, y)) { diffLvl = 25; }
	else if (BattonR36->isPress(x, y)) { diffLvl = 36; }

	return 0;
}

void ViewControllerMenu::getView(sf::RenderWindow& window)
{
	window.draw(Fon);
	window.draw(Image1);
	window.draw(Image2);
	window.draw(Image3);
	window.draw(Image4);
}
