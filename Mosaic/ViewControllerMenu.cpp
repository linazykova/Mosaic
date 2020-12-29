#include "ViewControllerMenu.h"

ViewControllerMenu::ViewControllerMenu()
{
	Image Im_I;							//image для загрузки туда текстур и получения спрайтов

	Im_I.loadFromFile("resources/menu.png");
	//Спрайт фона
	T5.loadFromImage(Im_I);

	Fon.setTexture(T5);
	Fon.setPosition(0, 0);

	int16_t count = 0;

	Im_I.loadFromFile("resources/Image1.jpg");

	if (T1.loadFromImage(Im_I)) 
	{									//Если картинка загружена пользователем в папку проекта

		Image1.setTexture(T1);

		changeScale(Image1, 277, 377);	// Подгоняем размеры (соотношение расширения не искажается)
		Image1.setPosition(7, 132);		// устанавливаем Спрайт на нужную нам позицию
		count++;
	}

	else
	{
		std::cout << "Файл Image1 не найден" << std::endl;
	}

	Im_I.loadFromFile("resources/Image2.jpg");

	if (T2.loadFromImage(Im_I)) 
	{									//Если картинка загружена пользователем в папку проекта

		Image2.setTexture(T2);

		changeScale(Image2, 277, 383);	// Подгоняем размеры (соотношение расширения не искажается)
		Image2.setPosition(391, 132);	// устанавливаем Спрайт на нужную нам позиц
		count++;
	}

	else
	{
		std::cout << "Файл Image2 не найден" << std::endl;
	}


	Im_I.loadFromFile("resources/Image3.jpg");

	if (T3.loadFromImage(Im_I)) 
	{									//Если картинка загружена пользователем в папку проекта

		Image3.setTexture(T3);

		changeScale(Image3, 281, 388);	// Подгоняем размеры (соотношение расширения не искажается)
		Image3.setPosition(7, 420);		// устанавливаем Спрайт на нужную нам позицию
		count++;
	}

	else
	{
		std::cout << "Файл Image3 не найден" << std::endl;
	}


	Im_I.loadFromFile("resources/Image4.jpg");

	if (T4.loadFromImage(Im_I)) 
	{									//Если картинка загружена пользователем в папку проекта

		Image4.setTexture(T4);

		changeScale(Image4, 281, 383);	// Подгоняем размеры (соотношение расширения не искажается)
		Image4.setPosition(391, 420);	// устанавливаем Спрайт на нужную нам позицию
		count++;
	}

	else
	{
		std::cout << "Файл Image4 не найден" << std::endl;
	}

	if (count == 0)
	{
		std::cout << "Ошибка, не загружена ни одна картинка, проверте в папке игры(формат картинок д.б. jpg). Закрытие игры." << std::endl;
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
