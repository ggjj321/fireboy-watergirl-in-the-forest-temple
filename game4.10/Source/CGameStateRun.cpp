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
		redDiamonds = new RedDiamond[3];
		blueDiamonds = new BlueDiamond[4];
	}

	CGameStateRun::~CGameStateRun()
	{
		delete [] buttons;
		delete[] redDiamonds;
		delete[] blueDiamonds;
	}

	void CGameStateRun::OnBeginState()
	{
		setLevelOneState();
	}

	void CGameStateRun::OnMove()						
	{
		// purple platform move
		int sisterPlatformY = 0;
		int brotherPlatformY = 0;

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
			sisterPlatformY = purplePlatform.GetY() - 34;
		}
		if (brotherOnPurplePlatform) {
			brotherPlatformY = purplePlatform.GetY() - 34;
		}
		//

		// yellow platform move
		bool sisterOnYellowPlatform = false;
		bool brotherOnYellowPlatform = false;

		for (int yellowBorder = 0; yellowBorder < 6; yellowBorder++) {
			for (int yellowBorderHeight = 0; yellowBorderHeight < 3; yellowBorderHeight++) {
				int yellowPlatformX = yellowPlatform.GetX() + 10 * yellowBorder;
				int yellowPlatformY = yellowPlatform.GetY() - 17 * yellowBorderHeight;

				if (map.isSameArray(yellowPlatformX, yellowPlatformY, sister.GetX(), sister.GetY())) {
					sisterOnYellowPlatform = true;
				}

				if (map.isSameArray(yellowPlatformX, yellowPlatformY, brother.GetX(), brother.GetY())) {
					brotherOnYellowPlatform = true;
				}
			}	
		}
		if (sisterOnYellowPlatform) {
			sisterPlatformY = yellowPlatform.GetY() - 34;
		}
		if (brotherOnYellowPlatform) {
			brotherPlatformY = yellowPlatform.GetY() - 34;
		}
		//

		bool sisterOnPlatform = sisterOnPurplePlatform || sisterOnYellowPlatform;
		bool brotherOnPlatform = brotherOnPurplePlatform || brotherOnYellowPlatform;

		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);   
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, sisterOnPlatform, sisterPlatformY);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, brotherOnPlatform, brotherPlatformY);

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

		if (map.isSameArray(brother.GetX(), brother.GetY(), rocker.GetX() + 15, rocker.GetY() + 15)) rocker.Touch();
		if (map.isSameArray(sister.GetX(), sister.GetY(), rocker.GetX() + 15, rocker.GetY() + 15)) rocker.Touch();

		yellowPlatform.OnMove(rocker.GetIsTouch());
		if(sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if(brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		timer.OnMove();
		timer.TimeCalculate();

		for (int i = 0; i < 3; i++) {
			if (map.isSameArray(brother.GetX() + 10, brother.GetY(), redDiamonds[i].GetX() + 5, redDiamonds[i].GetY() - 5)) {
				redDiamonds[i].Touch();
			}
		}
		for (int i = 0; i < 4; i++) {
			if (map.isSameArray(sister.GetX() + 10, sister.GetY(), blueDiamonds[i].GetX() + 5, blueDiamonds[i].GetY() - 5)) {
				blueDiamonds[i].Touch();
			}
		}
	}

	void CGameStateRun::OnInit()  								
	{
		setLevelOneState();
		ShowInitProgress(33);	

		map.LoadBitMap();

		sister.LoadBitmap();
		sister.AddingBitmap();		

		brother.LoadBitmap();
		brother.AddingBitmap();
				
		buttons[0].LoadBitmap();		
		buttons[1].LoadBitmap();

		ShowInitProgress(50);
		
		purplePlatform.LoadBitmap();
		
		yellowPlatform.LoadBitmap();

		rocker.LoadBitmap();

		for (int i = 0; i < 3; i++) {
			redDiamonds[i].LoadBitmap();
		}

		for (int i = 0; i < 4; i++) {
			blueDiamonds[i].LoadBitmap();
		}

		Sleep(300); 
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char SISTER_KEY_LEFT = 0x41;
		const char SISTER_KEY_UP = 0x57;
		const char SISTER_KEY_RIGHT = 0x44;
		const char SISTER_KEY_DOWN = 0x53;

		const char BROTHER_KEY_LEFT = 0x25;
		const char BROTHER_KEY_UP = 0x26;
		const char BROTHER_KEY_RIGHT = 0x27;
		const char BROTHER_KEY_DOWN = 0x28;

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
		const char SISTER_KEY_LEFT = 0x41;
		const char SISTER_KEY_UP = 0x57;
		const char SISTER_KEY_RIGHT = 0x44;
		const char SISTER_KEY_DOWN = 0x53;

		const char BROTHER_KEY_LEFT = 0x25;
		const char BROTHER_KEY_UP = 0x26;
		const char BROTHER_KEY_RIGHT = 0x27;
		const char BROTHER_KEY_DOWN = 0x28;

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
		yellowPlatform.OnShow();
		rocker.OnShow();

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

		timer.OnShow();

		for (int i = 0; i < 3; i++) {
			redDiamonds[i].OnShow();
		}

		for (int i = 0; i < 4; i++) {
			blueDiamonds[i].OnShow();
		}
	}
	void CGameStateRun::setLevelOneState()
	{
		sister.init();
		brother.init();
		buttons[0].init(140, 230, 1);
		buttons[1].init(480, 165, 1);
		purplePlatform.init(555, 180, 1);
		yellowPlatform.init(13, 245, 2);
		rocker.init(120, 280);
		timer.init(280, 0);
		redDiamonds[0].init(170, 30);
		redDiamonds[1].init(95, 210);
		redDiamonds[2].init(316, 420);
		blueDiamonds[0].init(370, 55);
		blueDiamonds[1].init(20, 75);
		blueDiamonds[2].init(380, 225);
		blueDiamonds[3].init(445, 420);
	}
}