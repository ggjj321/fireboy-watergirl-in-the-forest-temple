#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "red-diamond.h"

namespace game_framework {
RedDiamond::RedDiamond()
{
}
void RedDiamond::LoadBitmap()
{
	diamondPic.LoadBitmap(IDB_REDDIAMOND, RGB(255, 255, 255));
}
}