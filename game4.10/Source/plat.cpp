#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "plat.h"

namespace game_framework {
Plat::Plat()
{
}
void Plat::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	focusX = coordinateX;
	focusY = coordinateY;
	
}
void Plat::OnShow()
{
	buttonPic.SetTopLeft(x, y);
	buttonPic.ShowBitmap();
}
void Plat::LoadBitmap(int color)
{
	colorIndex = color;
	switch (colorIndex) {
	case 1:
		buttonPic.LoadBitmap(IDB_BITMAP31, RGB(255, 255, 255));
		break;
	case 2:
		buttonPic.LoadBitmap(IDB_BITMAP32, RGB(255, 255, 255));
		break;
	default:
		break;
	}
		
}
void Plat::GrenOnMove(bool isDown)
{
	if (isDown) {
		if (x >= (focusX - 87)) {
			x -= 1;
		}
	}
	else {
		if (x < focusX) {
			x += 1;
		}
	}
}
void Plat::OnMove(bool isDown)
{
	if (isDown == true) {
		if (y >= (focusY - 68)) {
			y -= 1;
		}
	}
	else {
		if (y < focusY) {
			y += 1;
		}
	}
}
int Plat::GetX()
{
	return x;
}
int Plat::GetY()
{
	return y;
}
int Plat::GetColor()
{
	return colorIndex;
}
int Plat::GetFocusX()
{
	return focusX;
}
int Plat::GetFocusY()
{
	return focusY;
}
}