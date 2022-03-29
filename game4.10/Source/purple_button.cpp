#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "purple_button.h"

namespace game_framework {
PurpleButton::PurpleButton() {
	init();
}
void PurpleButton::init() {
	x = 75;
	y = 200;
}
void PurpleButton::LoadBitmap()
{
	buttonPic.LoadBitmap(IDB_PURPLEBUTTON , RGB(255, 255, 255));
}
void PurpleButton::OnShow()
{
	buttonPic.SetTopLeft(x, y);
	buttonPic.ShowBitmap();
}
}