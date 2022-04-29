#ifndef DIAMOND
#define DIAMOND
namespace game_framework {
	class Diamond {
	public:
		Diamond();
		void OnShow();
		void Touch();
		void init(int x, int y);
		int GetX();
		int GetY();
	private:
		int x, y;      
		bool isTouch;
	protected:
		CMovingBitmap diamondPic;
	};
}
#endif
