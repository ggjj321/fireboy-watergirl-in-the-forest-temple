#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "blue-door.h"

namespace game_framework {
BlueDoor::BlueDoor()
{
}
void BlueDoor::LoadBitmap()
{
	doorPic.LoadBitmap(IDB_BLUEDOOR, RGB(255, 255, 255));
}
}