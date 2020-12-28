#include "ViewControllerBase.h"

void ViewControllerBase::changeScale(sf::Sprite& spr, float height, float width)
{
	auto a = spr.getGlobalBounds();
	float b = a.height, c = a.width;

	if ((b > height) || (c > width))
	{
		float scale = ((height / b) < (width / c)) ? (height / b) : (width / c);
		spr.scale(scale, scale);
		a = spr.getGlobalBounds();
		b = a.height, c = a.width;
	}

	else
	{
		if ((b < height) || (c < width))
		{
			float scale = ((height / b) < (width / c)) ? (height / b) : (width / c);
			spr.setScale(scale, scale);
		}
	}
}
