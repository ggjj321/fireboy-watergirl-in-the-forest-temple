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
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		//
		// �}�l���J���
		//
		logo.LoadBitmap(IDB_GAMESTARTVIEW);
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
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
			isEnterrSelectMenu = true;					// ������GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��

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
			// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
			//
			CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
			CFont f, * fp;
			f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
			fp = pDC->SelectObject(&f);					// ��� font f
			pDC->SetBkColor(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(255, 255, 0));
			pDC->TextOut(50, 220, "Please click mouse or press SPACE to begin.");
			pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
			if (ENABLE_GAME_PAUSE)
				pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
			pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
			pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
			CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
		}	

		if (showAbout)
		{
			aboutPic.SetTopLeft(0, 0);
			aboutPic.ShowBitmap();

			PutText(330, 380, 280, "press B to back");
		}
	}
}