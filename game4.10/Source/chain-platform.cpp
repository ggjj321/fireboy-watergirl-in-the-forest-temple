#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "chain-platform.h"

namespace game_framework {
	ChainPlatform::ChainPlatform()
	{
	}
	void ChainPlatform::init(int coordinateX, int coordinateY)
	{
		x = coordinateX;
		y = coordinateY;
	}
	void ChainPlatform::OnShow()
	{
		chainPic.SetTopLeft(x, y);
		chainPic.ShowBitmap();
	}
	void ChainPlatform::LoadBitmap()
	{
		chainPic.LoadBitmap(IDB_CHAINPLATFORM, RGB(255, 255, 255));
	}
}