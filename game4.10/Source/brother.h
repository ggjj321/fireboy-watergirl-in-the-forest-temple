#include "people.h"
namespace game_framework {
	class Brother : public People {
	public:
		Brother();
		void init(int x, int y);
		void LoadBitmap();  	
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void AddingBitmap();
	};
}