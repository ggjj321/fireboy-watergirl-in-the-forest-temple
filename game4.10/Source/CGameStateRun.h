#include "gamemap.h"
#include "sister.h"
#include "brother.h"
#include "button.h"
#include "platform.h"
#include "rocker.h"
#include "timer.h"
#include "red-diamond.h"
#include "blue-diamond.h"
#include "red-door.h"
#include "blue-door.h"

namespace game_framework {
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void SetLevelOneState();
		void LevelOneMove();
		void LevelOneShow();
		void SetLevelTwoState();
		void LevelTwoMove();
		void LevelTwoShow();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CGameMap		map;         
		Sister          sister;      
		Brother         brother;     
		Button         *buttons;
		Button         *whiteButtons;
		Button         *greenButtons;
		Platform		purplePlatform; 
		Platform        yellowPlatform;
		Rocker          rocker;
		Timer           timer;
		RedDiamond     *redDiamonds;
		BlueDiamond    *blueDiamonds;
		RedDiamond     *redDiamondsTwo;
		BlueDiamond    *blueDiamondsTwo;
		RedDoor		    redDoor;
		BlueDoor	    blueDoor;
	};
}
