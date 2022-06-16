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

		redDiamondsThree = new RedDiamond[8];
		blueDiamondsThree = new BlueDiamond[8];

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

		delete[] redDiamondsThree;
		delete[] blueDiamondsThree;

		delete[] chainPlatforms;
	}

	void CGameStateRun::OnBeginState()
	{
		secretNum = 0;
		map.ReadMapData();
		CGame::passGame = false;
		switch (CGameMap::mapLevel)
		{
		case 1:
			SetLevelOneState();
			break;
		case 2:
			SetLevelTwoState();
			break;
		case 3:
			SetLevelThreeState();
			break;
		case 4:
			SetLevelFourState();
			break;
		default:
			break;
		}		
	}

	void CGameStateRun::OnMove()						
	{
		switch (CGameMap::mapLevel)
		{
		case 1:
			LevelOneMove();
			break;
		case 2:
			LevelTwoMove();
			break;
		case 3:
			LevelThreeMove();
			break;
		case 4:
			LevelFourMove();
			break;
		default:
			break;
		}	
	}

	void CGameStateRun::OnInit()  	
	{
		secretNum = 0;
		map.ReadMapData();
		switch (CGameMap::mapLevel)
		{
		case 1:
			SetLevelOneState();
			break;
		case 2:
			SetLevelTwoState();
			break;
		case 3:
			SetLevelThreeState();
			break;
		case 4:
			SetLevelFourState();
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
		buttonsFour.LoadBitmap(1);

		whiteButtons[0].LoadBitmap(2);
		whiteButtons[1].LoadBitmap(2);

		greenButtons[0].LoadBitmap(3);
		greenButtons[1].LoadBitmap(3);

		greenButtonsFour.LoadBitmap(3);

		ShowInitProgress(50);
		
		purplePlatform.LoadBitmap(1);
		
		yellowPlatform.LoadBitmap(2);

		greyPlatform.LoadBitmap(1);

		greenPlatform.LoadBitmap(2);

		level4Grey.LoadBitmap(3);

		level4Green.LoadBitmap(4);

		level4Purple.LoadBitmap(5);

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

		for (int i = 0; i < 8; i++) {
			redDiamondsThree[i].LoadBitmap();
		}

		for (int i = 0; i < 8; i++) {
			blueDiamondsThree[i].LoadBitmap();
		}

		whiteDiamonds.LoadBitmap();

		redDoor.LoadBitmap();

		blueDoor.LoadBitmap();

		stone.LoadBitmap();

		for(int i = 0; i < 2; i++) chainPlatforms[i].LoadBitmap();

		Sleep(300); 		
	}

	void CGameStateRun::OnShow()
	{
		switch (CGameMap::mapLevel)
		{
		case 1:
			LevelOneShow();
			break;
		case 2:
			LevelTwoShow();
			break;
		case 3:
			LevelThreeShow();
			break;
		case 4:
			LevelFourShow();
			break;
		default:
			break;
		}	

		if (secretNum == 1) SecretTechText("c");
		if (secretNum == 2) SecretTechText("co");
		if (secretNum == 3) SecretTechText("con");
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

		const char SECRET_C = 0x43;
		const char SECRET_O = 0x4F;
		const char SECRET_N = 0x4E;
		const char SECRET_G = 0x47;

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

		if (nChar == SECRET_C && secretNum == 0)
			secretNum += 1;
		if (nChar == SECRET_O && secretNum == 1)
			secretNum += 1;
		if (nChar == SECRET_N && secretNum == 2)
			secretNum += 1;
		if (nChar == SECRET_G && secretNum == 3) {
			CGame::passGame = true;
			GotoGameState(GAME_STATE_OVER);
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

	void CGameStateRun::SecretTechText(char* text)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, * fp;
		f.CreatePointFont(230, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, text);
		pDC->TextOut(0, 0, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	void CGameStateRun::SetLevelOneState()
	{
		sister.init(33, 345);
		brother.init(33, 400);
		buttons[0].init(128, 230);
		buttons[1].init(480, 165);
		purplePlatform.init(555, 180);
		yellowPlatform.init(13, 245);
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
		const bool sisterRightBound = map.isEmpty(sister.GetX() + sister.GetWidth(), sister.GetY() + 17) && !stoneSisterRightBound;
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX() + 5, sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, sisterOnPlatform, sisterPlatformY);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17) && !stoneBrotherLeftBound;
		const bool brotherRightBound = map.isEmpty(brother.GetX() + brother.GetWidth(), brother.GetY() + 17) && !stoneBrotherRightBound;
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
		redDiamondsTwo[4].init(450, 290);
		redDiamondsTwo[5].init(220, 290);
		redDiamondsTwo[6].init(290, 190);
		redDiamondsTwo[7].init(280, 40);
		blueDiamondsTwo[0].init(130, 380);
		blueDiamondsTwo[1].init(180, 380);
		blueDiamondsTwo[2].init(400, 430);
		blueDiamondsTwo[3].init(450, 430);
		blueDiamondsTwo[4].init(400, 290);
		blueDiamondsTwo[5].init(140, 290);
		blueDiamondsTwo[6].init(325, 190);
		blueDiamondsTwo[7].init(340, 40);
		whiteButtons[0].init(75, 314);
		whiteButtons[1].init(495, 314);
		greenButtons[0].init(135, 66);
		greenButtons[1].init(460, 66);
		greyPlatform.init(320, 264);
		greenPlatform.init(367, 82);
		timer.init(280, 0);
		chainPlatforms[0].init(160, 218);
		chainPlatforms[1].init(400, 218);
	}
	void CGameStateRun::LevelTwoShow() {
		map.OnShow();

		greyPlatform.OnShow();
		greenPlatform.OnShow();

		blueDoor.OnShow();
		redDoor.OnShow();
		
		for (int i = 0; i < 2; i++) {
			whiteButtons[i].OnShow();
			greenButtons[i].OnShow();
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
		int greyPlatformTop = greyPlatform.GetFocusY() - 68;
		for(int i = 0 ; i < 4; i++) {
			map.ChangeArray(greyPlatform.GetX() + 8, (greyPlatform.GetY() + 5) + 17 * i, 1);
			if (greyPlatform.GetY() + 70 <= greyPlatform.GetFocusY() + 17 * i) {
				map.ChangeArray(greyPlatform.GetX() + 8, greyPlatform.GetFocusY() + 17 * i, 0);
			}
			if (greyPlatform.GetY() > greyPlatformTop + 17 * i) {
				map.ChangeArray(greyPlatform.GetX() + 8, greyPlatformTop + 17 * i, 0);
			}
		}
		int sisterPlatformY = 0;
		int brotherPlatformY = 0;

		bool sisterOnGreenPlatform = false;
		bool brotherOnGreenPlatform = false;

		for (int greenBorder = 0; greenBorder < 6; greenBorder++) {
			for (int greenBorderHeight = 1; greenBorderHeight < 3; greenBorderHeight++) {
				int greenPlatformX = greenPlatform.GetX() + 17 * greenBorder;
				int greenPlatformY = greenPlatform.GetY() - 17 * greenBorderHeight;

				if (map.isSameArray(greenPlatformX, greenPlatformY, sister.GetX(), sister.GetY())) {
					sisterOnGreenPlatform = true;
				}

				if (map.isSameArray(greenPlatformX, greenPlatformY, brother.GetX(), brother.GetY())) {
					brotherOnGreenPlatform = true;
				}
			}
		}
		if (sisterOnGreenPlatform) {
			sisterPlatformY = greenPlatform.GetY() - 34;
		}
		if (brotherOnGreenPlatform) {
			brotherPlatformY = greenPlatform.GetY() - 34;
		}
		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);
		const bool sisterRightBound = map.isEmpty(sister.GetX() + sister.GetWidth(), sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + (int)(sister.GetHeight()*1.2));
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, sisterOnGreenPlatform, sisterPlatformY);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + brother.GetWidth(), brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + (int)(brother.GetHeight() * 1.2));
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, brotherOnGreenPlatform, brotherPlatformY);

		timer.OnMove();
		timer.TimeCalculate();

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + sister.GetHeight());
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + sister.GetHeight());

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + brother.GetHeight());
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + brother.GetHeight());

		if (sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if (brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		for (int i = 0; i < 8; i++) {
			if (map.isInArea(brother.GetX(), brother.GetY(), redDiamondsTwo[i].GetX(), redDiamondsTwo[i].GetY())) {
				redDiamondsTwo[i].Touch();
			}
		}
		for (int i = 0; i < 8; i++) {
			if (map.isInArea(sister.GetX(), sister.GetY(), blueDiamondsTwo[i].GetX(), blueDiamondsTwo[i].GetY())) {
				blueDiamondsTwo[i].Touch();
			}
		}

		bool greyDown = false;
		for (int puttonIndex = 0; puttonIndex < 2; puttonIndex++) {
			int buttonPx = map.GetGx(whiteButtons[puttonIndex].GetX());
			int buttonPy = map.GetGy(whiteButtons[puttonIndex].GetY());
			int sisterPx = map.GetGx(sister.GetX());
			int sisterPy = map.GetGy(sister.GetY());
			int brotherPx = map.GetGx(brother.GetX());
			int brotherPy = map.GetGy(brother.GetY());

			bool isBrotherDown = ((buttonPx - 1 <= brotherPx && brotherPx <= buttonPx + 1) && buttonPy - 1 == brotherPy);
			bool isSisterDown = ((buttonPx - 1 <= sisterPx && sisterPx <= buttonPx + 1) && buttonPy - 1 == sisterPy);
			bool isDown = isBrotherDown || isSisterDown;

			whiteButtons[puttonIndex].OnMove(isDown);

			if (isDown) greyDown = true;
		}
		greyPlatform.OnMove(greyDown);

		bool greenDown = false;
		for (int puttonIndex = 0; puttonIndex < 2; puttonIndex++) {
			int buttonPx = map.GetGx(greenButtons[puttonIndex].GetX());
			int buttonPy = map.GetGy(greenButtons[puttonIndex].GetY());
			int sisterPx = map.GetGx(sister.GetX());
			int sisterPy = map.GetGy(sister.GetY());
			int brotherPx = map.GetGx(brother.GetX());
			int brotherPy = map.GetGy(brother.GetY());

			bool isBrotherDown = ((buttonPx - 1 <= brotherPx && brotherPx <= buttonPx + 1) && buttonPy - 1 == brotherPy);
			bool isSisterDown = ((buttonPx - 1 <= sisterPx && sisterPx <= buttonPx + 1) && buttonPy - 1 == sisterPy);
			bool isDown = isBrotherDown || isSisterDown;

			greenButtons[puttonIndex].OnMove(isDown);

			if (isDown) greenDown = true;
		}
		greenPlatform.GrenOnMove(greenDown, 87);

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

	void CGameStateRun::SetLevelThreeState() {
		sister.init(30, 200);   // 50 400
		brother.init(580, 40);  // 15 400
		redDoor.init(510, 195);
		blueDoor.init(65, 410);
		redDiamondsThree[0].init(420, 80);
		redDiamondsThree[1].init(320, 80);
		redDiamondsThree[2].init(220, 80);
		redDiamondsThree[3].init(150, 40);
		redDiamondsThree[4].init(55, 85);
		redDiamondsThree[5].init(40, 160);
		redDiamondsThree[6].init(385, 145);
		redDiamondsThree[7].init(285, 145);
		blueDiamondsThree[0].init(190, 280);
		blueDiamondsThree[1].init(290, 280);
		blueDiamondsThree[2].init(380, 275);
		blueDiamondsThree[3].init(440, 230);
		blueDiamondsThree[4].init(530, 290);
		blueDiamondsThree[5].init(540, 360);
		blueDiamondsThree[6].init(355, 345);
		blueDiamondsThree[7].init(220, 345);
		timer.init(280, 0);
	}

	void CGameStateRun::LevelThreeShow() {
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
			redDiamondsThree[i].OnShow();
		}

		for (int i = 0; i < 8; i++) {
			blueDiamondsThree[i].OnShow();
		}
	}

	void CGameStateRun::LevelThreeMove() {
		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, false, false);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, false, false);

		timer.OnMove();
		timer.TimeCalculate();

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + 40);

		if (sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if (brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		for (int i = 0; i < 8; i++) {
			if (map.isInArea(brother.GetX(), brother.GetY(), redDiamondsThree[i].GetX(), redDiamondsThree[i].GetY())) {
				redDiamondsThree[i].Touch();
			}
		}
		for (int i = 0; i < 8; i++) {
			if (map.isInArea(sister.GetX(), sister.GetY(), blueDiamondsThree[i].GetX(), blueDiamondsThree[i].GetY())) {
				blueDiamondsThree[i].Touch();
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

	void CGameStateRun::SetLevelFourState()
	{
		sister.init(120, 20); // 120 20
		brother.init(80, 20);
		rocker.init(320, 180);
		buttonsFour.init(84, 264);
		greenButtonsFour.init(265, 445);
		level4Grey.init(561, 347);
		level4Green.init(315, 245);
		level4Purple.init(263, 415);
		timer.init(280, 0);
		whiteDiamonds.init(210, 430);
		redDoor.init(528, 213);
		blueDoor.init(578, 410);
	}
	void CGameStateRun::LevelFourMove() {
		int greenPlatformTop = level4Green.GetFocusY() - 52;
		for (int i = 0; i < 3; i++) {
			map.ChangeArray(level4Green.GetX() + 8, (level4Green.GetY() + 5) + 17 * i, 1);
			if (level4Green.GetY() + 52 <= level4Green.GetFocusY() + 17 * i) {
				map.ChangeArray(level4Green.GetX() + 8, level4Green.GetFocusY() + 17 * i, 0);
			}
			if (level4Green.GetY() > greenPlatformTop + 17 * i) {
				map.ChangeArray(level4Green.GetX() + 8, greenPlatformTop + 17 * i, 0);
			}
		}

		int purplePlatformLeft = level4Purple.GetFocusX() - 52;
		for (int i = 0; i < 3; i++) {
			map.ChangeArray(level4Purple.GetX() + 17 * i, level4Purple.GetY() + 7, 1);
			if (level4Purple.GetX() + 52 <= level4Purple.GetFocusX() + 17 * i) {
				map.ChangeArray(level4Purple.GetX() + 17 * i, level4Purple.GetY() + 7, 0);
			}
			if (level4Purple.GetX() > purplePlatformLeft + 17 * i) {
				map.ChangeArray(purplePlatformLeft + 17 * i, level4Purple.GetY() + 7, 0);
			}
		}

		int greyPlatformTop = level4Grey.GetFocusY() + (2 * 52);
		for (int i = 0; i < 3; i++) {
			map.ChangeArray(level4Grey.GetX() + 8, level4Grey.GetY() + 17 * i, 1);
			if (level4Grey.GetFocusY() + 52 >= level4Grey.GetY() + 17 * i) {
				map.ChangeArray(level4Grey.GetX() + 8, level4Grey.GetY() - 17 * i, 0);
			}
		}

		const bool sisterLeftBound = map.isEmpty(sister.GetX() - 1, sister.GetY() + 17);
		const bool sisterRightBound = map.isEmpty(sister.GetX() + 10, sister.GetY() + 17);
		const bool sisterDownBound = map.isEmpty(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterUpBound = map.isEmpty(sister.GetX(), sister.GetY());
		sister.OnMove(sisterLeftBound, sisterRightBound, sisterDownBound, sisterUpBound, false, false);

		const bool brotherLeftBound = map.isEmpty(brother.GetX() - 1, brother.GetY() + 17);
		const bool brotherRightBound = map.isEmpty(brother.GetX() + 10, brother.GetY() + 17);
		const bool brotherDownBound = map.isEmpty(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherUpBound = map.isEmpty(brother.GetX(), brother.GetY());
		brother.OnMove(brotherLeftBound, brotherRightBound, brotherDownBound, brotherUpBound, false, false);

		if (map.isSameArray(brother.GetX(), brother.GetY(), rocker.GetX() + 15, rocker.GetY() + 15)) rocker.Touch();
		if (map.isSameArray(sister.GetX(), sister.GetY(), rocker.GetX() + 15, rocker.GetY() + 15)) rocker.Touch();

		level4Grey.level4DownMove(rocker.GetIsTouch());

		timer.OnMove();
		timer.TimeCalculate();

		const bool sisterTouchRedWater = map.isRedWater(sister.GetX() + 5, sister.GetY() + 40);
		const bool sisterTouchGreenWater = map.isGreenWater(sister.GetX() + 5, sister.GetY() + 40);

		const bool brotherTouchBlueWater = map.isBlueWater(brother.GetX() + 5, brother.GetY() + 40);
		const bool brotherTouchGreenWater = map.isGreenWater(brother.GetX() + 5, brother.GetY() + 40);

		if (sisterTouchRedWater || sisterTouchGreenWater) GotoGameState(GAME_STATE_OVER);
		if (brotherTouchBlueWater || brotherTouchGreenWater) GotoGameState(GAME_STATE_OVER);

		if (map.isInArea(sister.GetX(), sister.GetY(), whiteDiamonds.GetX(), whiteDiamonds.GetY())) {
			whiteDiamonds.Touch();
		}

		if (map.isInArea(brother.GetX(), brother.GetY(), whiteDiamonds.GetX(), whiteDiamonds.GetY())) {
			whiteDiamonds.Touch();
		}

		bool greenDown = false;
		int buttonPx = map.GetGx(greenButtonsFour.GetX());
		int buttonPy = map.GetGy(greenButtonsFour.GetY());
		int sisterPx = map.GetGx(sister.GetX());
		int sisterPy = map.GetGy(sister.GetY());
		int brotherPx = map.GetGx(brother.GetX());
		int brotherPy = map.GetGy(brother.GetY());

		bool isBrotherDown = ((buttonPx - 1 <= brotherPx && brotherPx <= buttonPx + 1) && buttonPy - 1 == brotherPy);
		bool isSisterDown = ((buttonPx - 1 <= sisterPx && sisterPx <= buttonPx + 1) && buttonPy - 1 == sisterPy);
		bool isDown = isBrotherDown || isSisterDown;

		greenButtonsFour.OnMove(isDown);

		if (isDown) greenDown = true;
	
		level4Green.level4OnMove(greenDown);

		bool purpleDown = false;
		int buttonPurplePx = map.GetGx(buttonsFour.GetX());
		int buttonPurplePy = map.GetGy(buttonsFour.GetY());

		bool isBrotherPurpleDown = ((buttonPurplePx - 1 <= brotherPx && brotherPx <= buttonPurplePx + 1) && buttonPurplePy - 1 == brotherPy);
		bool isSisterPurpleDown = ((buttonPurplePx - 1 <= sisterPx && sisterPx <= buttonPurplePx + 1) && buttonPurplePy - 1 == sisterPy);
		bool isPurpleDown = isBrotherPurpleDown || isSisterPurpleDown;

		buttonsFour.OnMove(isPurpleDown);

		if (isPurpleDown) purpleDown = true;
		
		level4Purple.GrenOnMove(purpleDown, 52);

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
	void CGameStateRun::LevelFourShow() {
		map.OnShow();

		blueDoor.OnShow();
		redDoor.OnShow();

		rocker.OnShow();

		buttonsFour.OnShow();

		greenButtonsFour.OnShow();

		level4Grey.OnShow();

		level4Green.OnShow();

		level4Purple.OnShow();

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

		whiteDiamonds.OnShow();
	}
}