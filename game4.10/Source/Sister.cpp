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
	y = 430;
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
	peoplePic.LoadBitmap(IDB_BITMAP7, RGB(255, 255, 255));
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
	peopleAni.AddBitmap(IDB_BITMAP8, RGB(255, 255, 255)); //sister_running
	peopleAni.AddBitmap(IDB_BITMAP9, RGB(255, 255, 255)); //sister_running2
}
void Sister::OnMoveAni()
{
	peopleAni.SetTopLeft(x, y);
	peopleAni.SetDelayCount(10);
	peopleAni.OnShow();
	peopleAni.OnMove();
		
}
}