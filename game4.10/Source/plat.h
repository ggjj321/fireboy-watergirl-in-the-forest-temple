namespace game_framework {
	class Plat {
	public:
		Plat();
		void OnShow();
		void LoadBitmap(int color);
		void OnMove(bool isDown);
		void GrenOnMove(bool isDown);
		void init(int x, int y);
		int GetX();
		int GetY();
		int GetColor();
		int GetFocusX();
		int GetFocusY();
	private:
		int x, y, colorIndex;    //
		int focusX, focusY;      // µJÂI
		bool isDown, isUp;
		CMovingBitmap buttonPic;
	};
}
