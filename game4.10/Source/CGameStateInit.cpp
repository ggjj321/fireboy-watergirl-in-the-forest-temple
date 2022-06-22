#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameStateInit.h"
#include "gamemap.h"
namespace game_framework {
	CGameStateInit::CGameStateInit(CGame* g)
		: CGameState(g)
	{
		isEnterrSelectMenu = false;
		showAbout = false;		
	}

	void CGameStateInit::OnInit()
	{
		CAudio::Instance()->Load(0, "sounds\\start.mp3");
		CAudio::Instance()->Load(1, "sounds\\about.mp3");
		showAbout = false;
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(0);	// 一開始的loading進度為0%
		//
		// 開始載入資料
		//
		logo.LoadBitmap(IDB_GAMESTARTVIEW);
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		levelMenu.LoadBitmap();

		pointers.LoadBitmap();

		aboutPic.LoadBitmap(IDB_ABOUT);

		CAudio::Instance()->Play(0, true);
	}

	void CGameStateInit::OnBeginState()
	{
		levelMenu.init(0, 0);
		pointers.init(120, 250, 210, 320, 300, 300, 410, 280, 330, 410);
		showAbout = false;
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';

		const char NEXT_LEVEL = 0x27;
		const char LAST_LEVEL = 0x25;
		const char LEVEL_SELECT = 0xd;

		const char ABOUT_BACK = 0x42;

		if (nChar == KEY_SPACE)
			isEnterrSelectMenu = true;					// 切換至GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲

		if (nChar == NEXT_LEVEL)
			pointers.NextLevel();
		if (nChar == LAST_LEVEL)
			pointers.LastLevel();
		if (nChar == LEVEL_SELECT)
		{
			if (pointers.GetSelectedLevel() == 5) {
				CAudio::Instance()->Play(1, true);
				CAudio::Instance()->Stop(0);
				showAbout = true;
			}
			else
			{
				CGameMap::mapLevel = pointers.GetSelectedLevel();
				CAudio::Instance()->Stop(0);
				GotoGameState(GAME_STATE_RUN);
			}	
		}

		if (nChar == ABOUT_BACK && showAbout) {
			showAbout = false;
			CAudio::Instance()->Stop(1);
			CAudio::Instance()->Play(0, true);
		}
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		isEnterrSelectMenu = true;
	}

	void CGameStateInit::OnShow()
	{
		if (isEnterrSelectMenu) {
			levelMenu.OnShow();
			pointers.OnShow();

			PutText(110, 80, 230, "Please use arrow key to select level");

			PutText(330, 380, 280, "about");
		}
		else
		{
			logo.SetTopLeft(0, 0);
			logo.ShowBitmap();

			//
			// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
			//
			CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, * fp;
			f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkColor(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(255, 255, 0));
			pDC->TextOut(50, 220, "Please click mouse or press SPACE to begin.");
			pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
			if (ENABLE_GAME_PAUSE)
				pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
			pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}	

		if (showAbout)
		{
			aboutPic.SetTopLeft(0, 0);
			aboutPic.ShowBitmap();

			PutText(330, 380, 280, "press B to back");
		}
	}
}