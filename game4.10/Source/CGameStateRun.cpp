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
		whiteButtons = new Button[2];
		greenButtons = new Button[2];

		redDiamonds = new RedDiamond[3];
		blueDiamonds = new BlueDiamond[4];

		redDiamondsTwo = new RedDiamond[8];
		blueDiamondsTwo = new BlueDiamond[8];

		chainPlatforms = new ChainPlatform[2];
	}

	CGameStateRun::~CGameStateRun()
	{
		delete [] buttons;
		delete [] whiteButtons;
		delete [] greenButtons;

		delete[] redDiamonds;
		delete[] blueDiamonds;

		delete[] redDiamondsTwo;
		delete[] blueDiamondsTwo;

		delete[] chainPlatforms;
	}

	void CGameStateRun::OnBeginState()
	{
		CGame::passGame = false;
		switch (map.mapLevel)
		{
		case 1:
			SetLevelOneState();
			break;
		case 2:
			SetLevelTwoState();
			break;
		default:
			break;
		}		
	}

	void CGameStateRun::OnMove()						
	{
		switch (map.mapLevel)
		{
		case 1:
			LevelOneMove();
			break;
		case 2:
			LevelTwoMove();
			break;
		default:
			break;
		}	
	}

	void CGameStateRun::OnInit()  								
	{
		switch (map.mapLevel)
		{
		case 1:
			SetLevelOneState();
			break;
		case 2:
			SetLevelTwoState();
			break;
		default:
			break;
		}

		ShowInitProgress(33);	

		map.LoadBitMap();

		sister.LoadBitmap();
		sister.AddingBitmap();		

		brother.LoadBitmap();
		brother.AddingBitmap();
				
		buttons[0].LoadBitmap(1);		
		buttons[1].LoadBitmap(1);

		whiteButtons[0].LoadBitmap(1);
		whiteButtons[1].LoadBitmap(1);

		greenButtons[0].LoadBitmap(1);
		greenButtons[1].LoadBitmap(1);

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

		for (int i = 0; i < 8; i++) {
			redDiamondsTwo[i].LoadBitmap();
		}

		for (int i = 0; i < 8; i++) {
			blueDiamondsTwo[i].LoadBitmap();
		}

		redDoor.LoadBitmap();

		blueDoor.LoadBitmap();

		stone.LoadBitmap();

		for(int i = 0; i < 2; i++) chainPlatforms[i].LoadBitmap();

		Sleep(300); 		
	}

	void CGameStateRun::OnShow()
	{
		switch (map.mapLevel)
		{
		case 1:
			LevelOneShow();
			break;
		case 2:
			LevelTwoShow();
			break;
		default:
			break;
		}		
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

	void CGameStateRun::SetLevelOneState()
	{
		sister.init(33, 345);
		brother.init(33, 400);
		buttons[0].init(128, 230);
		buttons[1].init(480, 165);
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
		redDoor.init(513, 43);
		blueDoor.init(571, 43);
		stone.init(340, 115); 
	}
	void CGameStateRun::LevelOneMove() {

		// stone and platform
		int sisterPlatformY = 0;
		int brotherPlatformY = 0;

		// stone move
		bool sisterOnStone = false;
		bool brotherOnStone = false;


		bool stoneLeftBound = map.isEmpty(stone.GetX(), stone.GetY() + 17);
		bool stoneRightBound = map.isEmpty(stone.GetX() + 10, stone.GetY() + 17);
		const bool stoneDownBound = map.isEmpty(stone.GetX() + 10, stone.GetY() + 37);

		stone.OnMove(stoneLeftBound, stoneRightBound, stoneDownBound,
			sister.GetX(), sister.GetY(), brother.GetX(), brother.GetY(), sister.GetWidth(), brother.GetWidth());

		bool stoneSisterLeftBound = !stoneLeftBound && stone.RightPush(sister.GetX(), sister.GetY());
		bool stoneBrotherLeftBound = !stoneLeftBound && stone.RightPush(brother.GetX(), brother.GetY());

		bool stoneSisterRightBound = !stoneRightBound && stone.LeftPush(sister.GetX(), sister.GetY(), sister.GetWidth());
		bool stoneBrotherRightBound = !stoneRightBound && stone.LeftPush(brother.GetX(), brother.GetY(), brother.GetWidth());


		for (int stoneBorder = 0; stoneBorder < 4; stoneBorder++) {
			for (int stoneBorderHeight = 1; stoneBorderHeight < 5; stoneBorderHeight++) {
				int stoneX = stone.GetX() + 3 * stoneBorder;
				int stoneY = stone.GetY() - 8 * stoneBorderHeight;

				if (map.isSameArray(stoneX, stoneY, sister.GetX(), sister.GetY())) {
					sisterOnStone = true;
				}

				if (map.isSameArray(stoneX, stoneY, brother.GetX(), brother.GetY())) {
					brotherOnStone = true;
				}
			}		
		}

		if (sisterOnStone) {
			sisterPlatformY = stone.GetY() - 35;
		}
		if (brotherOnStone) {
			brotherPlatformY = stone.GetY() - 35;
		}

		// purple platform move
		
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

		bool sisterOnPlatform = sisterOnPurplePlatform || sisterOnYellowPlatform || sisterOnStone;
		bool brotherOnPlatform = brotherOnPurplePlatform || brotherOnYellowPlatform || brotherOnStone;

		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17) && ! stoneSisterLeftBound;
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17) && !stoneSisterRightBound;
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX() + 5, sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, sisterOnPlatform, sisterPlatformY);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17) && !stoneBrotherLeftBound;
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17) && !stoneBrotherRightBound;
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX() + 10, brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, brotherOnPlatform, brotherPlatformY);

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 10, brother.GetY() + 40);

		bool purpleDown = false;
		for (int puttonIndex = 0; puttonIndex < 2; puttonIndex++) {
			int buttonPx = map.GetGx(buttons[puttonIndex].GetX());
			int buttonPy = map.GetGy(buttons[puttonIndex].GetY());
			int sisterPx = map.GetGx(sister.GetX());
			int sisterPy = map.GetGy(sister.GetY());
			int brotherPx = map.GetGx(brother.GetX());
			int brotherPy = map.GetGy(brother.GetY());
			bool isBrotherDown = ((buttonPx <= brotherPx && brotherPx <= buttonPx + 2) && buttonPy - 1 == brotherPy);
			bool isSisterDown = ((buttonPx <= sisterPx && sisterPx <= buttonPx + 2) && buttonPy - 1 == sisterPy);
			// bool isBrotherDown = map.isInArea(brother.GetX(), brother.GetY(), buttons[puttonIndex].GetX(), buttons[puttonIndex].GetY() - 1);
			// bool isSisterDown = map.isInArea(sister.GetX(), sister.GetY(), buttons[puttonIndex].GetX(), buttons[puttonIndex].GetY() - 1);
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
		if (sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if (brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		timer.OnMove();
		timer.TimeCalculate();

		for (int i = 0; i < 3; i++) {
			if (map.isInArea(brother.GetX(), brother.GetY(), redDiamonds[i].GetX(), redDiamonds[i].GetY())) {
				redDiamonds[i].Touch();
			}
		}
		for (int i = 0; i < 4; i++) {
			if (map.isInArea(sister.GetX(), sister.GetY(), blueDiamonds[i].GetX(), blueDiamonds[i].GetY())) {
				blueDiamonds[i].Touch();
			}
		}

		if (map.isInArea(sister.GetX(), sister.GetY(), blueDoor.GetX(), blueDoor.GetY())) {
			blueDoor.Touch();
		}
		if (map.isInArea(brother.GetX(), brother.GetY(), redDoor.GetX(), redDoor.GetY())) {
			redDoor.Touch();
		}

		if (redDoor.GetTouch() == true && blueDoor.GetTouch() == true) {
			map.NextLevel();
			CGame::passGame = true;
			GotoGameState(GAME_STATE_OVER);
		}
	}
	void CGameStateRun::LevelOneShow() {
		map.OnShow();

		blueDoor.OnShow();
		redDoor.OnShow();

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
		stone.OnShow();
	}
	void CGameStateRun::SetLevelTwoState() {
		sister.init(50, 400);   // 50 400
		brother.init(15, 400);  // 15 400
		redDoor.init(20, 30);
		blueDoor.init(80, 30);
		redDiamondsTwo[0].init(130, 430);
		redDiamondsTwo[1].init(180, 430);
		redDiamondsTwo[2].init(400, 380);
		redDiamondsTwo[3].init(450, 380);
		redDiamondsTwo[4].init(450, 300);
		redDiamondsTwo[5].init(220, 300);
		redDiamondsTwo[6].init(290, 190);
		redDiamondsTwo[7].init(280, 40);
		blueDiamondsTwo[0].init(130, 380);
		blueDiamondsTwo[1].init(180, 380);
		blueDiamondsTwo[2].init(400, 430);
		blueDiamondsTwo[3].init(450, 430);
		blueDiamondsTwo[4].init(400, 300);
		blueDiamondsTwo[5].init(140, 300);
		blueDiamondsTwo[6].init(320, 190);
		blueDiamondsTwo[7].init(340, 40);
		whiteButtons[0].init(60, 315);
		whiteButtons[1].init(480, 315);
		greenButtons[0].init(120, 70);
		greenButtons[1].init(460, 70);
		timer.init(280, 0);
		chainPlatforms[0].init(160, 218);
		chainPlatforms[1].init(400, 218);
	}
	void CGameStateRun::LevelTwoShow() {
		map.OnShow();

		blueDoor.OnShow();
		redDoor.OnShow();
		
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
		
		for (int i = 0; i < 8; i++) {
			redDiamondsTwo[i].OnShow();
		}
		
		for (int i = 0; i < 8; i++) {
			blueDiamondsTwo[i].OnShow();
		}
		
		for (int i = 0; i < 2; i++) {
			whiteButtons[i].OnShow();
			greenButtons[i].OnShow();
		}

		for (int i = 0; i < 2; i++) chainPlatforms[i].OnShow();
	}
	void CGameStateRun::LevelTwoMove() {
		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, false, 0);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, false, 0);

		timer.OnMove();
		timer.TimeCalculate();

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + 40);

		if (sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if (brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		for (int i = 0; i < 8; i++) {
			if (map.isSameArray(brother.GetX() + 10, brother.GetY(), redDiamondsTwo[i].GetX() + 5, redDiamondsTwo[i].GetY() - 5)) {
				redDiamondsTwo[i].Touch();
			}
		}
		for (int i = 0; i < 8; i++) {
			if (map.isSameArray(sister.GetX() + 10, sister.GetY(), blueDiamondsTwo[i].GetX() + 5, blueDiamondsTwo[i].GetY() - 5)) {
				blueDiamondsTwo[i].Touch();
			}
		}

		for (int puttonIndex = 0; puttonIndex < 2; puttonIndex++) {
			int buttonPx = map.GetGx(whiteButtons[puttonIndex].GetX());
			int buttonPy = map.GetGy(whiteButtons[puttonIndex].GetY());
			int sisterPx = map.GetGx(sister.GetX());
			int sisterPy = map.GetGy(sister.GetY() + 5);
			int brotherPx = map.GetGx(brother.GetX());
			int brotherPy = map.GetGy(brother.GetY() + 5);

			bool isBrotherDown = (buttonPx == brotherPx && buttonPy - 1 == brotherPy);
			bool isSisterDown = (buttonPx == sisterPx && buttonPy - 1 == sisterPy);
			bool isDown = isBrotherDown || isSisterDown;

			whiteButtons[puttonIndex].OnMove(isDown);
		}
	}
}