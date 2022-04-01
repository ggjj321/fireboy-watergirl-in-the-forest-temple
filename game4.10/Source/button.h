namespace game_framework {
	class Button {
	public:
		Button();
		void OnShow();
		void LoadBitmap();
		void OnMove(bool isDown);
		void init(int x, int y, int buttonColor);
		int GetX();
		int GetY();
	private:
		int x, y, colorIndex;    // 1:µµ¦â
		int focusX, focusY;      // µJÂI
		bool isDown, isUp;
		CMovingBitmap buttonPic;
	};
}
