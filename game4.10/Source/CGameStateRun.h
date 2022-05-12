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
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void SetLevelOneState();
		void LevelOneMove();
		void LevelOneShow();
		void SetLevelTwoState();
		void LevelTwoMove();
		void LevelTwoShow();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
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
