namespace game_framework {
	class PurpleButton {
	public:
		PurpleButton();
		void init();
		void LoadBitmap();  	
		void OnShow();
	private:
		int x, y;
		CMovingBitmap buttonPic;
	};
}