#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "gamemap.h"
namespace game_framework {
CGameMap::CGameMap(){
    x = 0;
    y = 0;
    mapLevel = 1; // set to 1
    ReadMapData();
}
void CGameMap::OnMove(){

}
void CGameMap::LoadBitMap() {
    firstMap.LoadBitmap(IDB_FINALMAP);
    secondMap.LoadBitmap(IDB_FINALMAP2);
}
void CGameMap::OnShow() {
    switch (mapLevel)
    {
    case 1:
        firstMap.SetTopLeft(x, y);
        firstMap.ShowBitmap();
        break;
    case 2:
        secondMap.SetTopLeft(x, y);
        secondMap.ShowBitmap();
        break;
    default:
        break;
    }
    
}
void CGameMap::ReadMapData() noexcept {
    int map1Origin[29][47] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},// 0
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 1
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 2
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 3
                    {1,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 4
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 5
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},// 6
                    {1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 7
                    {1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 8
                    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,1},// 9
                    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,1},// 10
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1},// 11
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1},// 12
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 13
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 14
                    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 15
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},// 16
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},// 17
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},// 18
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},// 19
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 20
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 21
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,5,5,5,5,5,1,1,1,1,1,1,2,0,0,0,0,0,1},// 22
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 23
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},// 24
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1},// 25
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},// 26
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},// 27
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,1,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1} };//28
    
    int map2Origin[29][39] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 0
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 1
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 2
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 3
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 4
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,1}, // 5
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,0,0,0,0,0,0,1}, // 6
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1}, // 7
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 8
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, // 9
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, // 10
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, // 11
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}, // 12
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}, // 13
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}, // 14
                    {1,0,0,0,0,1,1,1,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,5,5,5,5,5,5,5,1,1,1,1,1,1,1,1,1}, // 15
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 16
                    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 17
                    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 18
                    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 19
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,1}, // 20
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 21
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 22
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 23
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1}, // 24
                    {1,0,0,0,0,0,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,2,1,1,1}, // 25
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, // 26
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, // 27
                    {1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1} };

    switch (mapLevel)
    {
    case 1:
        for (int y = 0; y < 29; y++) {
            for (int x = 0; x < 47; x++) {
                mapArray[y][x] = map1Origin[y][x];
            }
        }
        gridSizeWeight = 13.61; // 640 / 47
        gridSizeHeight = 16.55; // 480 / 29
        break;
    case 2:
        for (int y = 0; y < 29; y++) {
            for (int x = 0; x < 39; x++) {
                mapArray[y][x] = map2Origin[y][x];
            }
        }
        gridSizeWeight = 16.41; // 640 / 39
        gridSizeHeight = 16.55; // 480 / 29
        break;
    }
}
bool CGameMap::isEmpty(int x, int y) noexcept {
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    if (mapArray[gy][gx] == 0)return TRUE;
    else return FALSE;
}
bool CGameMap::isFull(int x, int y) noexcept {
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    if (mapArray[gy][gx] == 1)return TRUE;
    else return FALSE;
}
bool CGameMap::isRedWater(int x, int y) noexcept {  // ����:3
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    if (mapArray[gy][gx] == 3)return TRUE;
    else return FALSE;
}
bool CGameMap::isBlueWater(int x, int y) noexcept {  // �Ť�:4
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    if (mapArray[gy][gx] == 4)return TRUE;
    else return FALSE;
}
bool CGameMap::isGreenWater(int x, int y) noexcept {  // ���:5
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    if (mapArray[gy][gx] == 5)return TRUE;
    else return FALSE;
}

int CGameMap::GetGx(int x) {
    return (int)(x / gridSizeWeight);
}
int CGameMap::GetGy(int y) {
    return (int)(y / gridSizeHeight);
}

void CGameMap::ChangeArray(int x, int y, int num) {
    const int gx = GetGx(x);
    const int gy = GetGy(y);
    mapArray[gy][gx] = num;
}
void CGameMap::LastLevel() {
    if (mapLevel - 1 > 0) mapLevel -= 1;
    ReadMapData();
}
void CGameMap::NextLevel() {
    mapLevel += 1;
    ReadMapData();
}
bool CGameMap::isSameArray(int x1, int y1, int x2, int y2) 
{
    const int gx1 = GetGx(x1);
    const int gy1 = GetGy(y1);
    const int gx2 = GetGx(x2);
    const int gy2 = GetGy(y2);
    return((gx1 == gx2) && (gy1 == gy2));
}
bool CGameMap::isInArea(int x1, int y1, int x2, int y2)
{
    bool check1 = false, check2 = false;
    const int nx1 = GetGx(x1);
    const int ny1 = GetGy(y1);
    const int nx2 = GetGx(x2);
    const int ny2 = GetGy(y2);
    const int nw = 1;
    const int nh = 1;
    if ((nx1 >= nx2) && (nx1 <= (nx2 + nw))) {
        check1 = true;
    }
    if ((ny1 >= ny2) && (ny1 <= (ny2 + nh))) {
        check2 = true;
    }
    return check1 && check2;
}

}


