#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "blue-diamond.h"

namespace game_framework {
BlueDiamond::BlueDiamond()
{
}
void BlueDiamond::LoadBitmap()
{
	diamondPic.LoadBitmap(IDB_BLUEDIAMOND, RGB(255, 255, 255));
}
}