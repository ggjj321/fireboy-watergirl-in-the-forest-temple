#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "brother.h"

namespace game_framework {
Brother::Brother() {
	init();
}
void Brother::init() {
	x = 33;
	y = 370;
	jumpinVelocity = 0;
	isMovingLeft = false;			
	isMovingRight = false;			
	isJumpimg = false;
	isSetJumping = false;
}
void Brother::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_BITMAP8, RGB(255, 255, 255));
}
void Brother::AddingBitmap()
{
	peopleAniR.AddBitmap(IDB_BITMAP9, RGB(255, 255, 255));  //right sister_running
	peopleAniR.AddBitmap(IDB_BITMAP10, RGB(255, 255, 255)); //right sister_running2
	peopleAniL.AddBitmap(IDB_BITMAP11, RGB(255, 255, 255)); //left sister_running
	peopleAniL.AddBitmap(IDB_BITMAP12, RGB(255, 255, 255)); //left sister_running2
}
void Brother::OnMoveAniRight()
{
	peopleAniR.SetTopLeft(x, y);
	peopleAniR.SetDelayCount(2);
	peopleAniR.OnShow();
	peopleAniR.OnMove();
}
void Brother::OnMoveAniLeft()
{
	peopleAniL.SetTopLeft(x, y);
	peopleAniL.SetDelayCount(2);
	peopleAniL.OnShow();
	peopleAniL.OnMove();
}
}