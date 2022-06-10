#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "pointers.h"

namespace game_framework {
Pointers::Pointers()
{
}
void Pointers::init(int cox1, int coy1, int cox2, int coy2, int cox3, int coy3, int cox4, int coy4, int cox5, int coy5)
{
	level = 1;
	x1 = cox1;
	x2 = cox2;
	x3 = cox3;
	x4 = cox4;
	x5 = cox5;
	y1 = coy1;
	y2 = coy2;
	y3 = coy3;
	y4 = coy4;
	y5 = coy5;
}
void Pointers::OnShow()
{
	switch (level)
	{
	case 1:
		pointerOnePic.SetTopLeft(x1, y1);
		pointerOnePic.ShowBitmap();
		break;
	case 2:
		pointerTwoPic.SetTopLeft(x2, y2);
		pointerTwoPic.ShowBitmap();
		break;
	case 3:
		pointerThreePic.SetTopLeft(x3, y3);
		pointerThreePic.ShowBitmap();
		break;
	case 4:
		pointerFourPic.SetTopLeft(x4, y4);
		pointerFourPic.ShowBitmap();
		break;
	case 5:
		pointerFivePic.SetTopLeft(x5, y5);
		pointerFivePic.ShowBitmap();
		break;
	default:
		break;
	}
}
void Pointers::LoadBitmap()
{
	pointerOnePic.LoadBitmap(IDB_POINTER, RGB(255, 255, 255));
	pointerTwoPic.LoadBitmap(IDB_POINTER, RGB(255, 255, 255));
	pointerThreePic.LoadBitmap(IDB_POINTER, RGB(255, 255, 255));
	pointerFourPic.LoadBitmap(IDB_POINTER, RGB(255, 255, 255));
	pointerFivePic.LoadBitmap(IDB_POINTER, RGB(255, 255, 255));
}
void Pointers::NextLevel()
{
	level += 1;
	if (level > 5) level = 1;
}
void Pointers::LastLevel()
{
	level -= 1;
	if (level < 1) level = 5;
}
int Pointers::GetSelectedLevel()
{
	return level;
}
}