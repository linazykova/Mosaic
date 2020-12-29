#include "GamePazzle.h"
#include <clocale>

int16_t main()
{
	setlocale(LC_ALL, "rus");
	GamePazzle myGame;

	return myGame.startGame();
}