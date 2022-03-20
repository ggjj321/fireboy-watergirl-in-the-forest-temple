#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "people.h"
namespace game_framework {
People::People() {}
void People::init() {
	x = 33;
	y = 17 * 2;
	isMovingLeft = false;			// 是否正在往左移動
	isMovingRight = false;			// 是否正在往右移動
	isJumpimg = false;
	isSetJumping = false;
}
void People::OnMove(bool leftBound, bool rightBound, bool downBound)
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
void People::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_SISTER);
}
void People::OnShow()
{
	peoplePic.SetTopLeft(x, y);
	peoplePic.ShowBitmap();
}

void People::SetMovingLeft(bool flag)
{
	isMovingLeft = flag;
}

void People::SetMovingRight(bool flag)
{
	isMovingRight = flag;
}
void People::SetJumpimg(bool flag) {
	isJumpimg = flag;
}
int People::GetX() {
	return x;
}
int People::GetY() {
	return y;
}
}