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
	}

	void CGameStateInit::OnInit()
	{
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
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
		levelMenu.init(0, 0);
		pointers.init(70, 250, 150, 300, 240, 260, 350, 260, 460, 260);
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';

		const char NEXT_LEVEL = 0x27;
		const char LAST_LEVEL = 0x25;
		const char LEVEL_SELECT = 0xd;

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
			CGameMap::mapLevel = pointers.GetSelectedLevel();
			GotoGameState(GAME_STATE_RUN);
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

			CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
			CFont f, * fp;
			f.CreatePointFont(230, "Times New Roman");	// ���� font f; 160���16 point���r
			fp = pDC->SelectObject(&f);					// ��� font f
			pDC->SetBkColor(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(255, 255, 0));
			char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
			sprintf(str, "Please use arrow key to select level");
			pDC->TextOut(110, 350, str);
			pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
			CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
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
	}
}