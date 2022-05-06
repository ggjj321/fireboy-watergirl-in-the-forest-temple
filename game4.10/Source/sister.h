#include "people.h"
namespace game_framework {
	class Sister : public People {
	public:
		Sister();
		void init(int x, int y);
		void LoadBitmap();  	
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void AddingBitmap();
	};
}