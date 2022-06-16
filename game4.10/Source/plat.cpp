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
	case 3:
		buttonPic.LoadBitmap(IDB_LEVELFOURGREY, RGB(255, 255, 255));
		break;
	case 4:
		buttonPic.LoadBitmap(IDB_LEVELFOURGREEN, RGB(255, 255, 255));
		break;
	case 5:
		buttonPic.LoadBitmap(IDB_LEVELFOURPURPLE, RGB(255, 255, 255));
		break;
	default:
		break;
	}
		
}
void Plat::GrenOnMove(bool isDown, int length)
{
	if (isDown) {
		if (x >= (focusX - length)) {
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

void Plat::level4DownMove(bool isDown)
{
	if (isDown) {
		if (y < (focusY + 52)) {
			y += 1;
		}
	}
	else {
		if (y > focusY) {
			y -= 1;
		}
	}
}

void Plat::level4OnMove(bool isDown)
{
		if (isDown == true) {
			if (y >= (focusY - 51)) {
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