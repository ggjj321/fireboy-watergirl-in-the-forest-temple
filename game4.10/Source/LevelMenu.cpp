#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "LevelMenu.h"

namespace game_framework {
LevelMenu::LevelMenu()
{
}
void LevelMenu::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
}
void LevelMenu::OnShow()
{
	MenuPic.SetTopLeft(x, y);
	MenuPic.ShowBitmap();
}
void LevelMenu::LoadBitmap()
{
	MenuPic.LoadBitmap(IDB_LEVELMENU, RGB(255, 255, 255));
}
}