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
}
void Sister::OnMove() 
{

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
}