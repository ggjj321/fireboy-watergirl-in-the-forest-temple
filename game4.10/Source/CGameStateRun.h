#include "gamemap.h"
#include "sister.h"
#include "brother.h"
#include "button.h"
#include "platform.h"
#include "rocker.h"
#include "timer.h"
#include "red-diamond.h"
#include "blue-diamond.h"
#include "white-diamond.h"
#include "red-door.h"
#include "blue-door.h"
#include "plat.h"
#include "stone.h"
#include "chain-platform.h"


namespace game_framework {
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							
		void OnInit();  								
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  
		void OnLButtonUp(UINT nFlags, CPoint point);	
		void OnMouseMove(UINT nFlags, CPoint point);	
		void OnRButtonDown(UINT nFlags, CPoint point);  
		void OnRButtonUp(UINT nFlags, CPoint point);
		void SetLevelOneState();
		void LevelOneMove();
		void LevelOneShow();
		void SetLevelTwoState();
		void LevelTwoMove();
		void LevelTwoShow();
		void SetLevelThreeState();
		void LevelThreeMove();
		void LevelThreeShow();
		void SetLevelFourState();
		void LevelFourMove();
		void LevelFourShow();
	protected:
		void OnMove();									
		void OnShow();									
	private:
		CGameMap		map;         
		Sister          sister;      
		Brother         brother;
		Button			buttonsFour;
		Button         *buttons;
		Button         *whiteButtons;
		Button		    greenButtonsFour;
		Button         *greenButtons;
		Platform		purplePlatform; 
		Platform        yellowPlatform;
		Plat			greyPlatform;
		Plat			greenPlatform;
		Plat			level4Grey;
		Plat			level4Green;
		Plat			level4Purple;
		Rocker          rocker;
		Timer           timer;
		WhiteDiamond    whiteDiamonds;
		RedDiamond     *redDiamonds;
		BlueDiamond    *blueDiamonds;
		RedDiamond     *redDiamondsTwo;
		BlueDiamond    *blueDiamondsTwo;
		RedDiamond	   *redDiamondsThree;
		BlueDiamond	   *blueDiamondsThree;
		RedDoor		    redDoor;
		BlueDoor	    blueDoor;
		Stone           stone;
		ChainPlatform  *chainPlatforms;		
	};
}
