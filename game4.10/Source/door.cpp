#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "door.h"

namespace game_framework {
Door::Door()
{
}
void Door::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	isTouch = false;
}
void Door::OnShow()
{
	doorPic.SetTopLeft(x, y);
	doorPic.ShowBitmap();
}
void Door::Touch()
{
	isTouch = true;
}
bool Door::GetTouch()
{
	return isTouch;
}
int Door::GetX()
{
	return x;
}
int Door::GetY()
{
	return y;
}

}