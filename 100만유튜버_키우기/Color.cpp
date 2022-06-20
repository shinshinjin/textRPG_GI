#include "Color.h"

void Color::setColor(short text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}