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
		CAudio::Instance()->Stop(2);

		if (CGame::passGame) {
			CAudio::Instance()->Play(3, true);
		}
		else {
			CAudio::Instance()->Play(4, true);
		}
	}

	void CGameStateOver::OnInit()
	{
		CAudio::Instance()->Load(3, "sounds\\win.mp3");
		CAudio::Instance()->Load(4, "sounds\\loss.mp3");

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

			PutText(200, 290, 200, "Press N to select level");
		}
		else{	
			pictureDie.SetTopLeft(0, 0);
			pictureDie.ShowBitmap();
			PutText(200, 270, 200, "Press N to select level");
			PutText(240, 390, 200, "Press R to Retry");
		}			
	}
	void CGameStateOver::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char RETRY_KEY = 0x52;
		const char NEXTMAP_KEY = 0x4E;
		if (CGame::passGame) {
			if (nChar == NEXTMAP_KEY) {
				if (CGame::passGame) {
					CAudio::Instance()->Stop(3);
				}
				else {
					CAudio::Instance()->Stop(4);
				}
				CAudio::Instance()->Play(0, true);
				GotoGameState(GAME_STATE_INIT);
			}
		}
		else
		{
			if (nChar == NEXTMAP_KEY) {
				if (CGame::passGame) {
					CAudio::Instance()->Stop(3);
				}
				else {
					CAudio::Instance()->Stop(4);				
				}	
				CAudio::Instance()->Play(0, true);
				GotoGameState(GAME_STATE_INIT);
			}
			if (nChar == RETRY_KEY) {
				if (CGame::passGame) {
					CAudio::Instance()->Stop(3);
				}
				else {
					CAudio::Instance()->Stop(4);
				}
				GotoGameState(GAME_STATE_RUN);
			}
		}
	}
}