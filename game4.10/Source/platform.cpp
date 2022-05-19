#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "platform.h"

namespace game_framework {
Platform::Platform()
{
}
void Platform::init(int coordinateX, int coordinateY, int color)
{
	x = coordinateX;
	y = coordinateY;
	focusX = coordinateX;
	focusY = coordinateY;
	colorIndex = color;
}
void Platform::OnShow()
{
	buttonPic.SetTopLeft(x, y);
	buttonPic.ShowBitmap();
}
void Platform::LoadBitmap()
{
	switch (colorIndex) {
	case 1:
		buttonPic.LoadBitmap(IDB_PURPLEPLATFORM, RGB(255, 255, 255));
		break;
	case 2:
		buttonPic.LoadBitmap(IDB_YELLOWPLATFORM, RGB(255, 255, 255));
		break;
	case 3:
		buttonPic.LoadBitmap(IDB_BITMAP31, RGB(255, 255, 255)); // grey
		break;
	case 4:
		buttonPic.LoadBitmap(IDB_BITMAP32, RGB(255, 255, 255)); // green
		break;
	default:
		int a = 1;
	}	
}
void Platform::OnMove(bool isDown)
{
	if (isDown) {
		if (y < (focusY + 60)) {
			y += 1;
		}
	}
	else {
		if (y > focusY) {
			y -= 1;
		}
	}
}
int Platform::GetX()
{
	return x;
}
int Platform::GetY()
{
	return y;
}
int Platform::GetColor()
{
	return colorIndex;
}
int Platform::GetFocusX()
{
	return focusX;
}
int Platform::GetFocusY()
{
	return focusY;
}
}