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
void Brother::init() { // origin 33 400
	x = 33;
	y = 400;
	jumpinVelocity = 0;
	downVelocity = 0;
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
	peopleAniR.AddBitmap(IDB_BITMAP15, RGB(255, 255, 255));  //right sister_running
	peopleAniR.AddBitmap(IDB_BITMAP16, RGB(255, 255, 255)); //right sister_running2
	peopleAniL.AddBitmap(IDB_BITMAP13, RGB(255, 255, 255)); //left sister_running
	peopleAniL.AddBitmap(IDB_BITMAP14, RGB(255, 255, 255)); //left sister_running2
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