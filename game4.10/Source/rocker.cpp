#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rocker.h"

namespace game_framework {
Rocker::Rocker()
{
}
void Rocker::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	focusX = coordinateX;
	focusY = coordinateY;
	isTouch = false;
}
void Rocker::OnShow()
{
	if (isTouch) {
		rockerLeft.SetTopLeft(x, y);
		rockerLeft.ShowBitmap();
	}
	else{
		rockerRight.SetTopLeft(x, y);
		rockerRight.ShowBitmap();
	}
	
}
void Rocker::LoadBitmap()
{
	rockerLeft.LoadBitmap(IDB_ROCKERLEFT, RGB(255, 255, 255));
	rockerRight.LoadBitmap(IDB_ROCKERRIGHT, RGB(255, 255, 255));
}
void Rocker::Touch()
{
	isTouch = !isTouch;
}
int Rocker::GetX()
{
	return focusX;
}
int Rocker::GetY()
{
	return focusY;
}
bool Rocker::GetIsTouch()
{
	return isTouch;
}
}