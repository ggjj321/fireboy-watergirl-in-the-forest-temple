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
void Button::init(int coordinateX, int coordinateY, int color)
{
	x = coordinateX;
	y = coordinateY;
	focusX = coordinateX;
	focusY = coordinateY;
	colorIndex = color;
}
void Button::OnShow()
{
	buttonPic.SetTopLeft(x, y);
	buttonPic.ShowBitmap();
}
void Button::LoadBitmap()
{
	switch (colorIndex) {
	case 1:
		buttonPic.LoadBitmap(IDB_PURPLEBUTTON, RGB(255, 255, 255));
	default:
		int a = 1;
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