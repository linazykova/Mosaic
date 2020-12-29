#include "GamePazzle.h"
#include <clocale>

int16_t main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "Для добавления свои изображений:\n\t-> Скопируйте нужный вам файл в расширении .JPG в папку resources,"
		"\n\tпредварительно переименовав его в Image[Номер от 1 до 4]." << std::endl;

	GamePazzle myGame;

	return myGame.startGame();
}