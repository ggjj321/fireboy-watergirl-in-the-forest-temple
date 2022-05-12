namespace game_framework {
	class Button {
	public:
		Button();
		void OnShow();
		void LoadBitmap(int color);
		void OnMove(bool isDown);
		void init(int x, int y);
		int GetX();
		int GetY();
		int GetColor();
	private:
		int x, y, colorIndex;    // 1:����
		int focusX, focusY;      // �J�I
		bool isDown, isUp;
		CMovingBitmap buttonPic;
	};
}
