#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "sister.h"

namespace game_framework {
Sister::Sister() {
	init();
}
void Sister::init() {
	x = 33;
	y = 345;
	jumpinVelocity = 0;
	downVelocity = 0;
	isMovingLeft = false;			
	isMovingRight = false;			
	isJumpimg = false;
	isSetJumping = false;
}
void Sister::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_BITMAP19, RGB(255, 255, 255));
}
void Sister::AddingBitmap()
{
	peopleAniR.AddBitmap(IDB_BITMAP20, RGB(255, 255, 255));  //right sister_running
	peopleAniR.AddBitmap(IDB_BITMAP21, RGB(255, 255, 255)); //right sister_running2
	peopleAniL.AddBitmap(IDB_BITMAP17, RGB(255, 255, 255)); //left sister_running
	peopleAniL.AddBitmap(IDB_BITMAP18, RGB(255, 255, 255)); //left sister_running2
}
void Sister::OnMoveAniRight()
{
	peopleAniR.SetTopLeft(x, y);
	peopleAniR.SetDelayCount(2);
	peopleAniR.OnShow();
	peopleAniR.OnMove();
}
void Sister::OnMoveAniLeft()
{
	peopleAniL.SetTopLeft(x, y);
	peopleAniL.SetDelayCount(2);
	peopleAniL.OnShow();
	peopleAniL.OnMove();
}
}