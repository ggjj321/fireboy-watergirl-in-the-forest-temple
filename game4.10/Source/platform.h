namespace game_framework {
	class Platform {
	public:
		Platform();
		void OnShow();
		void LoadBitmap(int color);
		void OnMove(bool isDown);
		void init(int x, int y);
		int GetX();
		int GetY();
		int GetColor();
		int GetFocusX();
		int GetFocusY();
	private:
		int x, y, colorIndex;    // 1:µµ¦â
		int focusX, focusY;      // µJÂI
		bool isDown, isUp;
		CMovingBitmap buttonPic;
	};
}
