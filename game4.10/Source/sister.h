namespace game_framework {
	class Sister
	{
	public:
		Sister();
		void LoadBitmap();
		void OnMove();
		void OnShow();
	private:
		int x, y; // ®y¼Ð
		CMovingBitmap peoplePic;
	};
}