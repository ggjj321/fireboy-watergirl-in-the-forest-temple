#ifndef DOOR
#define DOOR
namespace game_framework {
	class Door {
	public:
		Door();
		void OnShow();
		void Touch();
		void init(int x, int y);
		bool GetTouch();
		int GetX();
		int GetY();
	private:
		int x, y;      
		bool isTouch;
	protected:
		CMovingBitmap doorPic;
	};
}
#endif
