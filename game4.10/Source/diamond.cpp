#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "diamond.h"

namespace game_framework {
Diamond::Diamond()
{
}
void Diamond::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	isTouch = false;
}
void Diamond::OnShow()
{
	diamondPic.SetTopLeft(x, y);
	if(isTouch == false) diamondPic.ShowBitmap();
}
void Diamond::Touch()
{
	isTouch = true;
}
int Diamond::GetX()
{
	return x;
}
int Diamond::GetY()
{
	return y;
}

}