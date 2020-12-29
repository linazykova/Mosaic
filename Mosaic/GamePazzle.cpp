#include "GamePazzle.h"

GamePazzle::~GamePazzle()
{
	delete viewController[menu];

	if (viewController[game] != nullptr)
		delete viewController[game];
}

int16_t GamePazzle::startGame()
{
	bool flag = menu;

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)								//���������� ������ �� controller
			{
			case Event::Closed:
				window.close();
				std::cout << "�����" << std::endl;
				break;

			case Event::MouseButtonPressed:					//������� ������ ����

				if (event.key.code == sf::Mouse::Left)		// � ���� ������������ ������ ����� ������ ����
				{
					if (viewController[flag]->controller(window, event.mouseButton.x, event.mouseButton.y))
					{
						//=> �������� ���� (�������� �������, ��������� ������� � ������ ������ �����)
						if (viewController[game] == nullptr)
						{
							flag = game;
							viewController[game] = new ViewControllerGame(viewController[menu]->getNumImage(), viewController[menu]->getDiffLvl());
						}

						else								//����� �� ���� � ����
						{
							delete viewController[game];
							viewController[game] = nullptr;
							flag = menu;
						}
					}
				}
				break;

			default: break;
			}

		}

		window.clear();

		//���������� ������ �� View
		viewController[flag]->getView(window);

		window.display();
	}

	return 0;
}
