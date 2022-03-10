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
	isMovingDown = false;			// �O�_���b���U����
	isMovingLeft = false;			// �O�_���b��������
	isMovingRight = false;			// �O�_���b���k����
	isMovingUp = false;			    // �O�_���b���W����
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