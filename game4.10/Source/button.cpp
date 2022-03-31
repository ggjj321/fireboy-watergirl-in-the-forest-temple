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
int Button::GetX() 
{
	return x;
}
int Button::GetY() 
{
	return y;
}
void Button::SetDown(int downDistance) 
{
	y += downDistance;
}
}