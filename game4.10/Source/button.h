namespace game_framework {
	class Button {
	public:
		Button();
		void OnShow();
		void LoadBitmap();
		void init(int x, int y, int buttonColor);
		int GetX();
		int GetY();
		void SetDown(int downDistance);
	private:
		int x, y, colorIndex;    // 1:µµ¦â
		bool isDown, isUp;
		CMovingBitmap buttonPic;
	};
}
