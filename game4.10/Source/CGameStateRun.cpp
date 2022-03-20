#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameStateRun.h"

namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
	}

	CGameStateRun::~CGameStateRun()
	{
	}

	void CGameStateRun::OnBeginState()
	{
	}

	void CGameStateRun::OnMove()						// 移動遊戲元素
	{
		const bool leftBound = map.isEmpty(sister.GetX() - 1, sister.GetY());   // 判斷左邊陣列是否為0
		const bool rightBound = map.isEmpty(sister.GetX() + 10, sister.GetY()); // 判斷右邊陣列是否為0
		const bool downBound = map.isEmpty(sister.GetX(), sister.GetY() + 17 * 4);  // 判斷下方陣列是否為0
		sister.OnMove(leftBound, rightBound, downBound);
	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		//
		// 開始載入資料
		//
		map.LoadBitMap();
		sister.LoadBitmap();
		//
		// 完成部分Loading動作，提高進度
		//
		ShowInitProgress(50);
		Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep							

		//
		// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
		//
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(true);
		if (nChar == KEY_UP) {
			if (sister.isSetJumping == false) {
				sister.SetJumpimg(true);
				sister.jumpinVelocity = 13; // 設定跳躍初速
				sister.isSetJumping = true; // 已經跳躍過
			}
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(false);
		if (nChar == KEY_UP) {
			sister.SetJumpimg(false);
			sister.isSetJumping = false;
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{

	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{

	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{

	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{

	}

	void CGameStateRun::OnShow()
	{
		map.OnShow(); // 顯示地圖
		if (sister.GetIsMovingRight() == false && sister.GetIsMovingLeft() == false)
		{
			sister.OnShow();
		}
		else if (sister.GetIsMovingRight() == true)
		{
			sister.OnMoveAniRight();
		}
		else if (sister.GetIsMovingLeft() == true) {
			sister.OnMoveAniLeft();
		}
	}
}