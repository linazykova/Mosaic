#include "GamePazzle.h"
#include <clocale>

int16_t main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "��� ���������� ���� �����������:\n\t-> ���������� ������ ��� ���� � ���������� .JPG � ����� resources,"
		"\n\t�������������� ������������ ��� � Image[����� �� 1 �� 4]." << std::endl;

	GamePazzle myGame;

	return myGame.startGame();
}