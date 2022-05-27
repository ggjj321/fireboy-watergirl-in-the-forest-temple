#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stone.h"

namespace game_framework {
Stone::Stone() 
{
}
void Stone::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	downVelocity = 0;
}
void Stone::OnShow()
{
	stonePic.SetTopLeft(x, y);
	stonePic.ShowBitmap();
}
void Stone::LoadBitmap()
{
	stonePic.LoadBitmap(IDB_STONE, RGB(255, 255, 255));
}
void Stone::OnMove(bool leftBound, bool rightBound, bool downBound, int sisterX, int sisterY, int brotherX, int brotherY, int sisterWidth, int brotherWidth)
{
	stoneWidth = stonePic.Width();

	// left side is empty and person pushs stone to right side.
	if (leftBound && RightPush(sisterX, sisterY)) x = sisterX - stoneWidth;
	if (leftBound && RightPush(brotherX, brotherY)) x = brotherX - stoneWidth;

	// right side is empty and person pushs stone to right side.
	if (rightBound && LeftPush(sisterX, sisterY, sisterWidth)) x = sisterX + sisterWidth;
	if (rightBound && LeftPush(brotherX, brotherY, brotherWidth)) x = brotherX + brotherWidth;

	if (downBound) {
		y += downVelocity;
		downVelocity += 1;
	}
	else
	{
		downVelocity = 0;
	}
}
bool Stone::RightPush(int peopleX, int peopleY)
{
	const bool isSameHeight = ((y - 10) <= peopleY && peopleY <= (y + 10));
	bool isRightTouch = false;

	if(x<peopleX) isRightTouch = peopleX - x <= stoneWidth;
		
	return isSameHeight && isRightTouch;
}

bool Stone::LeftPush(int peopleX, int peopleY, int peopleWidth)
{
	const bool isSameHeight = ((y - 10) <= peopleY && peopleY <= (y + 10));
	bool isLeftTouch = false;

	if (x > peopleX)isLeftTouch = x - peopleX <= peopleWidth + 10;

	return isSameHeight && isLeftTouch;
}
int Stone::GetX()
{
	return x;
}
int Stone::GetY()
{
	return y;
}
}