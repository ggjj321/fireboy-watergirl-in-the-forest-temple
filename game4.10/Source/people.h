namespace game_framework {
	class People {
	public:
		People();
		void init();
		void LoadBitmap();
		void OnMove(bool leftBound, bool rightBound, bool downBound);
		void OnShow();
		void SetMovingLeft(bool flag);	  // 設定是否正在往左移動
		void SetMovingRight(bool flag);   // 設定是否正在往右移動
		void SetJumpimg(bool flag);	      // 設定是否正跳躍
		int GetX();
		int GetY();
		int jumpinVelocity;
		bool isSetJumping;
	private:
		int x, y; // 座標
		CMovingBitmap peoplePic;
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isJumpimg;			    // 是否正在往上移動  	
	};

}
