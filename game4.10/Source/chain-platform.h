namespace game_framework {
	class ChainPlatform {
	public:
		ChainPlatform();
		void OnShow();
		void LoadBitmap();
		void init(int x, int y);
	private:
		int x, y;    
		CMovingBitmap chainPic;
	};
}
