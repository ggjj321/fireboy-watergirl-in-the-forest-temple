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
			GotoGameState(GAME_STATE_INIT);
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

		picturePass.LoadBitmap(IDB_CONGRAT, RGB(255, 255, 255));
		
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		picturePass.SetTopLeft(0, 0);
		picturePass.ShowBitmap();
		if (CGame::passGame) {
			picturePass.SetTopLeft(0, 0);
			picturePass.ShowBitmap();

			PutText(145, 355, 340, "Press N to select level");
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
		if (CGame::passGame) {
			if (nChar == NEXTMAP_KEY) GotoGameState(GAME_STATE_INIT);
		}
		else
		{
			if (nChar == NEXTMAP_KEY) GotoGameState(GAME_STATE_INIT);
			if (nChar == RETRY_KEY) GotoGameState(GAME_STATE_RUN);
		}
	}
}