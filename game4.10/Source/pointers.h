namespace game_framework {
	class Pointers {
	public:
		Pointers();
		void init(int cox1, int coy1, int cox2, int coy2, int cox3, int coy3, int cox4, int coy4, int cox5, int coy5);
		void OnShow();
		void LoadBitmap();
		void NextLevel();
		void LastLevel();
		int GetSelectedLevel();
	private:
		int level;
		int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
		CMovingBitmap pointerOnePic, pointerTwoPic, pointerThreePic, pointerFourPic, pointerFivePic;
	};
}
