#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "sister.h"
#include "people.h"
namespace game_framework {
Sister::Sister()
{
	init();
}
void Sister::init() {
	x = 33;
	y = 17 * 2;
	isMovingLeft = false;			// 是否正在往左移動
	isMovingRight = false;			// 是否正在往右移動
	isJumpimg = false;
	isSetJumping = false;
}
void Sister::OnMove(bool leftBound, bool rightBound, bool downBound)
{
	const int XSTEP_SIZE = 3;
	const int YSTEP_SIZE = 4;


	if (downBound) y += YSTEP_SIZE; // 如果腳下為空，根據重力往下掉

	if (isJumpimg) {
		y -= jumpinVelocity;
		jumpinVelocity -= 1;
		if (jumpinVelocity == 0) isJumpimg = false;
	}

	if (isMovingLeft && leftBound)
		x -= XSTEP_SIZE;
	if (isMovingRight && rightBound)
		x += XSTEP_SIZE;
	
}
void Sister::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_SISTER);
}
void Sister::OnShow()
{
	peoplePic.SetTopLeft(x, y);
	peoplePic.ShowBitmap();
}

void Sister::SetMovingLeft(bool flag)
{
	isMovingLeft = flag;
}

void Sister::SetMovingRight(bool flag)
{
	isMovingRight = flag;
}
void Sister::SetJumpimg(bool flag) {
	isJumpimg = flag;
}
int Sister::GetX() {
	return x;
}
int Sister::GetY() {
	return y;
}
}