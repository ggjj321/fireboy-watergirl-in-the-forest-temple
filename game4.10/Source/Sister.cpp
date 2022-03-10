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
	x = 33;
	y = 320;
	isMovingDown = false;			// 是否正在往下移動
	isMovingLeft = false;			// 是否正在往左移動
	isMovingRight = false;			// 是否正在往右移動
	isMovingUp = false;			    // 是否正在往上移動
}
void Sister::OnMove() 
{
	const int STEP_SIZE = 2;
	if (isMovingLeft)
		x -= STEP_SIZE;
	if (isMovingRight)
		x += STEP_SIZE;
	if (isMovingUp)
		y -= STEP_SIZE;
	if (isMovingDown)
		y += STEP_SIZE;
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
void Sister::SetMovingDown(bool flag)
{
	isMovingDown = flag;
}

void Sister::SetMovingLeft(bool flag)
{
	isMovingLeft = flag;
}

void Sister::SetMovingRight(bool flag)
{
	isMovingRight = flag;
}

void Sister::SetMovingUp(bool flag)
{
	isMovingUp = flag;
}
}