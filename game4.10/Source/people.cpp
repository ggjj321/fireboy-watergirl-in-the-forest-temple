#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "people.h"
namespace game_framework {
People::People() {}
void People::OnMove(bool leftBound, bool rightBound, bool downBound, bool upBound, bool onPlatform, int platformY)
{
	const int XSTEP_SIZE = 5;
	const int YSTEP_SIZE = 4;

	if (downBound && (isJumpimg == false) && (onPlatform == false)) {
		y += downVelocity;
		downVelocity += 1;
	}
	
	if (downBound == false) {
		downVelocity = 0;
	}
	if (isJumpimg) {
		if (upBound == false) {
			isJumpimg = false;
			jumpinVelocity = 0;
		}
		else {
			if (jumpinVelocity == 0 && ((downBound == false) || (onPlatform))) { // 在地上跳起
				jumpinVelocity = 11;
			}
			else if (jumpinVelocity > 0 && (downBound == true)) { // 在空中
				jumpinVelocity -= 1;
			}
			else if (jumpinVelocity == 0 && (downBound == true)) isJumpimg = false; // 結束跳躍
			y -= jumpinVelocity;
		}
	}

	if (onPlatform && (isJumpimg == false)) {
		y = platformY;
		jumpinVelocity = 0;
	} 

	if (isMovingLeft && leftBound)
		x -= XSTEP_SIZE;
	if (isMovingRight && rightBound)
		x += XSTEP_SIZE;

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
int People::GetWidth()
{
	if(isMovingRight) return peopleAniR.Width();

	if (isMovingLeft) return peopleAniL.Width();

	return peoplePic.Width();
}
int People::GetHeight()
{
	if (isMovingRight) return peopleAniR.Height();

	if (isMovingLeft) return peopleAniL.Height();

	return peoplePic.Height();
}
bool People::GetIsMovingLeft() {
	return isMovingLeft;
}
bool People::GetIsMovingRight() {
	return isMovingRight;
}
}