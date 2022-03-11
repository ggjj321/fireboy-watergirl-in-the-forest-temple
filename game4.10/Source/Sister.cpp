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
	isMovingLeft = false;			// �O�_���b��������
	isMovingRight = false;			// �O�_���b���k����
	isJumpimg = false;
}
void Sister::OnMove(bool leftBound, bool rightBound)
{
	const int STEP_SIZE = 2;
	if (isMovingLeft && leftBound)
		x -= STEP_SIZE;
	if (isMovingRight && rightBound)
		x += STEP_SIZE;
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
int Sister::GetX() {
	return x;
}
int Sister::GetY() {
	return y;
}
}