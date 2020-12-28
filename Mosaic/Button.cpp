#include "Button.h"

bool Button::isPress(int16_t x, int16_t y)
{
	if ((x >= xBegin) && (y >= yBegin) && (x <= xEnd) && (y <= yEnd))
		return true;

	return false;
}
