namespace game_framework {
	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame* g);
		void OnBeginState();							
		void OnInit();
		void OnKeyDown(UINT, UINT, UINT);
	protected:
		void OnMove();									
		void OnShow();									
	private:
		int counter;
		bool retry;
		CMovingBitmap pictureDie;
		CMovingBitmap picturePass;
	};
}
