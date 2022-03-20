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
	}

	CGameStateRun::~CGameStateRun()
	{
	}

	void CGameStateRun::OnBeginState()
	{
	}

	void CGameStateRun::OnMove()						// ���ʹC������
	{
		const bool leftBound = map.isEmpty(sister.GetX() - 1, sister.GetY());   // �P�_����}�C�O�_��0
		const bool rightBound = map.isEmpty(sister.GetX() + 10, sister.GetY()); // �P�_�k��}�C�O�_��0
		const bool downBound = map.isEmpty(sister.GetX(), sister.GetY() + 17 * 4);  // �P�_�U��}�C�O�_��0
		sister.OnMove(leftBound, rightBound, downBound);
	}

	void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
	{
		ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
		//
		// �}�l���J���
		//
		map.LoadBitMap();
		sister.LoadBitmap();
		sister.AddingBitmap();
		//
		// ��������Loading�ʧ@�A�����i��
		//
		ShowInitProgress(50);
		Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep							

		//
		// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(true);
		if (nChar == KEY_UP) {
			if (sister.isSetJumping == false) {
				sister.SetJumpimg(true);
				sister.jumpinVelocity = 13; // �]�w���D��t
				sister.isSetJumping = true; // �w�g���D�L
			}
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		if (nChar == KEY_LEFT)
			sister.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			sister.SetMovingRight(false);
		if (nChar == KEY_UP) {
			sister.SetJumpimg(false);
			sister.isSetJumping = false;
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnShow()
	{
		map.OnShow(); // ��ܦa��
		if (sister.GetIsMovingRight() == false && sister.GetIsMovingLeft() == false)
		{
			sister.OnShow();
		}
		else if(sister.GetIsMovingRight() == true)
		{
			sister.OnMoveAniRight();
		}
		else if (sister.GetIsMovingLeft() == true) {
			sister.OnMoveAniLeft();
		}
		
	}
}