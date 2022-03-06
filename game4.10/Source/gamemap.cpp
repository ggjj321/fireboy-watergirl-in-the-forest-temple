#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "gamemap.h"
namespace game_framework {
CGameMap::CGameMap() {
    CGameMap::x = 0;
    CGameMap::y = 0;
}
void CGameMap::OnMove() {

}
void CGameMap::LoadBitMap() {
    firstMap.LoadBitmap(IDB_FINALMAP);
}
void CGameMap::OnShow() {
    firstMap.SetTopLeft(0, 0);
    CGameMap::firstMap.ShowBitmap();
}
}


