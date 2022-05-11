#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "red-door.h"

namespace game_framework {
RedDoor::RedDoor()
{
}
void RedDoor::LoadBitmap()
{
	doorPic.LoadBitmap(IDB_BITMAP28, RGB(255, 255, 255));
}
}