#ifndef PEOPLE
#define PEOPLE
namespace game_framework {
	class People {
	public:
		People();
		void OnMove(bool leftBound, bool rightBound, bool downBound, bool upBound, bool onPlatform, int platformY);
		void OnShow();
		void SetMovingLeft(bool flag);	  // 設定是否正在往左移動
		void SetMovingRight(bool flag);   // 設定是否正在往右移動
		void SetJumpimg(bool flag);	      // 設定是否正跳躍
		int GetX();
		int GetY();
		int jumpinVelocity;
		int GetWidth();
		int GetHeight();
		bool isSetJumping;
		bool GetIsMovingLeft();
		bool GetIsMovingRight();
	protected:
		int x, y; // 座標
		CMovingBitmap peoplePic;
		CAnimation peopleAniR, peopleAniL;
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isJumpimg;			    // 是否正在往上移動 
		int downVelocity;           // 下落速度
	};
}
#endif