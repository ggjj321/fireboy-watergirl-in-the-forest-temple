#include "people.h"
namespace game_framework {
	class Brother : public People {
	public:
		Brother();
		void init();
		void LoadBitmap();  	
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void AddingBitmap();
	};
}