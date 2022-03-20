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
	y = 420;
	isMovingLeft = false;			// 是否正在往左移動
	isMovingRight = false;			// 是否正在往右移動
	isJumpimg = false;
}
void Sister::OnMove(bool leftBound, bool rightBound)
{
	const int STEP_SIZE = 4;
	if (isMovingLeft && leftBound)
		x -= STEP_SIZE;
	if (isMovingRight && rightBound)
		x += STEP_SIZE;
}
void Sister::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_BITMAP8, RGB(255, 255, 255));
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
int Sister::GetX() {
	return x;
}
int Sister::GetY() {
	return y;
}
bool Sister::GetIsMovingLeft() {
	return isMovingLeft;
}
bool Sister::GetIsMovingRight() {
	return isMovingRight;
}
void Sister::AddingBitmap()
{
	peopleAniR.AddBitmap(IDB_BITMAP9, RGB(255, 255, 255));  //right sister_running
	peopleAniR.AddBitmap(IDB_BITMAP10, RGB(255, 255, 255)); //right sister_running2
	peopleAniL.AddBitmap(IDB_BITMAP11, RGB(255, 255, 255)); //left sister_running
	peopleAniL.AddBitmap(IDB_BITMAP12, RGB(255, 255, 255)); //left sister_running2
}
void Sister::OnMoveAniRight()
{
	peopleAniR.SetTopLeft(x, y);
	peopleAniR.SetDelayCount(3);
	peopleAniR.OnShow();
	peopleAniR.OnMove();
}
void Sister::OnMoveAniLeft()
{
	peopleAniL.SetTopLeft(x, y);
	peopleAniL.SetDelayCount(3);
	peopleAniL.OnShow();
	peopleAniL.OnMove();
}
}