#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameStateOver.h"
namespace game_framework {
	CGameStateOver::CGameStateOver(CGame* g)
		: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		if (retry)
			GotoGameState(GAME_STATE_RUN);
	}

	void CGameStateOver::OnBeginState()
	{
		retry = false;
	}

	void CGameStateOver::OnInit()
	{
		ShowInitProgress(66);

		pictureDie.LoadBitmap(IDB_DIEPIC, RGB(255, 255, 255));

		Sleep(300);			

		picturePass.LoadBitmap(IDB_PASSPIC, RGB(255, 255, 255));
		
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		picturePass.SetTopLeft(0, 0);
		picturePass.ShowBitmap();
		if (CGame::passGame) {
			picturePass.SetTopLeft(0, 0);
			picturePass.ShowBitmap();
		}
		else{
			pictureDie.SetTopLeft(0, 0);
			pictureDie.ShowBitmap();
		}	
	}
	void CGameStateOver::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char RETRY_KEY = 0x52;
		const char NEXTMAP_KEY = 0x4E;
		if (nChar == RETRY_KEY || nChar == NEXTMAP_KEY)
			retry = true;
	}
}