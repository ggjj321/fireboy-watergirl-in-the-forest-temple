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
	isMovingLeft = false;			// �O�_���b��������
	isMovingRight = false;			// �O�_���b���k����
	isJumpimg = false;
	isSetJumping = false;
}
void People::OnMove(bool leftBound, bool rightBound, bool downBound)
{
	const int XSTEP_SIZE = 3;
	const int YSTEP_SIZE = 4;


	if (downBound) y += YSTEP_SIZE; // �p�G�}�U���šA�ھڭ��O���U��

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