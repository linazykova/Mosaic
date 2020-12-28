#ifndef _MY_BUTTON_H_
#define _MY_BUTTON_H_

#include "Library.h"

class Button
{
private:
	const int16_t xBegin;
	const int16_t yBegin;
	const int16_t xEnd;
	const int16_t yEnd;

public:
	Button(int16_t xB, int16_t yB, int16_t xE, int16_t yE) : xBegin(xB), yBegin(yB), xEnd(xE), yEnd(yE) {};
	bool isPress(int16_t x, int16_t y);
};

#endif // !_MY_BUTTON_H_