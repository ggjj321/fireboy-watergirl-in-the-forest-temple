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
		buttons = new Button[2];
	}

	CGameStateRun::~CGameStateRun()
	{
		delete [] buttons;
	}

	void CGameStateRun::OnBeginState()
	{
		sister.init();
		brother.init();
	}

	void CGameStateRun::OnMove()						
	{
		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);   
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound);

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + 40);

		if(sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if(brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		for (int i = 0; i < 2; i++) {
			if ((brother.GetY() < buttons[i].GetY()) && (abs(brother.GetX() - buttons[i].GetX()) < 10)) {
				buttons[i].SetDown(abs(brother.GetX() - buttons[i].GetX()));
			}
			if ((sister.GetY() < buttons[i].GetY()) && (abs(sister.GetX() - buttons[i].GetX()) < 10)) {
				buttons[i].SetDown(abs(sister.GetX() - buttons[i].GetX()));
			}
		}
	}

	void CGameStateRun::OnInit()  								
	{
		ShowInitProgress(33);	

		map.LoadBitMap();

		sister.LoadBitmap();
		sister.AddingBitmap();
		sister.init();

		brother.LoadBitmap();
		brother.AddingBitmap();
		brother.init();

		buttons[0].init(75, 200, 1);
		buttons[0].LoadBitmap();

		buttons[1].init(430, 130, 1);
		buttons[1].LoadBitmap();


		ShowInitProgress(50);

		Sleep(300); 
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char SISTER_KEY_LEFT = 0x25; 
		const char SISTER_KEY_UP = 0x26;
		const char SISTER_KEY_RIGHT = 0x27;
		const char SISTER_KEY_DOWN = 0x28;

		const char BROTHER_KEY_LEFT = 0x41;
		const char BROTHER_KEY_UP = 0x57;
		const char BROTHER_KEY_RIGHT = 0x44;
		const char BROTHER_KEY_DOWN = 0x53;

		if (nChar == SISTER_KEY_LEFT)
			sister.SetMovingLeft(true);
		if (nChar == SISTER_KEY_RIGHT)
			sister.SetMovingRight(true);
		if (nChar == SISTER_KEY_UP) {
			sister.SetJumpimg(true);
		}

		if (nChar == BROTHER_KEY_LEFT)
			brother.SetMovingLeft(true);
		if (nChar == BROTHER_KEY_RIGHT)
			brother.SetMovingRight(true);
		if (nChar == BROTHER_KEY_UP) {
			brother.SetJumpimg(true);
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char SISTER_KEY_LEFT = 0x25;
		const char SISTER_KEY_UP = 0x26;
		const char SISTER_KEY_RIGHT = 0x27;
		const char SISTER_KEY_DOWN = 0x28;

		const char BROTHER_KEY_LEFT = 0x41;
		const char BROTHER_KEY_UP = 0x57;
		const char BROTHER_KEY_RIGHT = 0x44;
		const char BROTHER_KEY_DOWN = 0x53;

		if (nChar == SISTER_KEY_LEFT)
			sister.SetMovingLeft(false);
		if (nChar == SISTER_KEY_RIGHT)
			sister.SetMovingRight(false);

		if (nChar == BROTHER_KEY_LEFT)
			brother.SetMovingLeft(false);
		if (nChar == BROTHER_KEY_RIGHT)
			brother.SetMovingRight(false);
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
		for (int i = 0; i < 2; i++) {
			buttons[i].OnShow();
		}
		
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

		if (brother.GetIsMovingRight() == false && brother.GetIsMovingLeft() == false)
		{
			brother.OnShow();
		}
		else if (brother.GetIsMovingRight() == true)
		{
			brother.OnMoveAniRight();
		}
		else if (brother.GetIsMovingLeft() == true) {
			brother.OnMoveAniLeft();
		}
	}
}