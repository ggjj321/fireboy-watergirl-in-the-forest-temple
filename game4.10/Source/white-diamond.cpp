#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "white-diamond.h"

namespace game_framework {
WhiteDiamond::WhiteDiamond()
{
}
void WhiteDiamond::LoadBitmap()
{
	diamondPic.LoadBitmap(IDB_REDDIAMOND, RGB(255, 255, 255));
}
}