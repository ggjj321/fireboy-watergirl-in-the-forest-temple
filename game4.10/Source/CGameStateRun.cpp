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
		bool sisterOnPurplePlatform = false;
		bool brotherOnPurplePlatform = false;

		for (int purpleBorder = 0; purpleBorder < 6; purpleBorder++) {
			for (int purpleBorderHeight = 1; purpleBorderHeight < 3; purpleBorderHeight++) {
				int purplePlatformX = purplePlatform.GetX() + 14 * purpleBorder;
				int purplePlatformY = purplePlatform.GetY() - 17 * purpleBorderHeight;

				if (map.isSameArray(purplePlatformX, purplePlatformY, sister.GetX(), sister.GetY())) {
					sisterOnPurplePlatform = true;
				}

				if (map.isSameArray(purplePlatformX, purplePlatformY, brother.GetX(), brother.GetY())) {
					brotherOnPurplePlatform = true;
				}
			}	
		}
		if (sisterOnPurplePlatform) {
			sister.SetY(purplePlatform.GetY() - 34);
		}
		if (brotherOnPurplePlatform) {
			brother.SetY(purplePlatform.GetY() - 34);
		}
		
		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);   
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, sisterOnPurplePlatform);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, brotherOnPurplePlatform);

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + 40);

		bool purpleDown = false;
		for (int puttonIndex = 0; puttonIndex < 2; puttonIndex++) {
			int buttonPx = map.GetGx(buttons[puttonIndex].GetX());
			int buttonPy = map.GetGy(buttons[puttonIndex].GetY());
			int sisterPx = map.GetGx(sister.GetX());
			int sisterPy = map.GetGy(sister.GetY());
			int brotherPx = map.GetGx(brother.GetX());
			int brotherPy = map.GetGy(brother.GetY());
			
			bool isBrotherDown = (buttonPx == brotherPx && buttonPy - 1 == brotherPy);
			bool isSisterDown = (buttonPx == sisterPx && buttonPy - 1 == sisterPy);
			bool isDown = isBrotherDown || isSisterDown;

			buttons[puttonIndex].OnMove(isDown);

			for (int platformIndex = 0; platformIndex < 1; platformIndex++) {
				if (purplePlatform.GetColor() == buttons[puttonIndex].GetColor()) {
					if (isDown) purpleDown = true;
				}
			}
		}
		purplePlatform.OnMove(purpleDown);
		if(sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if(brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);
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

		buttons[0].init(140, 230, 1);
		buttons[0].LoadBitmap();

		buttons[1].init(480, 165, 1);
		buttons[1].LoadBitmap();


		ShowInitProgress(50);

		purplePlatform.init(550, 180, 1);
		purplePlatform.LoadBitmap();

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
		purplePlatform.OnShow();
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