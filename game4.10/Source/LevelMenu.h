namespace game_framework {
	class LevelMenu {
	public:
		LevelMenu();
		void init(int coordinateX, int coordinateY);
		void OnShow();
		void LoadBitmap();
	private:
		int x, y;
		CMovingBitmap MenuPic;
	};
}
