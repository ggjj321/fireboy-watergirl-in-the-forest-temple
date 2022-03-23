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

	void CGameStateRun::OnMove()						
	{
		const bool leftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);   
		const bool rightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17); 
		const bool downBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 60);
		const bool upBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(leftBound, rightBound, downBound, upBound);
	}

	void CGameStateRun::OnInit()  								
	{
		ShowInitProgress(33);	
		map.LoadBitMap();
		sister.LoadBitmap();
		sister.AddingBitmap();
		
		ShowInitProgress(50);
		Sleep(300); 
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; 
		const char KEY_UP = 0x26;
		const char KEY_RIGHT = 0x27; 
		const char KEY_DOWN = 0x28; 
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(true);
		if (nChar == KEY_UP) {
			sister.SetJumpimg(true);
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;
		const char KEY_UP = 0x26; 
		const char KEY_RIGHT = 0x27; 
		const char KEY_DOWN = 0x28; 
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(false);
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  
	{

	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	
	{

	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  
	{

	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	
	{

	}

	void CGameStateRun::OnShow()
	{
		map.OnShow(); 
		if (sister.GetIsMovingRight() == false && sister.GetIsMovingLeft() == false)
		{
			sister.OnShow();
		}
		else if(sister.GetIsMovingRight() == true)
		{
			sister.OnMoveAniRight();
		}
		else if (sister.GetIsMovingLeft() == true) {
			sister.OnMoveAniLeft();
		}
		
	}
}