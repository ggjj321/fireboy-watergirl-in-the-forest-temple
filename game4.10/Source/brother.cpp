#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "brother.h"

namespace game_framework {
Brother::Brother() {
}
void Brother::init(int coordinateX, int coordinateY) { // origin 33 400
	x = coordinateX;
	y = coordinateY;
	jumpinVelocity = 0;
	downVelocity = 0;
	isMovingLeft = false;			
	isMovingRight = false;			
	isJumpimg = false;
	isSetJumping = false;
}
void Brother::LoadBitmap()
{
	peoplePic.LoadBitmap(IDB_BROTHER, RGB(255, 255, 255));
}
void Brother::AddingBitmap()
{
	peopleAniR.AddBitmap(IDB_BROTHERRIGHTRUN1, RGB(255, 255, 255));  //right sister_running
	peopleAniR.AddBitmap(IDB_BROTHERRIGHTRUN2, RGB(255, 255, 255)); //right sister_running2
	peopleAniL.AddBitmap(IDB_BROTHERLEFTRUN1, RGB(255, 255, 255)); //left sister_running
	peopleAniL.AddBitmap(IDB_BROTHERLEFTRUN2, RGB(255, 255, 255)); //left sister_running2
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