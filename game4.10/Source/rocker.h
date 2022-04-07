namespace game_framework {
	class Rocker {
	public:
		Rocker();
		void OnShow();
		void LoadBitmap();
		void Touch();
		void init(int x, int y);
		int GetX();
		int GetY();
		bool GetIsTouch();
	private:
		int x, y;    // 1:����
		int focusX, focusY;      // �J�I
		int touchStatus;
		bool isTouch;
		CMovingBitmap rockerRight;
		CMovingBitmap rockerLeft;
	};
}
