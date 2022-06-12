#ifndef PEOPLE
#define PEOPLE
namespace game_framework {
	class People {
	public:
		People();
		void OnMove(bool leftBound, bool rightBound, bool downBound, bool upBound, bool onPlatform, int platformY);
		void OnShow();
		void SetMovingLeft(bool flag);	  // �]�w�O�_���b��������
		void SetMovingRight(bool flag);   // �]�w�O�_���b���k����
		void SetJumpimg(bool flag);	      // �]�w�O�_�����D
		int GetX();
		int GetY();
		int jumpinVelocity;
		int GetWidth();
		int GetHeight();
		bool isSetJumping;
		bool GetIsMovingLeft();
		bool GetIsMovingRight();
	protected:
		int x, y; // �y��
		CMovingBitmap peoplePic;
		CAnimation peopleAniR, peopleAniL;
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumpimg;			    // �O�_���b���W���� 
		int downVelocity;           // �U���t��
	};
}
#endif