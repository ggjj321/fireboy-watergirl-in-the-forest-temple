#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "button.h"

namespace game_framework {
Button::Button() 
{
}
void Button::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	focusX = coordinateX;
	focusY = coordinateY;
}
void Button::OnShow()
{
	buttonPic.SetTopLeft(x, y);
	buttonPic.ShowBitmap();
}
void Button::LoadBitmap(int color)
{
	colorIndex = color;
	switch (colorIndex) {
	case 1:
		buttonPic.LoadBitmap(IDB_PURPLEBUTTON, RGB(255, 255, 255));
		break;
	case 2:
		buttonPic.LoadBitmap(IDB_BITMAP34, RGB(255, 255, 255)); // white
		break;
	case 3:
		buttonPic.LoadBitmap(IDB_BITMAP33, RGB(255, 255, 255)); // green
		break;
	default:
		break;
	}	
}
void Button::OnMove(bool isDown)
{
	if (isDown)y = focusY + 7;
	else y = focusY;
}
int Button::GetX() 
{
	return focusX;
}
int Button::GetY() 
{
	return focusY;
}
int Button::GetColor()
{
	return colorIndex;
}
}