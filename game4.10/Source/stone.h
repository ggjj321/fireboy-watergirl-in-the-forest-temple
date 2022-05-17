namespace game_framework {
	class Stone {
	public:
		Stone();
		void init(int coordinateX, int coordinateY);
		void OnShow();
		void LoadBitmap();
		void OnMove(bool leftBound, bool rightBound, bool downBound, int sisterX, int sisterY, int brotherX, int brotherY);
		bool RightPush(int peopleX, int peopleY);
		//bool LeftPush(int peopleX, int peopleY);
		int GetX();
		int GetY();
	private:
		int x, y;
		int downVelocity;
		int stoneWidth;
		CMovingBitmap stonePic;
	};
}
