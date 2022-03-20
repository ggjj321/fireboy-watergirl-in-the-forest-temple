#include "people.h"
namespace game_framework {
	class Sister : public People {
	public:
		Sister();
		void init();
		void LoadBitmap();  	
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void AddingBitmap();
	};

	private:
		int x, y; // 座標
		CMovingBitmap peoplePic;
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isJumpimg;			// 是否正在往上移動
	};
}