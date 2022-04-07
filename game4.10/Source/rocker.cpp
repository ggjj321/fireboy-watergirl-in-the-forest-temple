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
	touchStatus = 0;
}
void Rocker::OnShow()
{
	if (touchStatus != 0) {
		touchStatus += 1;
		if (touchStatus == 50) touchStatus = 0; // let rocker's move sleep
	}
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
	if (touchStatus == 0) {
		isTouch = !isTouch;
	}
	touchStatus += 1;
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